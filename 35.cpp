#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};
int main()
{
	Solution yiku;
	vector<int> v1{1,2,3,4,5};
	cout<<yiku.searchInsert(v1,3)<<endl;
	return 0;
}

