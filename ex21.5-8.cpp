#include<iostream>
using namespace std;
//Á¤´ä
char stage[5][3] = {
	'_','_','_',
	'_','_','_',
	'A','T','K',
	'_','_','_',
	'_','_','_'
};
int x, y;
void search(char ch) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (ch == stage[i][j]) {
				x = i;
				y = j;
				break;
			}
		}
	}
}
void go(char ch, string order) {
	search(ch);

	if (order == "UP") {
		stage[x][y] = '_';
		stage[x-1][y] = ch;
	}
	else if (order == "DOWN") {
		stage[x][y] = '_';
		stage[x+1][y] = ch;
	}
	else if (order == "LEFT") {
		stage[x][y] = '_';
		stage[x][y-1] = ch;
	}
	else if (order == "RIGHT") {
		stage[x][y] = '_';
		stage[x][y + 1] = ch;
	}

}
int main() {
	for (int i = 0; i < 7; i++) {
		char ch;
		string order;
		cin >> ch >> order;
		go(ch, order);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<stage[i][j];
		}
		cout << endl;
	}
}