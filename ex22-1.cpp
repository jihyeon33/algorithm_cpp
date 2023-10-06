#include<iostream>
using namespace std;
//Á¤´ä
char list[3] = { 'A','B','C' };
char ch;
int lev=0;
char path[3] = { 0 };
void go() {
	if (lev == 2) {
		cout << path << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		ch = list[i];
		path[lev] = ch;
		lev++;
		go();
		path[lev] = 0;
		lev--;
	}
}
int main()
{
	go();
}