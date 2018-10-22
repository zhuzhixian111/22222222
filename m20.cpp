#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{	
		stack<char> s1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='['||s[i]=='{'||s[i]=='(')
				s1.push(s[i]);
			else
			{
				if(s1.empty()) return false;
				if(s[i]==')'&& s1.top()!='(') return false;
				if(s[i]=='}'&& s1.top()!='{') return false;
				if(s[i]==']'&& s1.top()!='[') return false;
				s1.pop();
			}
		}
		return true;
	}
};
int main()
{
	Solution yiku;
	string s("[](");
	string a("()");
	cout<<yiku.isValid(s)<<endl;
	cout<<yiku.isValid(a)<<endl;
	return 0;
}

