#include<iostream>
using namespace std; 

/*
*合并两个有序链表，合并后仍保持新链表有序
*/

//声明链表的结构
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList head)
{
	int n;
	cout << "请你输入要创建的链表的节点个数" << endl;
	cin >> n;
	LinkList p;

	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(ListNode));
		cin >> p->m_value;
		p->m_next = head->m_next;
		head->m_next = p;
	}
	cout << endl;
}

void printList(LinkList head)
{
	LinkList p = head->m_next;
	while (p)
	{
		cout << p->m_value << " ";
		p = p->m_next;
	}
	cout << endl;
}

void printMergeList(LinkList head)
{
	LinkList p = head;
	while (p)
	{
		cout << p->m_value << " ";
		p = p->m_next;
	}
	cout << endl;
}

//和并链表1和链表2，并返回新建的链表的头结点
ListNode * mergeList(LinkList head1,LinkList head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}

	ListNode *pMergeHead = NULL;
	if (head1->m_value < head2->m_value)
	{
		pMergeHead = head1;
		pMergeHead->m_next = mergeList(head1->m_next,head2);
	}
	else
	{
		pMergeHead = head2;
		pMergeHead->m_next = mergeList(head1,head2->m_next);
	}
	return pMergeHead;
}

int main()
{
	//使用头插法创建链表
	LinkList head1,head2,mergeHead;
	head1 = (LinkList)malloc(sizeof(ListNode));
	head1->m_value = -1;
	head1->m_next = NULL;
	head2 = (LinkList)malloc(sizeof(ListNode));
	head2->m_value = -2;
	head2->m_next = NULL;
	//创建链表1和2
	cout << "创建链表1" << endl;
	createList(head1);
	cout << "创建链表2" << endl;
	createList(head2);
	//打印创建的链表中的元素
	printList(head1);
	printList(head2);
	//调用合并函数
	mergeHead = mergeList(head1->m_next, head2->m_next);
	//打印合并后的链表中的元素
	printMergeList(mergeHead);
	system("pause");
}