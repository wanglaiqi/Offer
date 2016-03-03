#include<iostream>
using namespace std;

typedef struct ListNode
{
	int m_value;
	struct  ListNode *m_next;
}ListNode,*LinkList;

//创建带头结点的链表
void createList(LinkList L)
{
	LinkList p;
	int n;
	cout << "请你输入要建立的链表的元素个数" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(ListNode));
		cin >> p->m_value;
		p->m_next = L->m_next;
		L->m_next = p;
	}
	cout << endl;
}

//打印链表中的元素
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

//以时间复杂度为O(1)删除指定的节点
void delete_Node(LinkList L,LinkList deleteNode)
{
	if (L==NULL||deleteNode==NULL)
	{
		return;
	}

	//删除的节点不是尾节点
	if (deleteNode->m_next != NULL)
	{
		LinkList deleteNext;
		deleteNext = deleteNode->m_next;
		deleteNode->m_value = deleteNext->m_value;
		deleteNode->m_next = deleteNext->m_next;

		delete deleteNext;
		deleteNext = NULL;
	}
	//链表中只有一个节点，头结点也是尾节点
	else if (L == deleteNode)
	{
		delete deleteNode;
		deleteNode = NULL;
		L = NULL;
	}
	//删除的节点是尾节点
	else
	{
		LinkList pNode = L;
		while (pNode->m_next!=deleteNode)
		{
			pNode = pNode->m_next;
		}
		pNode->m_next = NULL;
		delete deleteNode;
		deleteNode = NULL;
	}
}

int main()
{
	LinkList head;
	LinkList deleteOfNode;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_next = NULL;
	head->m_value = -1;
	createList(head);
	printList(head);
	deleteOfNode = head->m_next;
	delete_Node(head, deleteOfNode);
	cout << "输出删除以后的链表中的元素" << endl;
	printList(head);
	system("pause");
}