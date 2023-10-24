#include <iostream>
#include <vector>
using namespace std;
//정답 성공!!
int N;
int K;
vector<int> vec;
vector<int> rslt;
void del(int idx) {
    if (vec.size() == 0) {
        return;
    }
    if (idx > vec.size() - 1) {
        while (idx > vec.size() - 1) {
            idx = idx - vec.size();
        }
    }
    rslt.push_back(vec[idx]);
    vec.erase(vec.begin() + idx);
    int next = idx + K - 1;
    del(next);
    return;

}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        vec.push_back(i + 1);
    }
    del(K - 1);
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << rslt[i];
        if (i < rslt.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}
