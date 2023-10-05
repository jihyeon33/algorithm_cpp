#include<iostream>
using namespace std;
//정답아님
int rslt = 0;
int cnt = 0;
int X, Y;
int directx[4] = { 1,-1,0,0 };
int directy[4] = { 0,0,-1,1 };
int paan[7][7] = {
	0,0,0,0,0,0,0,
	0,0,1,0,1,0,0,
	0,1,2,0,2,1,0,
	0,0,1,2,1,0,0,
	0,0,2,1,0,1,0,
	0,1,1,0,0,0,0,
	0,0,0,0,0,0,0
};
int path[3] = { 0 };
void go(int lev,int x,int y) {
	if (lev == 3 || x > 6 || y > 6) {
		for (int i = 0; i < 3; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		//path 가 1,2,1 이면 cnt++
		if (path[0]==1 && path[1]==2 && path[2]==1) cnt++;
		for (int i = 0; i < 3; i++) {
			path[i] = 0;
		}
		return;
	}
	if (lev == 0) {
		if (cnt == 3) rslt++;
		cnt = 0;
	}
	path[lev] = paan[x][y];
	for (int i = 0; i < 4; i++) {
		int nextx = x + directx[i];
		int nexty = y + directy[i];
		go(lev + 1, nextx, nexty);
	}
}
int main() {
	cin >> X >>Y;
	paan[X][Y] = 1;
	go(0,X,Y);
	cout << rslt;
	return 0;

}