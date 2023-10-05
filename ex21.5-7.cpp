#include<iostream>
using namespace std;
//Á¤´ä
int cnt = 0;
int X,Y;
int directx[4] = {1,-1,0,0};
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
bool check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nextx = x + directx[i];
		int nexty = y + directy[i];
		if (nextx > 6 || nexty > 6 || paan[nextx][nexty] != 1) return false;
	}
	return true;
}
int main() {
	cin >> X >> Y;
	paan[X][Y] = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = X+ directx[i];
		int nexty = Y+ directy[i];
		if (nextx <= 6 && nexty <= 6 && paan[nextx][nexty] == 2) {
			bool flag = check(nextx, nexty);
			if (flag == true) cnt++;
		}
	}
	cout << cnt;
	return 0;
}