/*给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1;set<int> s2;
		vector<int> v1;
		for(int i=0;i<nums1.size();i++)
			s1.insert(nums1[i]);
		for(int i=0;i<nums2.size();i++)
			s2.insert(nums2[i]);
		for(auto a:s1)
		{
			for(auto b:s2)
			{
				if(a==b)
					v1.push_back(a);
			}
		}
		return v1;
	 }
};

int main()
{
	vector<int> v1{4,9,5};
	vector<int> v2{9,4,9,8,4};
	Solution yiku;
	vector<int> v3;
	v3=yiku.intersection(v1,v2);
	for(auto a:v3)
		cout<<a<<" ";
	return 0;
}






