/*给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		string res;vector<int> res1;
		int q=0,w=0,s1=0,s2=0,l=0;
		s1=stoi(a,0,2);
		s2=stoi(b,0,2);
		l=s1+s2;
		while(l)
		{
			res1.insert(res1.begin(),l%2);
			l/=2;
		}
		for(int i=0;i<res1.size();i++)
		{
			q=q*10+res1[i];
		}
		stringstream s3;
		s3<<q;
		s3>>res;
		return res;
	}
};

int main()
{
	Solution yiku;
	string a("1010");string b("1011");
	string qwq;
	qwq=yiku.addBinary(a,b);
	cout<<qwq<<endl;
	return 0;
}
