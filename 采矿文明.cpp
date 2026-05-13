#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long sp[100001];
long long val[100001];
int main()
{
	cin>>n>>m>>k;
	sp[1]=0;
	val[0]=0;
	for(long long i=2;i<=n;i++){
		long long x;
		cin>>x;
		sp[i]=sp[i-1]+x;//到第i个矿井的花费
	}
	for(long long i=1;i<=n;i++){
		cin>>val[i];
	}
	long long ans=0;

	priority_queue<long long,vector<long long>,greater<long long>> q;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		if(m<sp[i])break;
		long long tmp=val[i];
		if(q.size()<k){
			 q.push(tmp);
			 sum+=tmp;
			ans=max(ans,min(sum,m-sp[i]));
		}
		else if(tmp>q.top()){
			sum-=q.top();
			q.pop();
			q.push(tmp);
			sum+=tmp;
			ans=max(ans,min(sum,m-sp[i]));
		}
	}
	cout<<ans;
	
 	return 0;
}
