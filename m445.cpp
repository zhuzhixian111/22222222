/*给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

 

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7*/

#include <iostream>
#include <vector>

using namespace std;


typedef struct ListNode {
      int val;
	  struct ListNode *m_pNext;
      struct ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  }LinkList;
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    }
};

LinkList* create(int n)
{
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	for(int i=0;i<n;i++)
	{
		node=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&node->val);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head;
}
void show(LinkList *l1)
{	
	while(l1->next!=NULL)
	{
		l1=l1->next;
		printf("%d",l1->val);
	}
}
int change(LinkList *l1)
{
	int res=0;
	while(l1->next!=NULL)
	{
		l1=l1->next;
		res=res*10+l1->val;
	}
	return res;
}
LinkList *su(int n)
{
	/*int res1=0;
	while(n)
	{
		res1=res1*10+n%10;
		n/=10;
	}
	cout<<res1<<endl;	*/
	LinkList *head;int res=0;LinkList *end;LinkList *node;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	while(n)
	{
		res=n%10;
		node=(LinkList*)malloc(sizeof(LinkList));
//		node=node->next;
		node->val=res;
		end->next=node;
		end=node;
		n/=10;
		end->next=0;
	}
	end->next=0;
	return head;
}
 
LinkList* reverse(LinkList *l1)
{
	LinkList *l2;
	stack<LinkList> s1;
	while(l1->next!=NULL)
	{
		l1=l1->next;
		s1.push(l1->val);
	}

 

 

int main()
{
	int s1,s2,sum;
	LinkList *yiku,*yiku1,*yiku3;
	yiku=create(5);
	yiku=ReverseList1(yiku);
	show(yiku);
/*	s1=change(yiku);
	cout<<"next list"<<endl;
	yiku1=create(5);
	s2=change(yiku1);
	sum=s1+s2;
//	cout<<sum<<endl;
	LinkList *yiku2;
	yiku2=su(sum);
	yiku2=ReverseList1(yiku2);
	show(yiku2);
//	cout<<change(yiku)<<endl;
//	show(yiku);*/
	return 0;
}
	
