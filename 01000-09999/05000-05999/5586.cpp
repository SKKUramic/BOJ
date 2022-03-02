// 5586 JOI와 IOI
// https://www.acmicpc.net/problem/5586
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int len, JOI = 0, IOI = 0;
    string s;
    cin >> s;
    len = s.length();
    for (int i = 0; i < len - 2; i++){
        if (s[i + 2] == 'I' && s[i + 1] == 'O'){
            if (s[i] == 'J'){
                JOI++;
            }
            else if (s[i] == 'I'){
                IOI++;
            }
        }
    }
    cout << JOI << '\n' << IOI;
}