#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <queue>
#include <new>
#include <stack>
#include <cstring>

using namespace std;

class Solution
{

};
typedef struct student
{
	int score;
	struct student *next;
}LinkList;

LinkList *create(int n)
{
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	for(int i=0;i<n;i++)
	{
		node=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&node->score);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head;
}
void change(LinkList *list) {//n为第n个节点
	LinkList *t = list;
	int i = 0,n;
	cout<<"输入要修改的位置"<<endl;
	cin>>n;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		puts("输入要修改的值");
		scanf("%d", &t->score);
	}
	else {
		puts("节点不存在");
	}
}
void delet(LinkList *list, int n) {
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t->next;
		free(t);
	}
	else {
		puts("节点不存在");
	}
}
LinkList* removeNthFromEnd(LinkList* head, int n) {
        if (!head->next) return NULL;
        LinkList *pre = head, *cur = head;
        for (int i = 0; i < n; ++i) cur = cur->next;
        if (!cur) return head->next;
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
void display(LinkList *list,LinkList *head)
{
	while(list->next != NULL)
	{
		list=list->next;
		printf("%d",list->score);
	}
	list=head;
}
int main()
{
	LinkList *yiku,*head;
	yiku=create(5);
	head=yiku;
	change(yiku);
/*	while(yiku->next != NULL)
	{
		yiku=yiku->next;
		printf("%d",yiku->score);
	}*/
	display(yiku,head);
	change(yiku);
	display(yiku,head);
	removeNthFromEnd(yiku,2);
	display(yiku,head);
//	yiku->next=yiku1->next;
//	yiku->next->next=NULL;
/*	yiku=head;
	change(yiku,4);
	cout<<endl;
	while(yiku->next!=NULL)
	{
		yiku=yiku->next;
		printf("%d",yiku->score);
	}*/
	return 0;
}
