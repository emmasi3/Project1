#include <iostream>
using namespace std;

template<class T>
class base
{
public:
	base()
	{
		cout << typeid(T).name() << endl;
	}
	T m;
};

//1.  class son :public base 这是报错的，原因：父类 base 为类模板，其中的 m 被son 继承，但是，继承的时候会给 son 分配空间
// . 这取决于其中的成员变量有多少···但是这时候 m 类类型 T 是不明确的，所以无法给son 分配内存，所以会报错

class son1 :public base<int>//只需要加上模板参数表指定 T 的内容就好！！！
{

};
//
template<class T>
class son2 :public base<T>  //2.如果在定义类的时候我不想指定出 T 的类型，而是想在主函数中用到的时候定义一下，该如何？
{
public:
	son2()                 //.继续写就行了，再定义一个 T 之后在给它类型就行了
	{
		cout << typeid(T).name() << endl;
		cout << "成功调用" << endl;
	}
	T M;
};

int main()
{
	son2<int>p;//3.这样就行了

	system("pause");
	return 0;
}