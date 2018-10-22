#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main()
{
	vector<int> v{1,2,3,4,5,6,7,8,9};
	while(v.size()!=1)
	{
	for(auto item=v.begin();item<v.end();item++)
	{
		
		v.erase(item);
	}
	if(v.size()==1)
		break;
	for(auto item=v.begin()+1;item<v.end();item++)
	{
		v.erase(item);
	}
	}
	for(auto a:v)
		cout<<a;
	return 0;
}
