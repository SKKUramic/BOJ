// 10866 덱
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, temp;
	string word;
	deque<int> q;
	cin >> test;
	for (int i = 0; i < test; i++){
		cin >> word;
		if (!word.compare("push_front")){
			cin >> temp;
			q.push_front(temp);
		}
		else if (!word.compare("push_back")){
			cin >> temp;
			q.push_back(temp);
		}
		else if (!word.compare("pop_front")){
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (!word.compare("pop_back")){
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.back() << '\n';
				q.pop_back();
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