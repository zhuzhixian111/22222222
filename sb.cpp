#include <iostream>
#include <vector>
using namespace std;
 
class Node
{
public:
	Node(int data)
	{
		value = data;
		next = 0;
	}
	int value;
	Node *next;
};
 
void add(int value, Node *&first, Node *&end)//value为要插入的元素
{
	if (first == 0)
		first = end = new Node(value);
	else
	{
		end->next = new Node(value);
		end = end->next;//end移动到新节点位置	
		end->next = 0;//这句在这里可以省掉，因为新节点在构造函数已经使next成员为0了
	}
}
 
void display(Node *first)
{
	if (first == 0)
	{
		cout << "链表里面没有元素" << endl;
		return;
	}
	else
	{
		Node *item = first;//item用于遍历链表所有节点
		while (item)
		{
			cout << item->value << " ";
			item = item->next;
		}
		cout << endl;
	}
 
}
 
//输入1 2 3 4 5
//输出5 4 3 2 1
 
Node* reverseLinkedList(Node *&first)
{
	if (first == 0)
		return 0;
 
	//定义三个指针
	Node *prev = first;
	Node *cur = first->next;
	Node *next = 0;//保存原链表中cur的下一个节点
	while (cur)
	{
		//因为要修改cur的next成员，先将next移到cur的下一个节点
		next = cur->next;//先将next移到cur的下一个节点
		cur->next = prev;//修改cur->next
 
		prev = cur;//prev前移到cur节点
		cur = next;//cur在原链表中递进一个节点	
	}//当cur移动到5后面的空节点时，退出循环，此时prev移到了5节点，是新链表的首节点
 
	first->next = 0;//原链表的first节点(新链表的尾节点)下一个节点为0
	first = prev;//让first移动到prev(首节点)
 
	return first;
}
 
 
int main()
{
	Node*first = 0, *end = 0;
	int N, temp;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		add(temp, first, end);
	}
 
	display(first);
 
	reverseLinkedList(first);
	display(first);
 
	return 0;
}

