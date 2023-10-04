#include<iostream>
using namespace std;
int a, b;
void go(int idx) {
	if (idx == b) {
		cout << b << " ";
		return;
	}
	cout << idx << " ";
	go(idx + 1);
	cout << idx << " ";
}
int main() {
	cin >> a >> b;
	go(a);
	return 0;
}