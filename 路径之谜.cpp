#include<bits/stdc++.h>
using namespace std;
int cas[21][21]={0};
int boa[21][21];
int nor[21],we[21];
int n;
bool ans=0;
struct ver{
	int x;
	int y;
	ver(int a,int b){
		x=a;
		y=b;
	}
};
vector<ver> cnt;
bool right(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+nor[i]+we[i];
	}
	return sum==0;
}
void dfs(int x,int y){
	if(x>n||x<1||y>n||y<1||nor[x]==0||we[y]==0||cas[x][y]==1)return;
	if(ans)return;
	cas[x][y]=1;
	ver tmp(x,y);
	cnt.push_back(tmp);
	nor[y]--;
	we[x]--;
	if(x==n&&y==n&&right()){
		ans=1;
		return;
	}
	dfs(x+1,y);
	if(ans)return;
	dfs(x,y+1);
	if(ans)return;
	dfs(x-1,y);
	if(ans)return;
	dfs(x,y-1);
	if(ans)return;

	nor[y]++;
	we[x]++;
	if(!cnt.empty())cnt.pop_back();
	cas[x][y]=0;
	return;
}
int main()
{

	cin>>n;
	for(int i=1;i<=n;i++)cin>>nor[i];
	for(int i=1;i<=n;i++)cin>>we[i];
	dfs(1,1);
	int nn=cnt.size();
	for(int i=0;i<nn;i++){
		int s,t;
		s=cnt[i].x-1;
		t=cnt[i].y-1;
		cout<<s+n*t<<" ";
	}
 	return 0;
}
