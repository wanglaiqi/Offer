#include<iostream>
#include<stack>
using namespace std;

/*
*�����ӡ�����е�Ԫ��
*/

//����һ�����Ա�ĵ�����洢�ṹ
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList L)
{
	int n = 0;
	LinkList p;
	cout << "�������½������Ԫ�ظ�����" << endl;
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
		//��ջ�в���Ԫ��
		nodes.push(p);
		p = p->m_next;
	}
	while (!nodes.empty())
	{
		//���ջ��Ԫ��
		p = nodes.top();
		cout << p->m_value << " ";
		//ɾ��ջ��Ԫ��
		nodes.pop();
	}
}

void Tips()
{
	cout << "�������ּ�ѡ����Ӧ�Ĳ�����" << endl;
	cout << "(1)" << "����ͷ�巨����һ����ͷ���ĵ�����" << endl;
	cout << "(2)" << "����������е�Ԫ��ֵ" << endl;
	cout << "(3)" << "ʹ�õݹ�ķ���������������е�Ԫ��" << endl;
	cout << "(4)" << "ʹ��ջ�ṹ������������е�Ԫ��" << endl;
	cout << "(5)" << "ʹ����ֹͣ����" << endl;
}

int main()
{
	int op;
	LinkList head = NULL;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_value = -1;
	head->m_next = NULL;
	Tips();
	cout << "������Ҫ���в�������ţ�" << endl;
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
		cout << "������Ҫ���в�������ţ�" << endl;
		cin >> op;
	}
	system("pause");
}