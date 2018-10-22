#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
	Node(int data)
	{
		value=data;
		next=0;
	}
	int value;
	Node *next;
};

void add(int value,Node *&first,Node *&end)
{
	if(first==0)
		first=end=new Node(value);
	else
	{
		end->next=new Node(value);
		end=end->next;
		end->next=0;
	}
}

void display(Node *first)
{
	if(first==0)
		return ;
	else
	{
		Node *item=first;
		while(item)
		{
			cout<<item->value<<" ";
			item=item->next;
		}
		cout<<endl;
	}
}
bool hasCycle(Node *head)
{
	  Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;

}
int main()
{
	Node *first=0,*end=0;
	int temp;
	for(int i=0;i<6;i++)
	{
		cin>>temp;
		add(temp,first,end);
	}
	display(first);
/*	Node *three;three=first;int c;int d;
	for(int i=0;i<2;i++)
	{
		c=three->value;
		three=three->next;
	}
	Node *six;six=first;
	for(int i=0;i<6;i++)
	{
		d=six->value;
		six=six->next;
	}
	six=three;*/
	Node *one=first;Node *two=first;
	int c;
	one=one->next->next;
	two=two->next->next->next->next;
	two=one->next;
	cout<<one->value;
	cout<<two->value;
	cout<<hasCycle(first)<<endl;
	display(first);
//	cout<<c<<endl;
	return 0;
}
















	
