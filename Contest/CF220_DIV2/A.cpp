/* ***********************************************
Author        :kuangbin
Created Time  :2013-12-18 23:33:01
File Name     :E:\2013ACM\CF±ÈÈü\CF220_DIV2\A.cpp
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
const int INF = 0x3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,i,j,a,b;
	while(scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b) == 6)
	{
		int ans = INF;
		bool flag ;
		flag = true;
		int dx,dy;
		dx = i - 1;
		dy = j - 1;
		if(dx % a == 0 && dy % b == 0)
		{
			if(dx == 0 && dy == 0)
				ans = 0;
			else if(dx == 0 && 1 + a > n);
			else if(dy == 0 && 1 + b > m);
			else
			{
				int t1 = dx / a;
				int t2 = dy / b;
				if(t1 % 2 == t2 % 2)
				{
					ans = min(ans,max(t1,t2));
				}
			}
		}
		dx = i - 1;
		dy = m - j;
		if(dx % a == 0 && dy % b == 0)
		{
			if(dx == 0 && dy == 0)
				ans = 0;
			else if(dx == 0 && 1 + a > n);
			else if(dy == 0 && m - b < 1);
			else
			{
				int t1 = dx / a;
				int t2 = dy / b;
				if(t1 % 2 == t2 % 2)
					ans = min(ans,max(t1,t2));
			}
		}
		dx = n - i;
		dy = j - 1;
		if(dx % a == 0 && dy % b == 0)
		{
			if(dx == 0 && dy == 0)
				ans = 0;
			else if(dx == 0 && n - a < 1);
			else if(dy == 0 && 1 + b > m);
			else
			{
				int t1 = dx/a;
				int t2 = dy/b;
				if(t1 % 2 == t2 % 2)
					ans = min(ans,max(t1,t2));
			}
		}
		dx = n - i;
		dy = m - j;
		if(dx % a == 0 && dy % b == 0)
		{
			if(dx == 0 && dy == 0)
				ans = 0;
			else if(dx == 0 && n - a < 1);
			else if(dy == 0 && m - b < 1);
			else
			{
				int t1 = dx/a;
				int t2 = dy/b;
				if(t1 % 2 == t2 % 2)
					ans = min(ans,max(t1,t2));
			}
		}
		if(ans == INF)
			printf("Poor Inna and pony!\n");
		else cout<<ans<<endl;
	}
    return 0;
}
