#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if(strs.empty())
			return " ";
		string res=" ";
		for(int j=0;j<strs[0].size();++j)
		{
			char c=strs[0][j];
			for(int i=1;i<strs.size();++i)
			{
				if(j>=strs[i].size() || strs[i][j] != c)
				{
					return res;
				}
			}
			res.push_back(c);
		}
	}
};

int main()
{
	vector<string> v1{"flower","flow","float"};
	Solution yiku;
	string a;
	a=yiku.longestCommonPrefix(v1);
	cout<<a<<endl;
	return 0;


}
