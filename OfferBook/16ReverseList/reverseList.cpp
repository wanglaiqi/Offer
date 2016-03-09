#include<iostream>
using namespace std;

/*
*反转链表的操作
*/
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList L)
{
	int n;
	cout << "输入建立链表的节点的个数"<<endl;
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

//反转链表中的元素
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
	//用头插法建立链表
	LinkList head;
	LinkList newHead;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_value = -1;
	head->m_next = NULL;
	createList(head);
	printList(head);
	newHead = reverseList(head);
	cout << "打印出反转后的链表中的元素" << endl;
	printReverseList(newHead);
	system("pause");
}