#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Person
{
public:
	Person()
	{
		//std::cout << "默认构造" << std::endl;
	}

	Person(const int age)
		:m_age(age)
	{
		std::cout << "创建Person" << std::endl;
	}

	~Person()
	{
		std::cout << "~n()析构" << std::endl;
	}

	int m_age = 1;
};

static void test1()
{
	std::shared_ptr<int[]> arr = std::make_shared<int[]>(16);

	for (int i = 0; i < 16; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;


	std::shared_ptr<Person[]> arr_p(new Person[8],
		[](Person* p) { std::cout << "删除\n";  delete[] p; });

	/*arr_p[0] = Person(4);*/

	for (int i = 0; i < 8; ++i)
	{
		std::cout << arr_p[i].m_age << " ";
	}
}

/*
* order: 验证 std::shared_ptr<Person[]> buffer = std::make_shared<Person[]>(8);
* 是否等价于：std::shared_ptr<Person[]> buffer(new Person[8]); 也就是 C++17 以后，是否能够
* 在不使用 std::make_shared<Person[]>(8)情况下，自动调用 delete[] p; 来析构所有的 Person[] 对象？
*/
static void test2()
{
	//std::shared_ptr<Person[]> buffer = std::make_shared<Person[]>(8);
	std::shared_ptr<Person[]> buffer(new Person[8]);

	// 已经验证：在 C++17 之后，以上两种写法会自动调用 delete[] p; 来释放智能指针托管的内存
	// 所以类似 std::shared_ptr<char[]> buffer(new char[buff_size]); 不用提供删除器，默认执行
	// delete[] p;
}

int main()
{
	// test1();
	test2();

	std::cout << "test2() 已退出，可以调试并查看，输出台Person是否正常输出析构内容？" << std::endl;

	return 0;
}

/*
* 1、这里的 Person 作为实验对象，使用 36 行的代码进行 -- 类数组的代理，放在堆区
*	定义删除器，默认打印 “删除”。
*	并且，Person 的默认构造函数，默认打印“默认构造”，有参构造函数，打印 “创建Person”
* 
* 2、在 new Person[8]时，也就是初始化这样一个“类数组”时，类或者结构体必须要有默认的构造函数，
*	也就是创建这个堆上的数组时，就要分配每一个 Person 的内存,也就是他们 8 个Person对象，此时已经
*	分配在了“堆区”，后续的 arr_p[0] = Person(4); 不会让 arr_p[0] 对象重新构造，而是类似于 拷贝赋值
* 
* 3、从创建 arr_p 开始，到退出作用域所做的事，
* （1）创建 arr_p 实例，并在 “堆区” 上分配 8 个Person类内存块，此时执行8次默认构造函数
*	并将 删除器 lambda，给到 arr_p，释放该智能指针时要用
* 
* （2）arr_p[0] = Person(4); 栈上创建一个 Person 类临时对象，并将其成员属性通过拷贝或者其他的方式
*	给到 arr_p[0] 的 “堆” 对象上，一定要注意，此时并没有重新构造，仅仅是拷贝(或者其他手段)而已
* 
* （3）退出作用域，智能指针执行析构函数，调用定义的 deleter，此时，你或许会疑问：
*	应该执行 8 次 delete，比较堆上，我们放了8个Person？
*	但是实际情况是：删除器此时，要写： delete[] p; 也就是直接释放一整个类数组
*	所以删除器，仅仅只会被执行一次，也就是 “删除” 这个字眼，仅仅会被打印一次
*	但是 delete[] p; 时，会调用每一个对象的 析构函数，嗯嗯，这样也算智能指针了吧
* 
* 4、注意 ,arr_p[0] 表示的就是第一个位置的 Person 对象，arr_p用法 == Person arr_p[];
*	看得明白吧？正常使用即可，还有 delete[] p;
* 
*/
