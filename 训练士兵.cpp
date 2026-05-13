#include<bits/stdc++.h>
using namespace std;
struct soldier{
	long long cost;
	long long times;
	soldier(long long x,long long y){
		cost=x;
		times=y;
	}
};
bool cmp(soldier a,soldier b){
	return a.times<b.times;
}
long long sum_cmp(vector<soldier> &arr,int i,long long m){
	long long sum=0;
	int n=arr.size();
	for(int j=i;j<n;j++){
		sum+=arr[j].cost*m;
	}
	return sum;
}
long long sum_cost(vector<soldier> &arr,int i){
	long long sum=0;
	int n=arr.size();
	for(int j=i;j<n;j++){
		sum+=arr[j].times*arr[j].cost;
	}
	return sum;
}
int main()
{
	long long n,S,sump=0;
	cin>>n>>S;
	vector<soldier> arr;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		soldier tmp(x,y);
		arr.push_back(tmp);
		sump+=x;
	}
	sort(arr.begin(),arr.end(),cmp);
	long long ans=0;
	int i=0,pre=0;
	while(i<n){
		long long cur=arr[i].times;
		long long d=cur-pre;
		ans+=d*min(sump,S);

		while(i<n&&arr[i].times==cur)	{
			sump-=arr[i].cost;
			i++;	
		}
		pre=cur;
	}
	
	cout<<ans;
	
 	return 0;
}
