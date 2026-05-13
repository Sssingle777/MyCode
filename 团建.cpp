#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
vector<int> t1,t2;
vector<vector<int>> e1,e2;
vector<vector<int>> g1,g2;
bool cmp1(int a,int b){
	return t1[a]<t1[b];
}
bool cmp2(int a,int b){
	return t2[a]<t2[b];
}
void pre(){
	for(int i=1;i<=n;i++){
		sort(e1[i].begin(),e1[i].end(),cmp1);
	}
	for(int i=1;i<=m;i++){
		sort(e2[i].begin(),e2[i].end(),cmp2);
	}
}
void build(int n,const vector<vector<int>>&g,vector<vector<int>>&e){
	vector<int>fa (n+1,0);
	queue<int>q;
	q.push(1);
	fa[1]=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(v==fa[u])continue;
			fa[v]=u;
			e[u].push_back(v);
			q.push(v);
		}
	}
}
void dfs(int p,int q,int dep){
	if(t1[p]!=t2[q])return;
	ans=max(ans,dep);
	int i=0,j=0;
	int n1=e1[p].size(),n2=e2[q].size();
	while(i<n1&&j<n2){
		int v1=t1[e1[p][i]];
		int v2=t2[e2[q][j]];
		if(v1<v2){
			i++;
		}else if(v1>v2){
			j++;
		}
		else{
			dfs(e1[p][i],e2[q][j],dep+1);
			i++;
			j++;
		}
	}
}	

int main()
{
	//ÊäÈë
	cin>>n>>m;
	t1.resize(n+1);
	t2.resize(m+1);	
	e1.resize(n+1);
	e2.resize(m+1);
	g1.resize(n+1);
	g2.resize(m+1);
	for(int i=1;i<=n;i++){
		cin>>t1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t2[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g1[x].push_back(y);
		g1[y].push_back(x);
	}
	for(int i=1;i<m;i++){
		int x,y;
		cin>>x>>y;
		g2[x].push_back(y);
		g2[y].push_back(x);
	}
	
	build(n,g1,e1);
	build(m,g2,e2);
	pre();
	dfs(1,1,1);
	cout<<ans;
 	return 0;
}
