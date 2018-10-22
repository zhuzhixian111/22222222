/*给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		map<int,int> m1;int res=0;
		for(int i=0;i<nums.size();i++)
			++m1[nums[i]];
		for(auto a:m1)
		{
			if(a.second>nums.size()/2)
			{
				res=a.first;
				break;
			}
		}
		
		return res;
    }
};

int main()
{
	vector<int> v1{2,2,3,5,6,6,6,6,6,6,6,6,6,1,1,2,3};
	Solution yiku;
	cout<<yiku.majorityElement(v1)<<endl;
	return 0;
}


