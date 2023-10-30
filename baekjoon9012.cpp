#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//백준 9012 괄호. 정답 성공!!
char inputs[51];
stack<char> stk;
vector<string> rslt;
bool isVPS() {
	bool flag = false;
	for (int i = 0; i < 51; i++) {
		if (inputs[i] == 0) break;
		if (inputs[i] == ')') {
			if (!stk.empty() && stk.top() == '(') {
				stk.pop();  // ()짝을 이루면 pop
			}
			else
			{
				stk.push(')');
			}
		}
		else {
			stk.push('(');
		}
	}
	//만약 스택이 비어있으면 vps , 안비어있으면 vps아님
	if (stk.empty() == true) flag = true;

	//스택, 입력값 다시 초기화하기
	for (int i = 0; i < 51; i++) {
		inputs[i] = 0;
	}
	while (!stk.empty()) stk.pop();

	return flag;
}
int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		// 문자열 입력받을 때마다 isVPS 함수 호출하여 vps인지 판단
		cin >> inputs;
		if (isVPS() == true) rslt.push_back("YES");
		else rslt.push_back("NO");
	}
	//결과 출력하기
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << endl;
	}
	return 0;
}