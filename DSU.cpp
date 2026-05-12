#include<iostream>
#include<vector>
using namespace std;
int fa[501];
int Find(int x) {
	if(fa[x] != x) {
		fa[x] = Find(fa[x]);
	}
	return fa[x];
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		fa[Find(x)] = Find(y);
	}
	for (int i = 1; i <= n; i++) {
		if (i == Find(i)) {
			for (int j = 1; j <= n; j++) {
				if (i == Find(j))cout << j << " ";
			}
			cout << "\n";
		}
	}

}