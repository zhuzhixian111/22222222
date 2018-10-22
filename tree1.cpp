/*
功能：（1）根据二叉树的括号表示法建立二叉树
      （2）根据二叉树获取其括号表示法字符串
      （3）输出二叉树的深度
      （4）输出二叉树的宽度
      （5）输出二叉树的结点的个数
      （6）输出二叉树叶子结点的个数
作者：pussy
日期：2015-11-22
*/

# include<stdio.h>
# include<malloc.h>
# include<string.h>

#define MAX 100

typedef struct BiNode{
    char data;//记录二叉树的节点信息
    int cs;//记录二叉树的层数
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

typedef struct{
    BiTree data[MAX];
    int top;
}Stack;

typedef struct{
    BiTree data[MAX];
    int front,rear;
}Queue;

void InitStack(Stack &s);
int isFull(Stack s);
int isEmpty(Stack s);
int Push(Stack &s,BiTree p);
int Pop(Stack &s);
int getTop(Stack &s,BiTree &p);
int createBiTree(BiTree &T,char str[]);
BiTree newnode(char c);
void printBiTree(BiTree T);
int getHeight(BiTree T);
int getWidth(BiTree T);
void getNum(BiTree T,int &num1,int &num2);
void InitQueue(Queue &q);
int EnQueue(Queue &q,BiTree t);
BiTree DeQueue(Queue &q);


int main()
{
    int num1,num2;//num1用于记录二叉树的结点个数，num2用于记录二叉树叶子结点的个数
    char khdata[MAX];//二叉树的括号表示字符串
    printf("请输入二叉树的括号表示法:\n");
    scanf("%s",khdata);
    BiTree T=NULL;
    int t=createBiTree(T,khdata);
    if(t==1)
        printf("二叉树建立成功!\n");
    else
    {
        printf("二叉树建立失败!\n");
        return 0;
    }
    printf("根据所建二叉树获得括号表示法字符串:");
    printBiTree(T);
    printf("\n树的深度为：%d\n",getHeight(T));
    printf("树的宽度为：%d\n",getWidth(T));
    getNum(T,num1,num2);
    printf("二叉树的结点的个数为：%d,叶子结点的个数为：%d\n",num1,num2);
    return 0;
}

//根据二叉树的括号表示法重建二叉树
int createBiTree(BiTree &T,char str[])
{
    int i=0;
    Stack s;
    InitStack(s);
    if(strlen(str)==0)//空树
    {
        T=NULL;
        return 0;
    }
    T=newnode(str[i++]);
    BiTree t=T;
    Push(s,T);
    //结束标志：栈中只剩下根结点，且字符串扫描完毕
    while(i<strlen(str)||(getTop(s,t)&&t!=T))
    {
        switch(str[i])
        {
        case '(':
            if(str[i+1]!=',')
            {
                //getTop(s,t);
                t->lchild=newnode(str[i+1]);
                Push(s,t->lchild);
                t=t->lchild;
                i=i+2;
            }
            else
            {
                Push(s,NULL);
                i++;
            }
            break;
        case ',':
            Pop(s);
            getTop(s,t);
            t->rchild=newnode(str[i+1]);
            Push(s,t->rchild);
            t=t->rchild;
            i=i+2;
            break;
        case ')':
            Pop(s);
            i++;
            break;
        }
    }
    return 1;
}

//括号表示法打印出二叉树
void printBiTree(BiTree T)
{
    if(T==NULL)
        return ;
    printf("%c",T->data);
    if(T->lchild==NULL&&T->rchild==NULL)
    {
        return ;
    }
    else
    {
        printf("(");
        if(T->lchild!=NULL)
            printBiTree(T->lchild);
        if(T->rchild!=NULL)
        {
            printf(",");
            printBiTree(T->rchild);
        }
        printf(")");
    }
}


//获取二叉树的深度
//二叉树的深度等于其左子树、右子树深度较高者加一
int getHeight(BiTree T)
{
    if(T==NULL)
        return 0;
    else{
        return (getHeight(T->lchild)>getHeight(T->rchild)?getHeight(T->lchild):getHeight(T->rchild))+1;
    }
}


//层次遍历二叉树获得二叉树的宽度
//先求出每层节点的个数，二叉树宽度等于节点数最多的那层的节点的个数
int getWidth(BiTree T)
{
    int num[MAX];
    memset(num,0,sizeof(num));
    if(T==NULL)
        return 0;
    else
    {
        Queue q;
        BiTree t=NULL;
        InitQueue(q);
        EnQueue(q,T);
        T->cs=1;
        num[T->cs]++;
        while(!(q.front==q.rear&&q.data[q.front]==0))//队列不为空
        {
            t=DeQueue(q);
            if(t->lchild)
            {
                t->lchild->cs=t->cs+1;
                num[t->lchild->cs]++;
                EnQueue(q,t->lchild);

            }
            if(t->rchild)
            {
                t->rchild->cs=t->cs+1;
                num[t->rchild->cs]++;
                EnQueue(q,t->rchild);
            }
        }
        int i,max=0;
        for(i=1;num[i];i++)
        {
            if(num[i]>max)
                max=num[i];
        }
        return max;
    }
}

//先序遍历获得二叉树的节点的个数和叶子节点的个数
void getNum(BiTree T,int &num1,int &num2)
{
    num1=0;num2=0;
    if(T==NULL)//空树
    {
        return ;
    }
    else
    {
        Stack s;
        InitStack(s);
        Push(s,T);
        num1++;
        if(T->lchild==NULL&&T->rchild==NULL)
            num2++;
        BiTree t=T;
        while(!isEmpty(s))
        {
            while(t)
            {
                Push(s,t->lchild);
                if(t->lchild)
                {
                    num1++;
                    if(t->lchild->lchild==NULL&&t->lchild->rchild==NULL)
                        num2++;
                }
                t=t->lchild;
            }
            Pop(s);
            if(!isEmpty(s))
            {
                getTop(s,t);
                Pop(s);
                Push(s,t->rchild);
                if(t->rchild)
                {
                    num1++;
                    if(t->rchild->lchild==NULL&&t->rchild->rchild==NULL)
                        num2++;
                }
                t=t->rchild;
            }
        }
    }
}

//入栈，若成功，则返回1，否则返回0
int Push(Stack &s,BiTree p)
{
    if(isFull(s))
        return 0;
    else
    {
        s.data[s.top]=p;
        s.top++;
        return 1;
    }
}

//出栈，若出栈成功，则返回1，否则返回0
int Pop(Stack &s)
{
    if(isEmpty(s))
        return 0;
    else
    {
        s.top--;
        return 1;
    }
}

//获得栈顶元素，成功返回1，失败返回0
int getTop(Stack &s,BiTree &p)
{
    if(isEmpty(s))
        return 0;
    else
    {
        p=s.data[s.top-1];
        return 1;
    }
}

//分配一个新的节点
BiTree newnode(char c)
{
    BiTree t=(BiTree)malloc(sizeof(BiNode));
    t->data=c;
    t->lchild=t->rchild=NULL;
    return t;
}

//初始化栈
void InitStack(Stack &s)
{
    s.top=0;
}

//判断栈是否满了，若是，则返回1，否则返回0.
int isFull(Stack s)
{
    if(s.top>=MAX)
        return 1;
    else
        return 0;
}

//判断栈是否为空，若是，返回1，否则返回0
int isEmpty(Stack s)
{
    if(s.top==0)
        return 1;
    else
        return 0;
}


//初始化队列
void InitQueue(Queue &q)
{
    q.front=q.rear=0;
    memset(q.data,0,MAX*sizeof(char));//初始化时队列数据为0
}

//入队(循环队列)，成功返回1，失败返回0
int EnQueue(Queue &q,BiTree t)
{
    if(q.front==q.rear&&q.data[q.front]!=0)//队列满
        return 0;
    else
    {
        q.data[q.rear]=t;
        q.rear=(q.rear+1)%MAX;
        return 1;
    }
}


//出队，失败返回0
BiTree DeQueue(Queue &q)
{
    BiTree t=q.data[q.front];
    q.data[q.front]=0;
    q.front=(q.front+1)%MAX;
    return t;
}


