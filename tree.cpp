#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position Find(int X ,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X,SearchTree T);
SearchTree Delete(int X,SearchTree T);
int Retrieve(Position P);
struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
	struct TreeNode *next;
};
typedef TreeNode yiku;
 struct TreeNode *next;
SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int X,SearchTree T)
{
	if(T==NULL)
		return NULL;
	if(X<T->Element)
		return Find(X,T->Left);
	else if(X>T->Element)
		return Find(X,T->Right);
	else
		return T;
}

Position FindMin(SearchTree T)
{
	if(T==NULL)
		return NULL;
	else if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
	if(T != NULL)
		while(T->Right != NULL)
			T=T->Right;
	return T;
}

SearchTree Insert(int X,SearchTree T)
{
	if(T == NULL)
	{
		T=(TreeNode*)malloc(sizeof(TreeNode));
		if(T==NULL)
			perror("Out of space!!!");
		else 
		{
			T->Element=X;
			T->Left = T->Right=NULL;
		}
	}
	else if(X<T->Element)
		T->Left=Insert(X,T->Left);
	else if(X>T->Element)
		T->Right=Insert(X,T->Right);
	return T;
}
//typedef struct TreeNode *head1;
//typedef struct TreeNode *node;
//typedef struct TreeNode *end;
yiku *create(int n)
{
	TreeNode *head1,*node,*end;
	head1=(yiku*)malloc(sizeof(yiku));
	end=head1;
	for(int i=0;i<n;i++)
	{
		node=(yiku*)malloc(sizeof(yiku));
		scanf("%d",&node->Element);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head1;
}
void display(TreeNode *l1)
{
	while(l1->next!=NULL)
	{
		l1=l1->next;
		printf("%d",l1->Element);
	}

}
yiku* create_tree(int n)
{
	yiku *node=new yiku;
	cin>>val;
	if(val==0)
	{
		return NULL;
	}

int main()
{
	TreeNode *yiku;
	yiku=create(5);
	MakeEmpty(yiku);
	display(yiku);	

	return 0;

}








