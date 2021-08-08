// 18258 큐 2
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, temp;
	string word;
	queue<int> q;
	cin >> test;
	for (int i = 0; i < test; i++){
		cin >> word;
		if (!word.compare("push")){
			cin >> temp;
			q.push(temp);
		}
		else if (!word.compare("pop")){
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!word.compare("size")){
			cout << q.size() << '\n';
		}
		else if (!word.compare("empty")){
			if (q.empty())
				cout << 1 << '\n';
			else {
				cout << 0 << '\n';
			}
		}
		else if (!word.compare("front")){
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (!word.compare("back")){
			if (q.empty())
				cout << -1 << '\n';
			else 
				cout << q.back() << '\n';
		}
	}
}