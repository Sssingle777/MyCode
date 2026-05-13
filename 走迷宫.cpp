#include<bits/stdc++.h>
using namespace std;
int board[101][101]={0};
int vis[101][101]={-1};
int stpx[4]={1,0,-1,0};
int stpy[4]={0,1,0,-1};
struct point{
	int x;
	int y;
	int step;
	point(int a,int b,int c){
		x=a;
		y=b;
		step=c;
	}
};
int bfs(int xs,int ys,int xf,int yf){
	queue<point> q;
	point start(xs,ys,0);
	q.push(start);
	vis[xs][ys]=1;
	while(!q.empty()){
		point cur=q.front();
		if(cur.x==xf&&cur.y==yf)return cur.step;//
		q.pop();
		for(int i=0;i<4;i++){
			int x=cur.x+stpx[i],y=cur.y+stpy[i];


			if(board[x][y]==1&&vis[x][y]!=1){
				vis[x][y]=1;
				int cnt=cur.step+1;
				point tmp(x,y,cnt);
				q.push(tmp);	
			}
		}
	}
	
	return -1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			cin>>board[i][j];
			vis[i][j]=0;
		}
	}
	
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int ans=bfs(x1,y1,x2,y2);
	cout<<ans;
 	return 0;
}
