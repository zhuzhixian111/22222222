#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int res=INT_MIN;int la=0;
	   for(auto num:nums)
		{
			la=max(la+num,num);
			res=max(res,la);
		}
	   return res;
    }
};

int main()
{
	Solution yiku;
	vector<int> v1{-1,-2,10,-1,3};
	cout<<yiku.maxSubArray(v1)<<endl;
	return 0;
}
