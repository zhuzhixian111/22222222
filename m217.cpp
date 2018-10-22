#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	/*	bool t=false;
		for(int i=0;i<nums.size()-1;i++)
		{
			for(int j=i+1;j<nums.size();j++)
			{
				if(nums[i]==nums[j])
				{
					t=true;
					break;
				}
			}
		}

		return t;*/
		bool t=false;int num;
		for(int i=0;i<nums.size();i++)
		{
			num=0;
			num=count(nums.begin(),nums.end(),nums[i]);
			if(num>=2)
			{
				t=true;
				break;
			}
		}
		return t;

    }
};

int main()
{
	vector<int> v1{1,2,3,4,1};
	vector<int> v2{1,2,3,4};
	
	Solution yiku;
	cout<<yiku.containsDuplicate(v1)<<endl;
	cout<<yiku.containsDuplicate(v2)<<endl;
	return 0;
}
