/*给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> v1(nums);
		vector<int> v2;int a=1;
		for(auto i=nums.begin();i!=nums.end();i++)
		{
			nums.erase(i);
			for(auto b:nums)
			{
				a*=b;
			}
			v2.push_back(a);
			a=1;
			nums=v1;

		}
		return v2;
    }
};

int main()
{
	vector<int> v1{1,2,3,4};
	Solution yiku;
	vector<int> v2;
	v2=yiku.productExceptSelf(v1);
	for(auto a:v2)
		cout<<a<<" ";
	return 0;
}
