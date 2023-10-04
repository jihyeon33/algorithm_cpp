#include<iostream>
using namespace std;
int n;
void go(int next) {
	if (next == 0) {
		return;
	}
	go(next / 2);
	cout << next << " ";
}
int main() {
	cin >> n;
	go(n);
	return 0;
}