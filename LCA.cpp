#include <iostream>
#include<vector>
using namespace std;
int fa[1000001][20], depth[1000001];
void build(vector<vector<int>>&tree,int x) {
	for (int i : tree[x]) {
		if (i == fa[x][0])continue;
		fa[i][0] = x;
		depth[i] = depth[x] + 1;
		for (int k = 1; k < 20; k++) {
			fa[i][k] = fa[fa[i][k - 1]][k - 1];
		}
		build(tree, i);
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);
	for (int k = 19; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}
	if (a == b)return a;
	for (int k = 19; k >=0; k--) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}
int main() {
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<int>> tree(n+1);
	vector<int> ans;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	fa[s][0] = 0;
	depth[s] = 1;
	build(tree, s);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ans.push_back(lca(a, b));
	}
	for (int i : ans)cout << i<<endl;
}