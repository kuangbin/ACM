#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
class WinterAndPresents {
	public:
	long long getNumber(vector <int> apple, vector <int> orange) {
		int n = apple.size();
		long long ret = 0;
		int Min = 200000000,Max = 0;
		for(int i = 0;i < n;i++)
		{
			int tmp = apple[i] + orange[i];
			Min = min(Min,tmp);
			Max = max(Max,tmp);
		}
		for(int i = 1;i <= Min;i++)
		{
			int n1 = 0,n2 = 0;
			for(int j = 0;j < n;j++)
			{
				n1 += min(i,apple[j]);
				n2 += max(0,i - orange[j]);
			}
			ret += n1 - n2 + 1;
		}
		return ret;
	}
};
