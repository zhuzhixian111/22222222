/*给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3*/

#include <iostream>
#include <vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
 if (!head || !head->next) return head;
        
        ListNode *start = head;
        while (start && start->next) {
            if (start->val == start->next->val) {
                ListNode *tmp = start->next;
                start->next = start->next->next;
                delete tmp;
            } else start = start->next;
        }
        return head;	
    }
	void delet(ListNode *li,int n)
	{
		ListNode *t=li,*in;
		int i=0;
		while(t!=NULL && i<n)
		{
			in=t;
			t=t->next;
			i++;
		}
		if(t->next!=NULL)
		{
			in->next=t->next;
			free(t);
		}
	}

};
ListNode *create(int n)
{
	ListNode *head,*node,*end;
	head=(ListNode*)malloc(sizeof(ListNode));
	end=head;
	for(int i=0;i<n;i++)
	{
		node=(ListNode*)malloc(sizeof(ListNode));
		scanf("%d",&node->val);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head;
}
void display(ListNode *head,ListNode *head1)
{
	while(head->next !=NULL)
	{
		head=head->next;
		printf("%d",head->val);
	}
	head=head1;
}
int main()
{
	 ListNode *yiku;
	 ListNode *yiku3;
	yiku3=yiku;
	 ListNode *qqq;
	yiku=create(5);
	display(yiku,yiku3);
	cout<<endl;
	Solution cmd;
	qqq=cmd.deleteDuplicates(yiku);
	display(qqq,yiku3);
	return 0;
}



