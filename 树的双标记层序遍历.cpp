#include <iostream>
#include<queue>
#include<stack>
using namespace std;
struct node {
	int val, le=-1, ri=-1;
};
int main()
{
	int N;
	while (cin >> N) {
		node inp[501];
		node tree[501];
		for (int i = 1; i <= N; i++) {
			int x,l, r;
			cin >> x >> l >> r;
			tree[i].val = x;
			inp[i].val = x;
			inp[i].le = l;
			inp[i].ri = r;
		}
		stack<int> stk;
		for (int i = 1; i < N; i++) {
			if (inp[i].le == 0 && inp[i].ri == 0) {
				stk.push(i);
			}
			if (inp[i].le == 1 && inp[i].ri == 1&&!stk.empty()) {
				tree[stk.top()].ri = i + 1;
				stk.pop();
			}
			if (inp[i].le == 0)tree[i].le = i + 1;
			if (inp[i].le == 1 && inp[i].ri == 0)tree[i].ri = i + 1;
		}

		queue<int> qq;
		qq.push(1);
		bool first = 1;
		while (!qq.empty()) {
			int k = qq.front();
			qq.pop();
			if (!first)cout << " ";
			cout << tree[k].val;
			first = 0;
			int tmp = tree[k].le;
			while (tmp != -1) {
				qq.push(tmp);
				tmp = tree[tmp].ri;
			}
		}
		cout << "\n";
	}
	return 0;
}