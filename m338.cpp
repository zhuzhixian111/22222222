
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
	
		 vector<int> res;
        for (int i = 0; i <= num; ++i) {
            res.push_back(bitset<32>(i).count());
        }
        return res;
    }
};


int main()
{
	Solution yiku;
	vector<int> v3;
	v3=yiku.countBits(9);
	for(auto a:v3)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}
