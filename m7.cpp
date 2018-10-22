#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		int a=0;
		while(x!=0)
		{
			a=a*10+x%10;
			x /=10;
		}
		return a;
	}
};

int main()
{
	Solution yiku;
	cout<<yiku.reverse(123)<<endl;
	cout<<yiku.reverse(-1965)<<endl;
	cout<<yiku.reverse(-123)<<endl;
	return 0;
}
	
