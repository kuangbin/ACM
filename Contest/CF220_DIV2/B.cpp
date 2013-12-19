/* ***********************************************
Author        :kuangbin
Created Time  :2013-12-19 0:07:55
File Name     :E:\2013ACM\CF±ÈÈü\CF220_DIV2\B.cpp
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

int dp1[100010][10];
unsigned long long dp2[100010][10];

char str[1000100];
int a[1000100];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",str) == 1)
	{
		int n = strlen(str);
		for(int i = 1;i <= n;i++)
			a[i] = str[i-1] - '0';
		
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for(int i = a[1];i <= a[1];i++)
		{
			dp1[1][i] = (a[1] == 9);
			dp2[1][i] = 1;
		}
		for(int i = 1;i < n;i++)
			for(int j = 1;j <= 9;j++)
				if(dp2[i][j] > 0)
			{
				//printf("%d %d %d\n",i,j,dp1[i][j]);
				//cout<<dp2[i][j]<<endl;
				int tmp = dp1[i][j] + (a[i+1] == 9);
				if(tmp > dp1[i+1][a[i+1]])
				{
					dp1[i+1][a[i+1]] = tmp;
					dp2[i+1][a[i+1]] = dp2[i][j];
				}
				else if(tmp == dp1[i+1][a[i+1]])
				{
					dp2[i+1][a[i+1]] += dp2[i][j];
				}
				if(j + a[i+1] == 9)
				{
					tmp = dp1[i][j] + 1;
					if(tmp > dp1[i+1][a[i+1] + j])
					{
						dp1[i+1][a[i+1] + j] = tmp;
						dp2[i+1][a[i+1] + j] = dp2[i][j];
					}
					else if(tmp == dp1[i+1][a[i+1] + j])
						dp2[i+1][a[i+1] + j] += dp2[i][j];
				}
			}
		int ans1 = 0;
		unsigned long long ans = 0;
		for(int i = 1;i <= 9;i++)
		{
			if(ans1 < dp1[n][i])
			{
				ans1 = dp1[n][i];
				ans = dp2[n][i];
			}
			else if(ans1 == dp1[n][i])
				ans += dp2[n][i];
		}
		
		cout<<ans<<endl;
		/*
		unsigned long long ans = 1;
		int id = 1;
		a[n+1] = 100;
		for(int i = 2;i <= n+1;i++)
		{
			if(a[i] + a[i-1] != 9)
			{
				if(i - id > 1)
				{
					if((i - id)%2)
						ans*=2;
				}
				id = i;
			}
		}
		cout<<ans<<endl;
		*/
	}
    return 0;
}
