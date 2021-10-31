// 3986 좋은 단어
// https://www.acmicpc.net/problem/3986
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int TC, answer = 0;
    string s;
    cin >> TC;
    while (TC-- > 0){
        stack<char> st;
        bool valid = true;
        cin >> s;
        for (int i = 0; i < s.length(); i++){
            if (st.empty() == true){st.push(s[i]);}
            else {
                if (st.top() == s[i]){
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        if (!st.empty()){valid = false;}
        if (valid == true){
            answer++;
        }
    }
    cout << answer;
}