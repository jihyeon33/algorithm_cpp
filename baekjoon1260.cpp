#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
//백준1260 DFS와 BFS  //정답!!
vector<vector<int>> gp;
vector<int> rslt;
vector<bool> visit;
void clear(int n) {
	//rslt, visit 클리어
	rslt.clear();
	visit.clear();
	for (int i = 0; i <= n; i++) {
		visit.push_back(false);
	}
}
void dfs(int v) {
	visit[v] = true;
	rslt.push_back(v);
	vector<int> nexts = gp[v];
	for (int i = 0; i < nexts.size(); i++) {
		int next = nexts[i];
		if (visit[next] == false) {
			dfs(next);
		}
	}
	return;
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int pop = q.front();
		if (visit[pop] == false) rslt.push_back(pop);
		visit[pop] = true;
		q.pop();
		for (int i = 0; i < gp[pop].size(); i++) {
			int next = gp[pop][i];
			if (visit[next] == false) q.push(next);
		}
	}
	return;
}
int main() {
	int N, M, V;
	cin >> N >> M >> V;
	//그래프 초기화
	for (int i = 0; i <= N; i++) {
		gp.push_back(vector<int>());
	}
	//입력받아 그래프 만들기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		gp[a].push_back(b);
		gp[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(gp[i].begin(), gp[i].end());
	}

	clear(N); //visit,rslt초기화
	dfs(V);
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << " ";
	}
	cout << endl;

	clear(N); //visit,rslt초기화
	bfs(V);
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << " ";
	}
	return 0;

}