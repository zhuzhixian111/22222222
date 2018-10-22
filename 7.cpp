#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
	 int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
	}
};
int main()
{
	Solution yiku;
	cout<<yiku.reverse(-123);
	cout<<yiku.reverse(-9561);
	return 0;
}
