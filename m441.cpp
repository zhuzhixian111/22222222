/*你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:

n = 5

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤

因为第三行不完整，所以返回2.
示例 2:

n = 8

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

因为第四行不完整，所以返回3.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
		/*int s=1;int c;
		if(n==1)
			return 1;
		for(int i=1,j=2;i<n;i++)
		{
			if(s+j>n)
			{
				c=i;
				return c;
			}

			s+=j;
			j++;
		}
		return c;*/
		int cur = 1, rem = n - 1;
        while (rem >= cur + 1) {
            ++cur;
            rem -= cur;
        }
        return n == 0 ? 0 : cur;
    }
};
int main()
{
	Solution yiku;
	cout<<yiku.arrangeCoins(2147483)<<endl;
	return 0;
}
