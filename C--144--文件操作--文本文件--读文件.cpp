#include <iostream>
using namespace std;
#include <fstream>
#include <string>

int main()
{
	ifstream ifs;

	ifs.open("test.txt", ios::in);

	//1.判断有没有打开  test.txt 文件
	int t = ifs.is_open();//这个函数的返回值为 bool 类型

	if (t == 0)
	{
		cout << "test.txt打开失败" << endl;
		return 0;
	}
	else
	{
		cout << "test.txt已打开" << endl;
		cout << "------------------" << endl;
	}
	//2.读数据
	//(1)
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	// 
	// 
	//(2)
	//char buff[1024] = { 0 };
	//while (ifs.getline(buff, sizeof(buff)))
	//{
	//	cout<<buff<<endl;
	//}

	//(3）
	string buf;
	buf = "hello0";
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//(4)
	char c;
	while ((c = ifs.get()) != EOF)// EOF == 文件末尾
	{
		cout << c << endl;
	}

	//3. 前三个都是一行一行读取，而且，在读取时，会直接覆盖掉已经读取的内容(buf 原本的内容)
	//4. 第四个时一个一个读取，一般不可取，太慢了，没效率
	//5. 推荐使用第三个，很直接简洁
	ifs.close();

	system("pause");
	return 0;
}