//��ԭ�����ͷ��һ��һ��ȡ�ڵ㲢���뵽�������ͷ��
Class Solution {
Public:
	ListNode *ReverseList(ListNode *pHead) {
		if(pHead == NULL)
		{
			return NULL;
		}
		ListNode *head = pHead;
		pHead = pHead->next;
		head->next = NULL;
		while(pHead)
		{
			ListNode *new = pHead->next;
			pHead->next = head;
			head = pHead;
			pHead = new;
		}
		return head;
	}
};