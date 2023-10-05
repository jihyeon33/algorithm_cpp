#include<iostream>
using namespace std;
//Á¤´ä
int vect[8];
int bucket[10] = { 0 };
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> vect[i];
	
	}
	for (int i = 0; i < 8; i++) {
		int idx = vect[i];
		bucket[idx]++;
	}
	for (int i = 0; i < 10; i++) {
		if (bucket[i] != 0) {
			int cnt = bucket[i];
			for (int j = 0; j < cnt; j++) {
				cout << i << " ";
			}
		}
	}
}
