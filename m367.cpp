#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
		bool t=false;int a=0;
		if(num==1)
			t=ture;
		for(int i=0;i<num/2;i++)
		{
			a=i*i;
			if(a==num)
			{
				t=true;
				break;
			}
			a=0;
		}
		return t;
    }
};

int main()
{
	Solution yiku;
	cout<<yiku.isPerfectSquare(14)<<endl;
	return 0;
}
