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
#include <time.h>
using namespace std;

class TheShuttles
{
	
	public:
	int getLeastCost(vector <int> cnt, int baseCost, int seatCost)
	{
		int ret = 0x3f3f3f3f;
		for(int i = 1; i <= 100;i++)
		{
			int sum = 0;
			for(int j = 0;j < cnt.size();j++)
			{
				int tmp = (cnt[j] + i - 1)/i;
				sum += baseCost*tmp + seatCost * tmp * i;
			}
			ret = min(ret,sum);
		}
		return ret;
	}
		
};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    return 0;
}
