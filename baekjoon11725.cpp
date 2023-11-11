#include <iostream>
#include<vector>
using namespace std;
//���� 11725 Ʈ���� �θ� ã��  //����� �����ε� ���� ü������ ��Ÿ�� ���� (AccessNullPointer) ����Ʈ���� �����ϰ� Ǯ� �׷���, �����ʿ�.
vector<int> rslt;
struct node {
	int val;
	node* left;
	node* right;
};
node* isexist(node* nownode, int val) {
	if (nownode->val == val) return nownode;
	node* left = nownode->left;
	if (left != NULL) {
		node* nd= isexist(left, val);
		if(nd!=NULL) return nd;
	}
	node* right = nownode->right;
	if (right != NULL) {
		node* nd = isexist(right, val);
		if (nd != NULL) return nd;
	}
	return NULL;
}
node* createnode(int value) {
	node* newnode = new node();
	newnode->val = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void insertnode(node* parentnode, int value) {
	node* siblingnode = createnode(value);
	if (parentnode->left == NULL) {
		parentnode->left = siblingnode;
	}
	else
	{
		parentnode->right = siblingnode;
	}
}
void laststep(node* now) {
	int parent = now->val;
	if (now->left != NULL) {
		int sibling = now->left->val;
		rslt[sibling] = parent;
		laststep(now->left);
	}
	if(now->right!= NULL){
		int sibling = now->right->val;
		rslt[sibling] = parent;
		laststep(now->right);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		rslt.push_back(0);
	}
	node* root = createnode(1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (isexist(root, a) != NULL) {  //a�� ������ 
			node* parentnode = isexist(root, a);
			insertnode(parentnode, b);   //a�� �θ���� �Ͽ� b�� �ڽĳ��� �μ�Ʈ
		}
		else {  //b�� ������
			node* parentnode = isexist(root, b);
			insertnode(parentnode, a); //b�� �θ���� �Ͽ� a�� �ڽĳ��� �μ�Ʈ
		}
	}
	laststep(root);
	//����ϱ�
	for (int i = 2; i <= n; i++) {
		cout << rslt[i] << endl;
	}

	return 0;
}