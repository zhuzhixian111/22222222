#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
		int res=0;int res1=0;
		res=sss(num);
		if(res>9)
		{
			res1=sss(res);
		}
		return res1;
			
    }
	int sss(int num)
	{
		int res=0;int res1=0;
		while(num)
		{
			res+=num%10;
			num/=10;
		}
		if(res>9)
		{
			sss(res);
		}
		else
			return res;
		return res;
	}
};
int main()
{
	Solution yiku;
	cout<<yiku.addDigits(199)<<endl;

	return 0;
}
