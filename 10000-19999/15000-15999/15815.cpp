// 15815 천재 수학자 성필
// https://www.acmicpc.net/problem/15815
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<long long> st;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	long long a, b, tmp;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			tmp = s[i] - '0';
			st.push(tmp);
		}
		else {
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			if (s[i] == '+'){
				st.push(a + b);
			}
			else if (s[i] == '-'){
				st.push(a - b);
			}
			else if (s[i] == '*'){
				st.push(a * b);
			}
			else if (s[i] == '/'){
				st.push(a / b);
			}
		}
	}
	cout << st.top();
}