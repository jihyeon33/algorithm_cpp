#include<iostream>
using namespace std;
//Á¤´ä
int paan[4][3] = {
	1,5,3,
	4,5,5,
	3,3,5,
	4,6,2
};
int a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (a <= paan[i][j] && paan[i][j] <= b) {
				paan[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (paan[i][j] == 0) {
				cout << "#" << " ";
			}else {
				cout << paan[i][j] << " ";
			}
		}
		cout << endl;
	}
}