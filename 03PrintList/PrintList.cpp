输入一个链表，反转链表后，输出链表的所有元素。

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
		pHead->next = NULL;//防止链环
		return pNew;	
	}
}