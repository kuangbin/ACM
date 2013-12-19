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
class ORSolitaireDiv2 {
	public:
	int getMinimum(vector <int> numbers, int goal) {
		int n = numbers.size();
		int num[33];
		memset(num,0,sizeof(num));
		int tmp = 0;
		for(int i = 0;i < n;i++)
		{
			int v = numbers[i];
			if((goal|v) != goal)continue;
			tmp |= v;
			for(int j = 0; j < 31;j++)
				if(v & (1<<j))
					num[j]++;
		}
		if(tmp != goal)return 0;
		int ans = 10000;
		for(int i = 0;i < 31;i++)
			if(goal & (1<<i))
			{
				ans = min(ans,num[i]);
			}
		return ans;
		
	}
};
