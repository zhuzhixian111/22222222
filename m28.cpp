#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if(haystack.empty()) return -1;
		int m=haystack.size();int n=needle.size();
		for(int i=0;i<=m-n;++i)
		{
			int j=0;
			for(j=0;j<n;++j)
			{
				if(haystack[i+j]!=needle[j]) break;
			}
			if(j==n)
				return i;
		}
    }

};

int main()
{
	string a("hffffffffffffffffffffsssssllo");
	string b("ll");
	Solution yiku;
	cout<<yiku.strStr(a,b);
	return 0;
}
