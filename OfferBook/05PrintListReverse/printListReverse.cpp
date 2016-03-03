#include<iostream>
#include<stack>
using namespace std;

/*
*逆序打印链表中的元素
*/

//定义一个线性表的单链表存储结构
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList L)
{
	int n = 0;
	LinkList p;
	cout << "请输入新建链表的元素个数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(ListNode));
		cin >> p->m_value;
		p->m_next = L->m_next;
		L->m_next = p;
	}
}

void printList(LinkList L)
{
	LinkList p;
	p = L->m_next;
	while (p)
	{
		cout << p->m_value << " ";
		p = p->m_next;
	}
	cout << endl;
}

void reverseList1(LinkList L)
{
	if (L!=NULL)
	{
		if (L->m_next!=NULL)
		{
			reverseList1(L->m_next);
		}
		cout << L->m_value << " ";
	}
	cout << endl;
}

void reverseList2(LinkList L)
{
	stack<LinkList> nodes;
	LinkList p;
	p = L;
	while (p!=NULL)
	{
		//向栈中插入元素
		nodes.push(p);
		p = p->m_next;
	}
	while (!nodes.empty())
	{
		//获得栈顶元素
		p = nodes.top();
		cout << p->m_value << " ";
		//删除栈顶元素
		nodes.pop();
	}
}

void Tips()
{
	cout << "按照数字键选择相应的操作：" << endl;
	cout << "(1)" << "利用头插法创建一个带头结点的单链表" << endl;
	cout << "(2)" << "输出单链表中的元素值" << endl;
	cout << "(3)" << "使用递归的方法逆序输出链表中的元素" << endl;
	cout << "(4)" << "使用栈结构逆序输出链表中的元素" << endl;
	cout << "(5)" << "使程序停止运行" << endl;
}

int main()
{
	int op;
	LinkList head = NULL;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_value = -1;
	head->m_next = NULL;
	Tips();
	cout << "请输入要进行操作的序号：" << endl;
	cin >> op;
	while (op)
	{
		switch (op)
		{
		case 1:
			createList(head); break;
		case 2:
			printList(head); break;
		case 3:
			reverseList1(head); break;
		case 4:
			reverseList2(head); break;
		case 5:
			exit(0);
		default:
			break;
		}
		Tips();
		cout << "请输入要进行操作的序号：" << endl;
		cin >> op;
	}
	system("pause");
}