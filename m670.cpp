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

class Solution {
public:
    int maximumSwap(int num) {
		vector<int> v1;int maxnum1=0;
		vector<int> v2;
		while(num)
		{
			v1.push_back(num%10);
			num/=10;
		}
		for(int i=0,j=v1.size()-1;i<v1.size();i++,j--)
		{
			int maxnum=0;
			for(int q=i+1;q<j;q++)
			{
				swap(v1[i],v1[q]);int c=0;
				for(int w=0;w<v1.size();w++)
				{
					c=c*10+v1[w];
				}
				maxnum1=max(c,maxnum1);
				v2.push_back(maxnum1);
			}
		}
		return maxnum1;


    }
};



int main()
{
	Solution yiku;
	cout<<yiku.maximumSwap(9973)<<endl;
	return 0;
}
