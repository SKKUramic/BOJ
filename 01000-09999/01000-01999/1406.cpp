// 1406 에디터
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> LEFT;
stack<char> RIGHT;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	char command, p;
	string C;
	cin >> C;
	for (int i = 0; i < C.length(); i++){
		LEFT.push(C[i]);
	}
	cin >> T;
	while (T-- > 0){
		cin >> command;
		if (command == 'L'){
			if (!LEFT.empty()){
				RIGHT.push(LEFT.top());
				LEFT.pop();
			}
		}
		else if (command == 'D'){
			if (!RIGHT.empty()){
				LEFT.push(RIGHT.top());
				RIGHT.pop();
			}
		}
		else if (command == 'B'){
			if (!LEFT.empty()){
				LEFT.pop();
			}
		}
		else if (command == 'P'){
			cin >> p;
			LEFT.push(p);
		}
	}
	while (!LEFT.empty()){
		RIGHT.push(LEFT.top());
		LEFT.pop();
	}
	while (!RIGHT.empty()){
		cout << RIGHT.top();
		RIGHT.pop();
	}
}