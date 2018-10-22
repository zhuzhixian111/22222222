/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
		 string res = "";
        int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
};

int main()
{
	Solution yiku;
	string a("12345");string b("12345");
	cout<<yiku.addStrings(a,b)<<endl;
	return 0;
}

