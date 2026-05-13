#include<bits/stdc++.h>
using namespace std;
long long dp[1001][1001]={0};
long long item[1001][3];
int main()
{
	//输入数据+初始化
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int v,w;
		cin>>v>>w;
		//w重量，v价值
		item[i][1]=w;
		item[i][2]=v;
		dp[i][0]=0;
	}
	for(int i=1;i<=m;i++)dp[0][i]=0;
	
	//
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>=item[i][2]) dp[i][j]=max(dp[i-1][j-item[i][2]]+item[i][1],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][m];
 	return 0;
}
