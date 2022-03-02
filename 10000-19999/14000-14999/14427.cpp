// 14427 수열과 쿼리 15
// https://www.acmicpc.net/problem/14427
#include <iostream>
#include <utility>
#define MAX 131072
#define INF 1111111111
using namespace std;

typedef long long ll;

int Lnum, Rnum;
pair<ll, ll> answer;
pair<ll, ll> segtree[262145]; // <data, idx>

pair<ll, ll> return_minpair(pair<ll, ll> a, pair<ll, ll> b){ // data가 작은 pair 리턴, 둘이 같다면 idx가 작은 pair 리턴
	if (a.first < b.first){
		return a;
	}
	else if (a.first > b.first){
		return b;
	}
	else {
		if (a.second < b.second){
			return a;
		}
		else {
			return b;
		}
	}
}

void update(ll idx, ll num){
	segtree[idx] = {num, idx - MAX + 1}; // idx는 1부터 시작하므로 보정해줌
	while (idx > 1){
		idx /= 2;
		segtree[idx] = return_minpair(segtree[2 * idx], segtree[2 * idx + 1]);
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long num;
	int N, M, command, idx;
	cin >> N;
	for (int i = 0; i <= 2 * MAX; i++){
		segtree[i] = {INF, INF};
	}
	for (int i = 0; i < N; i++){
		cin >> num;
		update(MAX + i, num);
	}
	cin >> M;
	for (int m = 0; m < M; m++){
		cin >> command;
		if (command == 1){
			cin >> idx >> num;
			update(MAX + idx - 1, num);
		}
		else if (command == 2){
			cout << segtree[1].second << '\n'; // 배열 내의 최솟값의 위치만 출력하면 됨
		}
	}
}