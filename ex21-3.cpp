#include<iostream>
using namespace std;
//Á¤´ä
int level, branch;
void recursive(int lev) {
	if (lev == level) {
		return;
	}
	for (int i = 0; i < branch; i++) {
		recursive(lev + 1);
	}
	return;
}
int main() {
	cin >> level >> branch;
	recursive(0);
	return 0;
}