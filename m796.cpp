#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool rotateString(string A, string B) {
		bool t=false;char s;
		if(A.size()==B.size()==1 && A==B) return true;
		for(int i=0;i<B.size()-1;i++)
		{
			B.insert(B.end(),B[0]);
			B.erase(B.begin());
			if(A==B)
				t=true;
		}
		return t;

    }
};

int main()
{
	string a("abcde");
	string b("cdeab");
	Solution yiku;
	cout<<yiku.rotateString(a,b)<<endl;
	return 0;
}
