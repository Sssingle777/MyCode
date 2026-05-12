#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> cmp_next(string s) {
	vector<int> next(s.size());
	next[0] = -1;
	int j = 0, k = -1;
	while (j < s.size()-1) {
		if(k==-1||s[j]==s[k]){
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}
vector<int> cmp_nex_pro(string s) {
	vector<int> next(s.size());
	next[0] = -1;
	int j = 0, k = -1;
	while (j < s.size() - 1) {
		if (k == -1 || s[j] == s[k]) {
			j++;
			k++;
			if (s[j] != s[k])
				next[j] = k;
			else next[j] = next[k];
		}
		else
			k = next[k];
	}
	return next;
}

int KMP(string s, string t,vector<int> next) {
	int i = 0,j=0;
	int n = s.size(), m = t.size();
	while(j<m&&i<n){
		if (j==-1||s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == t.size())return i - j;
	return -1;
}
int main() {
	string s,t;
	cin >> s>>t;
	vector<int> next = cmp_next(t);
	for (int i = 0; i < t.size(); i++) {
		cout << next[i]<<" ";
	}
	cout << endl;
	
	vector<int> next_pro = cmp_nex_pro(t);
	for (int i = 0; i < t.size(); i++) {
		cout << next_pro[i] << " ";
	}
	cout << endl;
	
	int ans = KMP(s, t, next);
	cout << ans;
	return 0;
}