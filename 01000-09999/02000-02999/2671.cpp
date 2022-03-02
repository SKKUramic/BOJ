// 2671 잠수함식별
// https://www.acmicpc.net/problem/2671
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool valid = true;
    string s;
    int idx = 0, len;
    cin >> s;
    len = s.length();
    s.resize(250, 'X');
    while (1){
        if (idx >= len){
            break;
        }
        if (s[idx] == '0'){
            if (s[idx + 1] == '1'){
                idx += 2;
            }
            else if (s[idx + 1] == '0'){
                if (idx > 1 && s[idx - 1] == '1' && s[idx - 2] == '1'){
                    idx--;
                }
                else {
                    valid = false;
                    break;
                }
            }
            continue;
        }
        if (s[idx] == '1'){
            if (s[idx + 1] != '0' || s[idx + 2] != '0'){
                valid = false;
                break;
            }
            idx += 2;
            while (s[idx] == '0'){
                idx++;
            }
            if (idx >= len){
                valid = false;
                break;
            }
            while (s[idx] == '1'){
                idx++;
            }
        }
        else {
            valid = false;
            break;
        }
    }
    if (valid == true){
        cout << "SUBMARINE";
    }
    else {
        cout << "NOISE";
    }
}