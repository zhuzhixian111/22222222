/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
int res = 0;
        for (auto num : nums) res ^= num;
        return res;	
    }
};
int main()
{
	vector<int> v{4,5,4,6,6,8,8,1,2,2,1};
	Solution yiku;
//	cout<<yiku.singleNumber(v);
	int c=5,d=2;
	c^=d;
	cout<<c<<endl;
	return 0;
}
