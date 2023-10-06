#include<iostream>
using namespace std;
//Á¤´ä
int branch, level;
int cnt = 1;
void recur(int lev) {
	if (lev == level) {
		return;
	}
	for (int i = 0; i < branch; i++) {
		cnt++;
		recur(lev + 1);
	}
}
int main()
{
	cin >> branch >> level;
	recur(0);
	cout << cnt;
}