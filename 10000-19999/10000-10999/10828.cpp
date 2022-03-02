// 10828 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, temp;
	string word;
	stack<int> s;
	cin >> test;
	for (int i = 0; i < test; i++){
		cin >> word;
		if (!word.compare("push")){
			cin >> temp;
			s.push(temp);
		}
		else if (!word.compare("pop")){
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (!word.compare("size")){
			cout << s.size() << '\n';
		}
		else if (!word.compare("empty")){
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (!word.compare("top")){
			if (s.empty())
				cout << -1 << '\n';
			else 
				cout << s.top() << '\n';
		}
	}
}