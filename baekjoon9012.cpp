#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//���� 9012 ��ȣ. ���� ����!!
char inputs[51];
stack<char> stk;
vector<string> rslt;
bool isVPS() {
	bool flag = false;
	for (int i = 0; i < 51; i++) {
		if (inputs[i] == 0) break;
		if (inputs[i] == ')') {
			if (!stk.empty() && stk.top() == '(') {
				stk.pop();  // ()¦�� �̷�� pop
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
	//���� ������ ��������� vps , �Ⱥ�������� vps�ƴ�
	if (stk.empty() == true) flag = true;

	//����, �Է°� �ٽ� �ʱ�ȭ�ϱ�
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
		// ���ڿ� �Է¹��� ������ isVPS �Լ� ȣ���Ͽ� vps���� �Ǵ�
		cin >> inputs;
		if (isVPS() == true) rslt.push_back("YES");
		else rslt.push_back("NO");
	}
	//��� ����ϱ�
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << endl;
	}
	return 0;
}