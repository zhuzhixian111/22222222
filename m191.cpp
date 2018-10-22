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

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		vector<int> v1;
		int res;
		uint32_t i=0;
		i=n;
		while(i)
		{
			v1.insert(v1.begin(),i%2);
			i/=2;
		}
		res=count(v1.begin(),v1.end(),1);
	/*	for(int i=0;i<v1.size();i++)
		{
			res=res*10+v1[i];
		}*/
		return res;

    }
};

int main()
{
	vector<int> v1{1};
	Solution yiku;
	cout<<yiku.hammingWeight(2147483648)<<endl;
	return 0;
}
