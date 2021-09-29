// 5555 반지
// https://www.acmicpc.net/problem/5555
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, ans = 0;
    string s, str;
    bool str_same;
    cin >> str;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> s;
        for (int a = 0; a < s.length(); a++){
            str_same = true;
            for (int b = 0; b < str.length(); b++){
                if (str[b] != s[(a + b) % 10]){
                    str_same = false;
                    break;
                }
            }
            if (str_same == true){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}