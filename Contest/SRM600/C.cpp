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

int F[100];
int find(int x)
{
	if(F[x] == -1)return x;
	return F[x] = find(F[x]);
}
class PalindromeMatrixDiv2
{
	public:
	int minChange(vector <string> A, int rowCount, int columnCount)
	{
		int n = A.size();
		int m = A[0].length();
		int ans = n*m;
		for(int s1 = 0;s1 < (1<<n);s1++)
			for(int s2 = 0;s2 < (1<<m);s2++)
			{
				int cnt1 = 0;
				for(int i = 0;i < n;i++)
					if(s1 & (1<<i))
						cnt1++;
				if(cnt1 < rowCount)continue;
				int cnt2 = 0;
				for(int i = 0;i < m;i++)
					if(s2 & (1<<i))
						cnt2++;
				if(cnt2 < columnCount)continue;
				memset(F,-1,sizeof(F));
				for(int i = 0;i < n;i++)
					if(s1 & (1<<i))
					{
						for(int j = 0;j < m/2;j++)
						{
							int t1 = find(m * i + j);
							int t2 = find(m * i + m - 1 - j);
							if(t1 != t2)
								F[t1] = t2;
						}
					}
				for(int j = 0;j < m;j++)
					if(s2 & (1<<j))
					{
						for(int i = 0;i < n/2;i++)
						{
							int t1 = find(m * i + j);
							int t2 = find(m * (n - 1 - i) + j);
							if(t1 != t2)
								F[t1] = t2;
						}
					}
				int ret = 0;
				for(int i = 0;i < n*m;i++)
					if(find(i) == i)
					{
						int tp0 = 0, tp1 = 0;
						for(int j = 0;j < n*m;j++)
							if(find(j) == find(i))
							{
								int x = j / m;
								int y = j % m;
								if(A[x][y] == '0')
									tp0++;
								else tp1++;
							}
						ret += min(tp0,tp1);
					}
				ans = min(ret,ans);
			}
		return ans;
	}
};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    vector<string>A;
	A.push_back("0000");
	A.push_back("1000");
	A.push_back("1100");
	A.push_back("1110");
 PalindromeMatrixDiv2 test;
 test.minChange(A,3,2);
	
    return 0;
}
