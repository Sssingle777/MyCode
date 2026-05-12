#include <iostream>
using namespace std;
void hanoi(int n,char s,char m,char f) {
	if (n == 1) {
		cout << s << "->" << f << " ";
		return;
	}
	hanoi(n - 1, s, f, m);
	cout << s << "->" << f << " ";
	hanoi(n - 1, m, s, f);
}
int main() {
	int n;
	char a = 'A', b = 'B', c = 'C';
	cin >> n;
	hanoi(n,a,b,c);
}