#include<iostream>
using namespace std;
char str[5] = { 0 };
void print(int idx) {
	if (idx == 5) {
		cout << endl;
		return;
	}
	cout << str[idx];
	print(idx + 1);
	cout << str[idx];
}
int main() {
	cin >> str;
	print(0);
	return 0;
}