#include<iostream>
using namespace std;
//Á¤´ä
int level;
char vect[4] = {'B','G','T','K'};
char path[3] = { 0 };
void recursive(int lev) {
	if (lev == level) {
		cout << path << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		path[lev] = vect[i];
		recursive(lev + 1);
		path[lev+1] = 0;
	}

}
int main() {
	cin >> level;
	recursive(0);
}