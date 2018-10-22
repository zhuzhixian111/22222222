/*给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
 

示例 2:

输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
 

说明:

k 的值为正数，且总是小于给定排序数组的长度。
数组不为空，且长度不超过 104
数组里的每个元素与 x 的绝对值不超过 104*/

#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> res=arr;
		while(res.size()>k)
		{
			int first=0,last=res.size()-1;
			if(x-res.front()<=res.back()-x)
			{
				res.pop_back();
			}
			else
				res.erase(res.begin());
		}
		return res;

    }
};
int main()
{
	vector<int> v1{1,2,3,4,5};
	Solution yiku;
	vector<int> v2;
	v2=yiku.findClosestElements(v1,4,3);
	for(auto a:v2)
		cout<<a;
	cout<<endl;
}
