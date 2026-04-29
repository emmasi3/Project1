#include <iostream>
using namespace std;
#include <string>
#define max 1000  // 4.这里不能用 ; 号结尾，否则会报错！！！

struct people {
	string name;
	string xb;
	string age;
	string phone;
	string adress;

};
struct addresspeople {
	people arr[max];
	int number = 0;
}content;

void cd();

int main()
{
	cd();
	//制造选择
	int n = 0;
	int N = 0;
	while (1) {// 3. 利用while(1) 所谓的“死”循环来实现 执行完 1 ···其他功能后还能继续选择其他的功能！！！
		cout << "请选择功能" << endl;
		cin >> n;
		switch (n) {
		case 1:// 添加联系人
			if (N == 1000) {
				cout << "联系人1000，空间不足" << endl;
				break;
			}
			cout << "请输入联系人的信息：" << endl;
			cout << "姓名：";
			cin >> content.arr[N].name;
			cout << "性别：";
			cin >> content.arr[N].xb;
			cout << "年龄：";
			cin >> content.arr[N].age;
			cout << "电话：";
			cin >> content.arr[N].phone;
			//
			content.number++;
			cout << "联系人数(总)：" << content.number << endl;
			//
			N++;
			break;
		case 2://显示联系人
			for (int i = 0; i <= N-1; i++) {
				cout << content.arr[i].name << endl;
			}
			break;
		case 3: {//删除联系人（并且排序填满空位）
			string n3;
			cin >> n3;
			int n33 = 0;
			for (int i = 0; i <= N-1; i++) {
				if (n3 == content.arr[i].name) {
					for (i; i <= N-1; i++) {
						content.arr[i] = content.arr[i + 1];//注意，这一块儿考虑到用户一般没有1000个联系人，所以就没有处理
						//最后一个的问题
					}
					n33 = 1;
				}
			}
			if (n33 == 0) {
				cout << "没有该联系人" << endl;
			}

			break;
		}
		case 4: {//查找联系人
			string n4;
			cout << "查找人名：" << endl;
			cin >> n4;
			int n44 = 0;
			for (int i = 0; i <= N-1; i++) {
				if (n4==(content.arr[i].name)) {
					cout << content.arr[i].name << endl;
					cout << content.arr[i].xb<<endl;
					cout << content.arr[i].age<<endl;
					cout << content.arr[i].phone<<endl;
					n44 = 1;
					break;
				}
			}

			if (n44 == 0) {
				cout << "没有该联系人" << endl;
			}

			break;
		}
		case 5://修改联系人
		{
			string n5;
			cout << "请输入要查找的：" << endl;
			cin >> n5;
			int n55 = 0;
			for (int i = 0; i <= N-1; i++) {
				if (n5 == content.arr[i].name) {
					cout << "请输入修改后联系人的信息：" << endl;
					cout << "姓名：";
					cin >> content.arr[i].name;
					cout << "性别：";
					cin >> content.arr[i].xb;
					cout << "年龄：";
					cin >> content.arr[i].age;
					cout << "电话：";
					cin >> content.arr[i].phone;
					n55 = 1;
				}
				if (n55 == 0) {
					cout << "查无此人" << endl;
				}
			}
		}
			break;
		case 6://清空联系人
		{
			N = 0;//这里没有遍历整个通讯录，当然是由更好的方法
			      //直接将人数统计变量 N=0 ，那么查询功能将不会显示任何人，但是，这些数据依然保留在arr[]中
			      //但是，再一次通过添加联系人的操作，会直接“覆盖”被清空的对应部分
			      //不从在浪费空间的问题，reason: arr[1000]数组被创建的时候，已经分配了1000个单位的空间，之后没有对容量
			      // 做改变，所以没有浪费空间
		}
			break;
		case 7:
			system("pause");// 1.这两句语句直接回退出“整个”程序
			return 0;
		default:
			cout << "请输入正确的指令功能键！！！" << endl;
			goto out;// 2.也可以用 goto 语句来跳到main()的关闭处
		}
	}
out:
	system("pause");
	return 0;
}

void cd() {
	cout << "**********************" << endl;
	cout << "*****1、添加联系人****" << endl;
	cout << "*****2、显示联系人****" << endl;
	cout << "*****3、删除联系人****" << endl;
	cout << "*****4、查找联系人****" << endl;
	cout << "*****5、修改联系人****" << endl;
	cout << "*****6、清空联系人****" << endl;
	cout << "*****7、退出通讯录****" << endl;
	cout << "**********************" << endl;
}