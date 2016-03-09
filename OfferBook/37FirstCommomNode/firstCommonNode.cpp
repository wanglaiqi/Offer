#include<iostream>
using namespace std;

//��������Ľṹ����
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

//�������������һ�������ڵ�ķ�������
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

	//�õ���һ����ͬ�Ĺ����ڵ�
	ListNode *pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}

int main()
{
	//ʹ��ͷ�巨��������
	LinkList head1, head2, firstCommonNode;
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
	//���ò��ҹ����ڵ�ķ���
	firstCommonNode = findFirstCommonNode(head1, head2);
	//��ӡ�������ڵ��ֵ
	cout << "��һ�������ڵ��ֵ�ǣ�" << endl;
	cout << firstCommonNode->m_value << endl;
	system("pause");
}