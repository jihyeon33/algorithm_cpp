#include<iostream>
using namespace std;
//Á¤´ä
char str[20] = { 0 };
void print(int lev) {
	if (lev == 1) {
		cout << 1 <<" ";
		return;
	}
	cout << lev << " ";
	print(lev - 1);
	cout << lev << " ";
}
int main() {
	cin >> str;
	int strlen;
	for (int i = 0; i < 20; i++) {
		if (str[i] == 0) {
			strlen = i;
			break;
		}
	}
	print(strlen);
	return 0;

}