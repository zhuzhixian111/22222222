#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
		string b;
		char c;
		for(int i=0;i<str.size();i++)
		{
			c=str[i];
			if(tolower(c))
				b.push_back(tolower(c));
		}
		return b;
    }
};

int main()
{
	Solution yiku;
	string a("Hello");
	string aa;
	aa=yiku.toLowerCase(a);
	cout<<aa<<endl;
	return 0;
}
