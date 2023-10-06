#include<iostream>
#include<cstring>
using namespace std;
//Á¤´ä
int y = 5;
int x=5;
void go(char str[10]) 
{
	if (strcmp(str, "up") == 0) {
		y = y - 1;
	}else if (strcmp(str, "down") == 0) {
		y = y + 1;
	}else if (strcmp(str, "left") == 0) {
		x = x - 1;
	}else if (strcmp(str, "right") == 0) {
		x = x + 1;
	}else if (strcmp(str, "click") == 0) {
		cout << y << "," << x<<endl;
	}
}
int main() 
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char str[10];
		cin >> str;
		go(str);
	}
}