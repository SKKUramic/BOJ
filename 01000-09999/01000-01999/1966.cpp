// 1966 프린터 큐
#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, paper, index, p, hi, hello, count = 0;
	queue<pair<int, int>> q;
	priority_queue <int> priority;
	cin >> test;
	for (int i = 0; i < test; i++){
		count = 0;
		cin >> paper >> index;
		for (int x = 0; x < paper; x++){
			cin >> p;
			q.push(make_pair(x, p));
			priority.push(p);
		}
		
		while (!q.empty()){
			hi = q.front().first;
			hello = q.front().second;
			//cout << hi << ' ' << hello << ' ';
			q.pop();
			if (priority.top() == hello){
				priority.pop();
				count++;
				//cout << "count plus" << ' ';
				if (hi == index){
					cout << count << '\n';
					break;
				}
			}
			else{
				q.push(make_pair(hi, hello));
			}
			//cout << '\n';
		}
		//cout << '\n';
		//initializing
		while (!q.empty())
			q.pop();
		while (!priority.empty())
			priority.pop();
	}
}