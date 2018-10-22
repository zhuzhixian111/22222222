#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		int res=0;
		map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'M',1000}};
		for(int i=0;i<s.size();i++)
		{
			int val=m[s[i]];
			if(i==s.size()-1 || m[s[i+1]]) res+= val;
			else
			res -= val;
		}
		return res;
	}
};
int main()
{
	string a("LXXXVI");
	Solution yiku;
	cout<<yiku.romanToInt(a)<<endl;
	return 0;
}
