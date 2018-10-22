/*给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		map<char,int> m1;int length=0;
		for(int i=0;i<s.size();i++)
		{
			++m1[s[i]];
			length++;
			for(int j=0;j<m1.size();j++)
			{
				if(m1[s[j]]==2)
					break;
			}
		}
		return length;




    }
};

int main()
{
	string a("abcabcgg");
	Solution yiku;
	cout<<yiku.lengthOfLongestSubstring(a)<<endl;
	return 0;
}

