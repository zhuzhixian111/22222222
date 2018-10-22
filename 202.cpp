#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
		set<int> s1;
		while(n!=1)
		{
			int t=0;
			while(n)
			{
				t+=(n%10)*(n%10);
				n/=10;
			}
			n=t;
			if(s1.count(n)) break;
			else
				s1.insert(n);
		}
		return n==1;
    }
};

int main()
{
	Solution yiku;
	cout<<yiku.isHappy(19)<<endl;
	cout<<yiku.isHappy(11)<<endl;
	return 0;
}

