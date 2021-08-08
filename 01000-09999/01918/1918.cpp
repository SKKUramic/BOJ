// 1918 후위 표기식
// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
string expression;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> expression;
	for (int i = 0; i < expression.size(); i++){
		if (expression[i] >= 'A' && expression[i] <= 'Z'){ // 그냥 출력한다.
			cout << expression[i];
		}
		else if (expression[i] == '+' || expression[i] == '-'){ // 더하기나 뺄셈을 만나면, 괄호의 시작을 만나기 전까지 stack 내의 문자를 계속 출력한다. 종료 시 이 문자를 stack에 넣는다.
			while (!s.empty() && s.top() != '('){
				cout << s.top();
				s.pop();
			}
			s.push(expression[i]);
		}
		else if (expression[i] == '*' || expression[i] == '/'){ // 나눗셈이나 곱셈을 만나면, 괄호의 시작 혹은 +-를 만나기 전까지 stack 내의 문자를 계속 출력한다. 종료 시 이 문자를 stack에 넣는다.
			while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-'){
				cout << s.top();
				s.pop();
			}
			s.push(expression[i]);
		}
		else if (expression[i] == '('){ // 그냥 stack에 넣는다.
			s.push(expression[i]);
		}
		else if (expression[i] == ')'){ // 괄호 내의 모든 문자를 출력한다.
			while (s.top() != '('){
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()){
		cout << s.top();
		s.pop();
	}
}