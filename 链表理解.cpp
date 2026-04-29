#include <iostream>
using namespace std;

class list
{
public:
	list* L=NULL;
};

class node
{
public:
	int value;
	node* p;
};

void list_create()
{
	node* A;   //这个用来给“上一个结点”进行操作
	node* temp;//这个用来给“正在创建的节点”进行操作
	//空头结点
	node n;
	n.p = NULL;
	//
	A = &n;
	//循环中的大概内容
	temp = new(node);
	temp->value = 1;
	temp->p = NULL;

	A->p = temp;
	A = temp;


	temp = new(node);
	temp->value = 2;
	temp->p = NULL;

	A->p = temp;
	A = temp;

	temp = new(node);
	temp->value = 3;
	temp->p = NULL;

	A->p = temp;
	A = temp;

	temp = new(node);
	temp->value = 4;
	temp->p = NULL;

	A->p = temp;
	A = temp;
	//为了使用，指向第一个头结点（空结点）
	int i = 0;
	A = &n;
	for (temp = &n; A->p != NULL; temp = temp->p)
	{
		if (i == 0)
		{
			i = 1;
			A = temp;
			continue;
		}

		cout << temp->value << " ";
		A = temp;
	}
}

int main()
{
	list_create();
	


	return 0;
}