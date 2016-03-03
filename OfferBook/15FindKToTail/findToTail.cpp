#include<iostream>
using namespace std;

typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode, *LinkList;

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

LinkList findKToTail(LinkList L, unsigned int k)
{
	if (L==NULL || k==0)
	{
		return NULL;
	}
	LinkList pAhead = L;
	LinkList pBehind = NULL;

	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pAhead->m_next!=NULL)
		{
			pAhead = pAhead->m_next;
		}
		else
		{
			return NULL;
		}
	}

	pBehind = L;
	while (pAhead->m_next!=NULL)
	{
		pAhead = pAhead->m_next;
		pBehind = pBehind->m_next;
	}
	return pBehind;
}

int main()
{
	int k;
	cout << "��������k��ֵ" << endl;
	cin >> k;
	LinkList head;
	LinkList findNode;
	LinkList deleteOfNode;
	head = (LinkList)malloc(sizeof(ListNode));
	head->m_next = NULL;
	head->m_value = -1;
	createList(head);
	printList(head);
	//�ҵ�������k���ڵ�
	findNode = findKToTail(head, k);
	cout << "������ҵ��Ľڵ��ֵ����" << endl;
	cout << findNode->m_value << endl;
	system("pause");
}