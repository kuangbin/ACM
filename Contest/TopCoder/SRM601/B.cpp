/* ***********************************************
Author        :kuangbin
Created Time  :2013-12-28 22:48:14
File Name     :E:\2013ACM\TC\SRM601\B.cpp
************************************************ */

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
const int MOD = 1e9+7;
int f[2010][2048][2];
//f[i][j][k] 表示前i个数，A set 和 B set 的数异或和为j, A set 异或和第r位为0,1的方案数
class WinterAndSnowmen
{
	public:
		int getNumber(int N, int M)
		{
			int Max = max(N,M);
			int ans = 0 ;
			for(int r = 0; r <= 10;r++)//枚举Aset 和Bset 哪一个二进制位不同
			{
				memset(f,0,sizeof(f));
				f[0][0][0] = 1;
				for(int i = 1;i <= Max;i++)
					for(int j = 0;j < 2048;j++)
						for(int k = 0;k < 2;k++)
						{
							f[i][j][k] += f[i-1][j][k];
							if(f[i][j][k] >= MOD)
								f[i][j][k] -= MOD;
							if(i <= N)
							{
								f[i][j^i][k ^ ((i>>r)&1)] += f[i-1][j][k];
								if(f[i][j^i][k ^ ((i>>r)&1)] >= MOD)
									f[i][j^i][k ^ ((i>>r)&1)] -= MOD;
							}
							if(i <= M)
							{
								f[i][j^i][k] += f[i-1][j][k];
								if(f[i][j^i][k] >= MOD)
									f[i][j^i][k] -= MOD;
							}
						}
				for(int i = (1<<r);i < (1<<(r+1));i++)
				{
					ans += f[Max][i][0];
					if(ans >= MOD)
						ans -= MOD;
				}
			}
			return ans;
		}
	
};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    return 0;
}
