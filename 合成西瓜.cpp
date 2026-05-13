#include<bits/stdc++.h>
using namespace std;
long long ans[1000001];
long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1)res=res*a%998244353;
		a=a*a%998244353;
		b>>=1;
	}
	return res%998244353;
}
long long solve(long long x,long long y){
	long long d=x-y;
	if(x<=y)return 1;
	long long ans=(qpow(2,d-1)%998244353)*(y+1)%998244353;
	return ans%998244353;
}
int main()
{
	
	long long t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		long long a=solve(x,y);
		ans[i]=(a);
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
 	return 0;
}
