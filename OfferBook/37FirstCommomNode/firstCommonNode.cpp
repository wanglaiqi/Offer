#include<iostream>
using namespace std;

//定义链表的结构如下
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

unsigned int GetListLength(ListNode *pHead)
{
	unsigned int nLength = 0;
	ListNode *pNode = pHead->m_next;
	while (pNode != NULL)
	{
		nLength++;
		pNode = pNode->m_next;
	}
	return nLength;
}

//查找两个链表第一个公共节点的方法如下
ListNode * findFirstCommonNode(LinkList head1,LinkList head2)
{
	unsigned int nLength1 = GetListLength(head1);
	unsigned int nLength2 = GetListLength(head2);

	int nLengthDif = nLength1 - nLength2;

	ListNode *pListHeadLong = head1;
	ListNode *pListHeadShort = head2;

	if (nLength1<nLength2)
	{
		pListHeadLong = head2;
		pListHeadShort = head1;
		nLengthDif = nLength2 - nLength1;
	}

	for (int i = 0; i < nLengthDif; i++)
	{
		pListHeadLong = pListHeadLong->m_next;
	}

	while ((pListHeadLong!=NULL) && (pListHeadShort!=NULL) && (pListHeadLong->m_value!=pListHeadShort->m_value))
	{
		pListHeadLong = pListHeadLong->m_next;
		pListHeadShort = pListHeadShort->m_next;
	}

	//得到第一个共同的公共节点
	ListNode *pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}

int main()
{
	//使用头插法创建链表
	LinkList head1, head2, firstCommonNode;
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
	//调用查找公共节点的方法
	firstCommonNode = findFirstCommonNode(head1, head2);
	//打印出公共节点的值
	cout << "第一个公共节点的值是：" << endl;
	cout << firstCommonNode->m_value << endl;
	system("pause");
}