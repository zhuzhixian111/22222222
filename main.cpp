#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <queue>
#include <new>
#include <stack>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool hasePath(char *matrix,int rows,int cols,char *str)
{
	if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
		return false;
	bool *visited =new bool[rows *cols];
	memset(visited ,0,rows*cols);
	int pathLengeh=0;
	for(int row=0;row<rows'row++)
	{
		for(int col=0;col<cols;col++)
		{
			if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
				return true;
		}
	}
}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char*str,int &pathLengeh,bool visited)
{
	if(str[pathLengeh]=='\0')
		return true;
	bool hasPath=false;
	
		




int main()
{
	return 0;
}
