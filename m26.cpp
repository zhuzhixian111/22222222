#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	 if (nums.empty()) return 0;
        int pre = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]) ++cur;
            else nums[++pre] = nums[cur++];
        }
        return pre + 1;
    }
};


int main()
{
	Solution yiku;
	vector<int> v1{1,1,1,2,2,3,3,4,5,6,6};
	cout<<yiku.removeDuplicates(v1);
	for(auto a:v1)
		cout<<a<<" ";
	return 0;
}
