#include<iostream>
using namespace std; 

/*
*�ϲ��������������ϲ����Ա�������������
*/

//��������Ľṹ
typedef struct ListNode
{
	int m_value;
	struct ListNode *m_next;
}ListNode,*LinkList;

void createList(LinkList head)
{
	int n;
	cout << "��������Ҫ����������Ľڵ����" << endl;
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

//�Ͳ�����1������2���������½��������ͷ���
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
	//ʹ��ͷ�巨��������
	LinkList head1,head2,mergeHead;
	head1 = (LinkList)malloc(sizeof(ListNode));
	head1->m_value = -1;
	head1->m_next = NULL;
	head2 = (LinkList)malloc(sizeof(ListNode));
	head2->m_value = -2;
	head2->m_next = NULL;
	//��������1��2
	cout << "��������1" << endl;
	createList(head1);
	cout << "��������2" << endl;
	createList(head2);
	//��ӡ�����������е�Ԫ��
	printList(head1);
	printList(head2);
	//���úϲ�����
	mergeHead = mergeList(head1->m_next, head2->m_next);
	//��ӡ�ϲ���������е�Ԫ��
	printMergeList(mergeHead);
	system("pause");
}