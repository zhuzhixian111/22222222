#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
 public:
     vector<int> twoSum(vector<int> &numbers, int target) {
         vector<int> result;
         for (int i = 0; i < numbers.size()-1; i++) {
             for (int j = i+1; j < numbers.size(); j++) {
                 if (numbers[i] + numbers[j]==target) {
                     result.push_back(i);
                     result.push_back(j);
                 }
             }
         }
         return result;
     }
 };
int main()
{	
	vector<int> v1{2,7,11,15};
	int target=9;
	vector<int> v2;
	Solution yiku;
	v2=yiku.twoSum(v1,target);
	for(auto a:v2)
		cout<<a<<" ";
	
	return 0;
}

