#include <iostream>
#include <vector>

using namespace std;

typedef struct st
{
	int num;
	struct st *next;
}ListNode;

ListNode *create(int n)
{
	ListNode *head,*node,*end;
	head=(ListNode*)malloc(sizeof(ListNode));
	end=head;
	for(int i=0;i<n;i++)
	{
		node=(ListNode*)malloc(sizeof(ListNode));
		scanf("%d",&node->num);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head;
}
void display(ListNode *h,ListNode *head)
{
	while(h->next!=NULL)
	{
		h=h->next;
		printf("%d",h->num);
	}
	h=head;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *cur,*prc;
		cur=head;prc=head;
		if (!head->next) return NULL;
		for(int i=0;i<n;i++) cur=cur->next;
		if (!cur) return head->next;
		while(cur->next)
		{
			cur=cur->next;
			prc=prc->next;
		}
		prc->next=prc->next->next;
		return prc;
    }
};

int main()
{
	Solution yiku;
	ListNode *L1,*L2,*L3;
	L1=create(5);
	L3=L1;
	L2=yiku.removeNthFromEnd(L1,6);
	display(L1,L3);
	cout<<endl;
	display(L1,L3);
	return 0;
}
	
