#include <iostream>
using namespace std;

int* f() {
	int a = 10;
	return &a;
}
int* ff() {
	int* b= new int(10);
	return b;
}
int* fff() {
	int* arr = new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	return arr;
}

int main()
{
	int* a = f();
	cout << "a=" << *a << endl;
	cout << "a=" << *a << endl<<endl;
	//1. 在“栈区”也就是除主函数之外的函数 f() 中所定义的任何变量的赋值操作，都会在函数 f() 运行结束后“释放内存”
	// . 也就是，取消 a 所占用的空间
	// . 这时候再次在主函数中通过（）地址 &a 来打印a 的值 ，不会得到 a=10 的结果，但是在有些编译器里面，会自动保留 a=10
	//  . 的缓存，也就是 退出 f() 函数后，会在第一遍调用 a 时，依旧是 a=10 的值，但是在第二遍之后，就会被释放内存

	//2. 但是，有时候要用这个属性，该怎么办？
	int* b = ff();
	cout << "b=" << *b << endl;
	cout << "b=" << *b << endl << endl;
	// . 使用 new 运算符直接在“堆区”里面开辟一个 int 类型的 空间 储存 10 ,然后“返回值”为 10 所在的“地址”==int*
	// . 这时候，打印结果直接全部为 b=10; 因为---- 此时 10 的地址在“堆区”，也就相当于在 main()函数内定义的变量
	// . new int(10); 返回值类型为 “地址”，------ 这是 用 new 创建一个 “变量”

	//3. 如果要创建一个 数组 呢？
	int* arr = fff();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	// . new int[10]; ---- 这是创建数组的方式，而且，只能这样写，不能 new int[10]={1,2,····} 这样写，会报错

	//4. 那么，如何“释放内存”呢？
	// . 在c++中一般用 delete a; // delete[] arr; 来释放变量和数组分配的空间 
	delete[] arr;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	// .此时，再一次遍历数组，就会报错，因为 arr[] 已经被删除了
	system("pause");
	return 0;
}