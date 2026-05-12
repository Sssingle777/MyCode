#include <iostream>
#include<vector>
using namespace std;
class queue {
private:
	int* nums;
	int front;
	int queSize;
	int queCapacity;
public:
	queue(int capacity) {
		nums = new int[capacity];
		front = 0;
		queSize = 0;
		queCapacity = capacity;
	}
	~queue() {
		delete[] nums;
	}

	int getSize() {
		return queSize;
	}
	bool isEmpty() {
		return queSize == 0;
	}
	int peek_first() {
		return nums[front];
	}
	int peek_last() {
		return nums[(front+queSize-1+queCapacity)%queCapacity];
	}
	void push(int num) {
		if (queSize == queCapacity) return;
		int rear = (front + queSize) % queCapacity;
		nums[rear] = num;
		queSize++;
	}
	int pop_first() {
		int num = peek_first();
		front = (front + 1)%queCapacity;
		queSize--;
		return num;
	}
	int pop_last() {
		int num = peek_last();
		queSize--;
		return num;
	}
};

int main() {
	int n, k;
	cin >> n >> k;	
	queue queue1(n);
	vector<int> nums,ans;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
		if (!queue1.isEmpty() && i - queue1.peek_first() >= k)
			queue1.pop_first();
		while (!queue1.isEmpty() && nums[queue1.peek_last()] < x) {
			queue1.pop_last();
		}
		queue1.push(i);
		if (i >= k - 1)ans.push_back(nums[queue1.peek_first()]);
	}
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}
/*
8 3
1 3 -1 -3 5 3 6 7
*/