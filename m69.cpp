/*实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。*/
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
		int a=pow(x,1/2);
		
		return a;
    }
};

int main()
{
	Solution yiku;
	int b=8;
	cout<<yiku.mySqrt(b)<<endl;
	cout<<pow(2,3)<<endl;
	cout<<(int)pow(8,0.5)<<endl;
	return 0;
}
