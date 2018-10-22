#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef struct sss
{
	int val;
	struct sss *next;
}LinkList;

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

LinkList* reverse(LinkList *l1)
{
	stack<int> s1;
	stack<LinkList> s2;
	LinkList *l2;
	while(l1->next!=NULL)
	{
		l1=l1->next;
		s1.push(l1->val);
	}
	l2->val=s1.top();
/*	while(s1.top())
	{
		l2=(LinkList*)malloc(sizeof(LinkList));
		l2->val=s1.top();
		l2=l2->next;
		s1.pop();
		
	}*/
	return l2;


}

void show(LinkList *l1)
{
	while(l1->next!=NULL)
	{
		l1=l1->next;
		printf("%d",l1->val);
	}
}


int main()
{
	LinkList *yiku,*yiku1;
	int n;
	cin>>n;
	yiku=create(n);
	stack<int> s1;
	LinkList *l1;
	l1=reverse(yiku);
//	show(l1);
	while(l1->next!=NULL)
	{
		l1=l1->next;
		s1.push(l1->val);
	}
//	cout<<s1.top()<<endl;
//	s1.pop();
//	cout<<s1.top()<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<s1.top();
		s1.pop();
	}
//	cout<<s1.top();
//	cout<<s1.top()<<endl;
//	cout<<l1->next->val;
//	cout<<l1->next->next->val;
//	cout<<l1->next->val<<endl;
/*	while(s1.top())
	{
		cout<<s1.top();
		s1.pop();
	}*/
//	cout<<s1.top()<<endl;
//	show(yiku);
	cout<<endl;
	return 0;
}
