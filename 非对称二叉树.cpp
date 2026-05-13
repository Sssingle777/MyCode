#include<bits/stdc++.h>
using namespace std;
long long dp[36][36]={0};
int main()
{
	int n,k;
	cin>>n>>k;
	dp[0][0]=1;
	//dp[1][1]=1;
//	dp[2][2]=2;
	for(int i=1;i<=n;i++){
		for(int l=0;l<i;l++){
			int r=i-1-l;
			for(int hl=0;hl<=l;hl++){
				for(int hr=0;hr<=r;hr++){
					int ma=max(hr,hl);
					int mi=min(hr,hl);
					if(ma>=k*mi){
						dp[i][ma+1]+=dp[l][hl]*dp[r][hr];
					}	
				}
				
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans+=dp[n][i];
	}
	cout<<ans;
 	return 0;
}
