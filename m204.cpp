#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
		int num=0;
		for(int i=2;i<n;i++)
			num+=ift(i);
		return num;
    }
	bool ift(int n)
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				return 0;
			}
		}
		return true;
	}
};

int main()
{
	Solution yiku;
	cout<<yiku.countPrimes(1500000)<<endl;
	//cout<<yiku.ift(8)<<endl;
	return 0;
}
