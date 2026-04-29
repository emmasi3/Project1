#include <iostream>
using namespace std;

class node
{
public:
	int value;
	node* next;
};

node* head = NULL;//用于指向上一个结点，用全局变量，方便后面的调用

void add_list(int n,node& no1)
{
	head = &no1;
	node* temp = NULL;//用来控制正在创建的结点
	for (int i = 0; i < n; i++)
	{
		temp = new(node);
		cin >> temp->value;
		temp->next = NULL;
		head->next = temp;
		head = temp;
	}
}

void myprintf(node& no1)
{
	int i = 0;
	node* head = &no1;
	while (head->next != NULL)
	{
		if (i == 0)
		{
			i=1;
			head = head->next;
			continue;
		}
		cout << head->value << " ";
		head = head->next;
	}
	if (head->next == NULL && i == 1)
	{
		cout << head->value << endl;
	}
}

int main()
{
	//1.空结点
	node no1{};
	no1.next = NULL;
	int n;
	cout << "你想插入个数：" << endl;
	cin >> n;
	//2.插入链表
	add_list(n,no1);
	//3.遍历打印链表
	myprintf(no1);

	return 0;
}