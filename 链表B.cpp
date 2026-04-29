#include <iostream>
using namespace std;

class node
{
public:
	int value;
	node* next;
};

node* head;
//在"链表A"中，我创建头结点时，直接创建了一个真的结点(node no1)，但是不用，这个结点只需要起到一个“空”的作用就好了

node* insert_(int n)//这是正序插入，尾插！
{
	node* temp = NULL;
	node* first = NULL;
	for (int i = 0; i < n; i++)
	{
		temp = new(node);
		if (i == 0)
		{
			first = temp;
		}
		cin >> temp->value;
		temp->next = NULL;
		if (i > 0)
		{
			head->next = temp;
		}
		head = temp;
	}
	return first;
}

void myprintf()
{
	node* head_ = head;
	//记住，指向一个指针，也就是存储一个“指针的地址”，只能用高一级的指针，如果向上面写的那样，
	//head_ 存储的不是 &head，而是 &(*head),里面存储的地址
	//这点前面没有讲到，所以要记住
	while (head_ != NULL)
	{
		cout << head_->value << " ";
		head_ = head->next;
		head = head->next;
	}
}

void delete_()
{
	node* temp = head->next;
	while (head != NULL)
	{
		delete(head);
		head = temp;
		if (temp != NULL)
		{
			temp = temp->next;
		}
	}
}

int main()
{
	//1.这样就相当于创建了一个“头空结点”
	head = NULL;
	int n=0;
	cin >> n;
	head = insert_(n);

	//2.打印输出
	node* head_ = head;
	myprintf();
	head = head_;

	//3.清理对象
	delete_();
	cout << (head == NULL) << endl;

	return 0;
}