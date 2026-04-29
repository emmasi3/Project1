#include <iostream>
using namespace std;
#include <string>

int main()
{
	int a = 10;
	cout << "a=" << a << endl;
	cout << "请输入a的新值：" << endl;
	cin >> a;
	cout << "a=" << a << endl;
	//1、cin>> 相当于scanf()
	char p[] = "hello";
	cin >> p;
	cout << "p=" << p << endl;
	//2、一般来说，C语言中，数组p【】不能被修改容量，但是在c++中，如果你以char p[]方式定义字符串，那么遇到这种情况（
	// 改变了p的容量），他会执行，而且不会报错，但是会显示调试错误，虽然说程序正常执行，会得到想要的
	//3、但是，当以 string p="hello";时，你直接用cin>>p，输入长处p容量的东西，他不会报错，比p[]更加宽松，但是这样
	// 、就不具有了安全性

	system("pause");
	return 0;
}