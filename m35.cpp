#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]==target)
				return i;
			else
			{
				if(nums[i]<target && nums[i+1]>target)
					return i+1;
				else if(target<nums[0])
					return 0;
				else if(target>nums[nums.size()-1])
					return nums.size();
			}
		}
		return 0;
    }
};

int main()
{
	Solution yiku;
	vector<int> v1{1,3,5,7,9};
	cout<<yiku.searchInsert(v1,5)<<endl;
	vector<int> v2{1,3,5,6};
	cout<<yiku.searchInsert(v2,0)<<endl;
	return 0;
}
