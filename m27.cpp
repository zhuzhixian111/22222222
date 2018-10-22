#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

		int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
	}
};

int main()
{
	vector<int> v1{0,1,2,2,3,0,4,2};
	Solution yiku;
	cout<<yiku.removeElement(v1,2);
	for(auto a:v1)
		cout<<a<<" ";
	return 0;
}
