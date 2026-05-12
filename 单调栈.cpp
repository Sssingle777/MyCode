#include <iostream>
#include<vector>
using namespace std;
class arrstack {
private:
	vector<int> data;
public:
	arrstack() {}
	bool isEmpty() {
		return data.empty();
	}
	int getSize() {
		return int(data.size());
	}
	void push(int val) {
		data.push_back(val);
	}
	void pop() {
		if (!isEmpty()) {
			data.pop_back();
		}
	}
	int getTop() {
		return data.back();
	}
};
int main() {
		int n;
		cin >> n;
		vector<int> arr(n + 2, 0);

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		arrstack stk;
		stk.push(0);
		int ans = 0;
		for (int i = 1; i <= n + 1; i++) {
			while (!stk.isEmpty() && arr[i] < arr[stk.getTop()]) {
				int h = arr[stk.getTop()];
				stk.pop();
				int w = i - stk.getTop() - 1;
				int sum = h * w;
				if (sum > ans)ans = sum;
			}
			stk.push(i);

		}
		cout << ans;
	

}
/*
* 6
2 1 5 6 2 3
*/