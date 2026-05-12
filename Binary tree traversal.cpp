#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct Tnode {
	int val;
	Tnode* left;
	Tnode* right;
	Tnode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};
void freetree(Tnode* root) {
	if (root == nullptr)return;
	freetree(root->left);
	freetree(root->right);
	delete root;
}
class Tree {
private:
	Tnode* root;
	void preOrder(vector<int> &vec,Tnode* node) {
		if (node == nullptr) return;
		vec.push_back(node->val);
		preOrder(vec, node->left);
		preOrder(vec, node->right);
	}
	void inOrder(vector<int>& vec, Tnode* node) {
		if (node == nullptr)return;
		inOrder(vec, node->left);
		vec.push_back(node->val);
		inOrder(vec, node->right);
	}
	void postOrder(vector<int>& vec, Tnode* node) {
		if (node == nullptr)return;
		postOrder(vec, node->left);
		postOrder(vec, node->right);
		vec.push_back(node->val);
	}
	int depth_lo(Tnode*Node) {
		if (Node == nullptr)return 0;
		int h = 0;
		stack<pair<Tnode*,int>> stk;
		stk.push({ Node,1 });
		while (!stk.empty()) {
			auto cur = stk.top();
			stk.pop();
			Tnode* node = cur.first;
			int dep = cur.second;
			h = max(h, dep);
			if (node->left != nullptr) {
				stk.push({ node->left,dep+ 1 });
			}
			if(node->right!=nullptr){
				stk.push({ node->right,dep + 1 });
			}
		}
		return h;
	}
	int depth_re(Tnode *node) {
		if (node == nullptr) return 0;
		return max(depth_re(node->left), depth_re(node->right)) + 1;
	}

public:
	Tree() {
		root = nullptr;
	}
	~Tree() {
		freetree(root);
	}
	void setRoot(Tnode* r) {
		root = r;
	}
	vector<int>preOrder() {
		vector<int> vec;
		preOrder(vec, root);
		return vec;
	}
	vector<int>inOrder() {
		vector<int> vec;
		inOrder(vec, root);
		return vec;
	}
	vector<int>postOrder() {
		vector<int> vec;
		postOrder(vec, root);
		return vec;
	}
	int depth_re() {
		return depth_re(root);
	}
	int depth_lo() {
		return depth_lo(root);
	}
	int bfs(Tnode* node) {
		if (node == nullptr)return 0;
		queue<Tnode*> q;
		q.push(node);
		int cnt = 0;
		while (!q.empty()) {
			Tnode* tmp = q.front();
			q.pop();
			if (tmp->val == 1)cnt++;
			if (tmp->left != nullptr) {
				q.push(tmp->left);
			}
			if (tmp->right != nullptr) {
				q.push(tmp->right);;
			}
		}
		return cnt;
	}
	int dfs(Tnode* node) {
		if (node == nullptr) return 0;
		int cnt = 0;
		if (node->val == 1) cnt++;
		cnt += dfs(node->left);
		cnt += dfs(node-> right);
		return cnt;
	}
};

int main() {
	Tree t;

	Tnode* root = new Tnode(1);
	root->left = new Tnode(2);
	root->right = new Tnode(1);
	root->left->left = new Tnode(4);
	root->left->right = new Tnode(5);
	root->right->left = new Tnode(1);

	t.setRoot(root);

	vector<int> pre = t.preOrder();
	vector<int> in = t.inOrder();
	vector<int> post = t.postOrder();
	for (int i = 0; i < 6; i++) {
		cout << pre[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << in[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << post[i] << " ";
	}
	cout << endl;
	cout << t.depth_lo()<<" "<<t.depth_re()<<endl;
	cout << t.bfs(root)<<" "<<t.dfs(root);

}