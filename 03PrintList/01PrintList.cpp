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

//������
//����ָ����������ͬʱ��
class Solution {
public��
	 ListNode* ReverseList(ListNode* pHead) {
		 if(pHead==NULL)
		 {
			 return pHead;
		 }
		 if(pHead->next == NULL)
		 {
			 return pHead;
		 }
		 ListNode *pBefore = pHead,*p = pHead->next,pAfter = p->next;
		 while(pAfter)
		 {
			 p->next = pBefore;
			 pBefore = p;
			 p = pAfter;
			 pAfter = p->pAfter;
		 }
		 p->next = pBefore;
		 pHead->next = NULL;
		 return p;
	 }
}