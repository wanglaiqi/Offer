����һ��������ת�����������������Ԫ�ء�

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode *pNew = pHead;
		while(pHead==NULL||pHead->next==NULL)
		{
			retutn pHead;
		}
		
		pNew = ReverseList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = NULL;//��ֹ����
		return pNew;	
	}
}