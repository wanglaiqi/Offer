#include<iostream>
using namespace std;

typedef struct ListNode
{
	int m_value;
	struct  ListNode *m_next;
}ListNode,*LinkList;

//������ͷ��������
void createList(LinkList L)
{
	LinkList p;
	int n;
	cout << "��������Ҫ�����������Ԫ�ظ���" << endl;
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

//��ӡ�����е�Ԫ��
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

//��ʱ�临�Ӷ�ΪO(1)ɾ��ָ���Ľڵ�
void delete_Node(LinkList L,LinkList deleteNode)
{
	if (L==NULL||deleteNode==NULL)
	{
		return;
	}

	//ɾ���Ľڵ㲻��β�ڵ�
	if (deleteNode->m_next != NULL)
	{
		LinkList deleteNext;
		deleteNext = deleteNode->m_next;
		deleteNode->m_value = deleteNext->m_value;
		deleteNode->m_next = deleteNext->m_next;

		delete deleteNext;
		deleteNext = NULL;
	}
	//������ֻ��һ���ڵ㣬ͷ���Ҳ��β�ڵ�
	else if (L == deleteNode)
	{
		delete deleteNode;
		deleteNode = NULL;
		L = NULL;
	}
	//ɾ���Ľڵ���β�ڵ�
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
	cout << "���ɾ���Ժ�������е�Ԫ��" << endl;
	printList(head);
	system("pause");
}