#include<iostream>
using namespace std;

/*
*��ת����Ĳ���
*/
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList L)
{
	int n;
	cout << "���뽨������Ľڵ�ĸ���"<<endl;
	cin >> n;
	LinkList p;
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
	LinkList p = L->m_next;
	while (p)
	{
		cout << p->m_value << " ";
		p = p->m_next;
	}
	cout << endl;
}

void printReverseList(LinkList L)
{
	LinkList p = L;
	while (p)
	{
		if (p->m_value!=-1)
		{
			cout << p->m_value << " ";
		}
		p = p->m_next;
	}
	cout << endl;
}

//��ת�����е�Ԫ��
LinkList reverseList(LinkList head)
{
	LinkList reverseHead = NULL;
	LinkList pNow = head;
	LinkList pPrevious = NULL;
	while (pNow != NULL)
	{
		LinkList pNext = pNow->m_next;
		if (pNext == NULL)
		{
			reverseHead = pNow;
		}

		pNow->m_next = pPrevious;
		pPrevious = pNow;
		pNow = pNext;
	}
	return reverseHead;
}

int main()
{
	//��ͷ�巨��������
	LinkList head;
	LinkList newHead;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_value = -1;
	head->m_next = NULL;
	createList(head);
	printList(head);
	newHead = reverseList(head);
	cout << "��ӡ����ת��������е�Ԫ��" << endl;
	printReverseList(newHead);
	system("pause");
}