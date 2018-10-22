#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		ddd(n,n,"",res);
		return res;
	}
		void ddd(int left,int right,string out,vector<string> &res)
		{
			if(left>right) return;
			if(left==0 && right==0) res.push_back(out);
			else
			{
				if(left>0)
					ddd(left-1,right,out+'(',res);
				if(right>0)
					ddd(left,right-1,out+')',res);
			}
    }
};

int main()
{
	Solution yiku;
	vector<string> v1;
	v1=yiku.generateParenthesis(3);
	for(auto a:v1)
		cout<<a<<endl;
	return 0;
}
