#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		if(nums[0]!=0)
			return 0;
		int s=0;
		for(int i=0,j=i+1;i<nums.size();i++)
		{
			if(nums[j-i]!=1)
			{
				s=i+1;
				break;
			}
		}
		return s;


				
    }
};

int main()
{
	Solution yiku;
	vector<int> v1{9,6,4,2,3,5,7,0,1};
	cout<<yiku.missingNumber(v1)<<endl;
	return 0;
}




