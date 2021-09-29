// 4470 줄번호
// https://www.acmicpc.net/problem/4470
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string s;
    cin >> N;
    getline(cin, s);
    for (int n = 1; n <= N; n++){
        getline(cin, s);
        cout << n << ". " << s << '\n';
    }
}