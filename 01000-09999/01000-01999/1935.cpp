// 1935 후위 표기식
// https://www.acmicpc.net/problem/1935
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<double> sd; // 후위 표기식을 계산하기 위해선 
char str[101];
double AtoZ[30];

int main(){
	int N, Size;
	double a, b;
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++){
		cin >> AtoZ[i];
	}
	Size = strlen(str);
	for (int i = 0; i < Size; i++){
		if (str[i] < 'A' || str[i] > 'Z'){ // 사칙연산자가 들어오면, 직전에 스택에 넣은 두 double 숫자를 꺼내 계산한다.
			b = sd.top(); sd.pop();
			a = sd.top(); sd.pop(); // 나눗셈 때문에 거꾸로 뽑음
			if (str[i] == '+'){
				sd.push(a + b);
			}
			else if (str[i] == '-'){
				sd.push(a - b);
			}
			else if (str[i] == '*'){
				sd.push(a * b);
			}
			else if (str[i] == '/'){
				sd.push(a / b);
			}
		}
		else {
			sd.push(AtoZ[str[i] - 'A']);
		}
	}
	printf("%.2lf", sd.top()); // 답은 스택 안에 있다
}