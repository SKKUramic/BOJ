// 13974 파일 합치기 2
// https://www.acmicpc.net/problem/11066
// 여기 있었구만 '우선순위 큐'
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> novel;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, chapter;
	long long int cost, c1, c2, temp;
	cin >> T;
	while (T-- > 0){
		while (!novel.empty()){
			novel.pop();
		}
		cost = 0;
		cin >> chapter;
		for (int i = 1; i <= chapter; i++){
			cin >> temp;
			novel.push(temp);
		}
		if (chapter == 1) { // 1장짜리 소설ㄷㄷ
			cout << novel.top() << '\n';
			continue;
		}
		while (novel.size() != 1){
			c1 = novel.top(); novel.pop();
			c2 = novel.top(); novel.pop();
			temp = c1 + c2;
			cost += temp;
			novel.push(temp);
		}
		cout << cost << '\n';
	}
}