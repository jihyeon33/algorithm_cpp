#include <iostream>
#include <vector>
using namespace std;
//백준2346 풍선 떠뜨리기 _링크드리스트  //출력정상인데 오답..
vector<int> balloons;
vector<int>indexs;
vector<int> rslt;
bool isPlus(int x) {
	int y = x * (-1);
	if (y > 0) return false; //음수
	return true; //양수
}
void pop(int nowidx) {
	if (balloons.size() == 1) { //남은 풍선이 1개인 순간 나머지 풍선 터뜨리고 바로 리턴
		rslt.push_back(indexs[0]);
		balloons.erase(balloons.begin() + 0);
		indexs.erase(indexs.begin() + 0);
		return;
	}
	int index = indexs[nowidx];
	rslt.push_back(index);
	int step = balloons[nowidx];
	balloons.erase(balloons.begin() + nowidx);
	indexs.erase(indexs.begin() + nowidx);
	int nextidx = nowidx;
	if (step ==0) {
	}else if (isPlus(step) == true) {
		for (int i = 0; i < step-1; i++) { //오른쪽으로 이동
			nextidx++;
			if (nextidx > balloons.size() - 1) nextidx = 0;
		}
	}
	else {
		step = step * (-1);
		for (int i = 0; i < step; i++) {  //왼쪽으로 이동
			nextidx--;
			if (nextidx < 0) nextidx = balloons.size() - 1;
		}
	}
	pop(nextidx);
	return;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		balloons.push_back(num);
		indexs.push_back(i + 1);
	}
	pop(0);
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i];
		if (i < rslt.size() - 1) cout << " ";
	}
	return 0;

}