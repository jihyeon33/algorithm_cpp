#include<iostream>
#include<vector>
using namespace std;
//����1167 Ʈ���� ����  //���2 //����� �����ε� ������..
vector<int> rslt;
struct node {
	int val;
	vector<pair<node*, int>> siblings;
};

void laststep(node* nownode ,int total) {
	for (int i = 0; i < nownode->siblings.size(); i++) {
		laststep(nownode->siblings[i].first, total + nownode->siblings[i].second);
	}
	//�ڽĳ����� ������ total ����ְ� ����
	rslt.push_back(total);
	return;
}
node* findnode(node* nownode, int val) {
	if (nownode->val == val) return nownode;
	//�ڽĳ���Ž��
	for (int i = 0; i < nownode->siblings.size(); i++) {
		pair<node*, int> siblnode = nownode->siblings[i];
		node* returnode = findnode(siblnode.first, val);
		if (returnode != NULL) return returnode;
	}
	return NULL;
}
node* createnode(int val) {
	node* newnode = new node();
	newnode->val = val;
	newnode->siblings= vector<pair<node*, int>>();
	return newnode;
}
void insertnode(node* parentnode, int sibl, int w) {
	node* siblnode = createnode(sibl);
	pair<node*, int> siblnodew;
	siblnodew.first = siblnode;
	siblnodew.second = w;
	parentnode->siblings.push_back(siblnodew);
}
int main() {
	int V;
	cin >> V;
	//��Ʈ ����
	node* root = createnode(1);
	for (int i = 0; i < V; i++) {
		int a; 
		cin >> a;
		while (true)
		{
			int b;
			cin >> b;
			if (b == -1) break;
			int w;
			cin >> w;
			// a,b find
			node* anode = findnode(root, a);
			node* bnode = findnode(root, b);
			//�Ѵ� ������ pass
			//�ϳ��� ������ insert
			if (anode != NULL &&bnode ==NULL) {
				insertnode(anode, b, w);
			}
			else if (anode == NULL && bnode != NULL) {
				insertnode(bnode, a, w);
			}
			//�Ѵ� ������ �������
		}

	}
	//���� ���
	laststep(root, 0);
	int r = 0;
	for (int i = 0; i < rslt.size(); i++) {
		if (r < rslt[i]) r = rslt[i];
	}
	cout << r;
	return 0;
}