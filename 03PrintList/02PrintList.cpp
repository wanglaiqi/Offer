//从原链表的头部一个一个取节点并插入到新链表的头部
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