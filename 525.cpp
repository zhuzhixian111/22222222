/*给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组。

示例 1:

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
注意: 给定的二进制数组的长度不会超过50000。*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		
		vector<int> v1;int maxx=0;int min;
		for(int i=0;i<nums;i++)
		{
			v1.push_back(nums[i]);
			if(v1.size()%2==0 && count(v1.begin(),v1.end(),0)==count(v1.begin(),v1.end(),1)
			maxx=max(maxx,v1.size());
		}
		return maxx;
};

int main()
{
	
