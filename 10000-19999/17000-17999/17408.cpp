// 17408 수열과 쿼리 24
// https://www.acmicpc.net/problem/17408
#include <iostream>
#include <utility>
#define MAX 131072
using namespace std;

typedef long long ll;
int N, M, Lnum, Rnum;
ll command, p1, p2;
pair<ll, ll> answer;
pair<ll, ll> segtree[262144]; // Ai ~ Aj 중 가장 큰 값 두 개를 pair에 저장함

pair<ll, ll> ret_maxpair(pair<ll, ll> a, pair<ll, ll> b){ // 두 큰 값 pair를 리턴함
	pair<ll, ll> ret;
	ll arr[4];
	ll temp;
	arr[0] = a.first; arr[1] = a.second; arr[2] = b.first; arr[3] = b.second;
	for (int i = 3; i >= 0; i--){
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	ret.first = arr[0]; ret.second = arr[1];
	return ret;
}

void update(ll idx, ll num){
	segtree[idx] = {num, 0};
	while (idx > 1){
		idx /= 2;
		segtree[idx] = ret_maxpair(segtree[2 * idx], segtree[2 * idx + 1]);
	}
	return;
}

pair<ll, ll> find_maxpair(int node, ll left, ll right){
	if (left > Rnum || right < Lnum){return {0, 0};} // 범위를 벗어났을 경우
	if (node >= MAX){return segtree[node];}
	if (Lnum <= left && right <= Rnum){return segtree[node];}
	ll middle = (left + right) / 2;
	return ret_maxpair(find_maxpair(2 * node, left, middle), find_maxpair(2 * node + 1, middle + 1, right)); // 리턴받은 두 pair에서 4개의 수 중 2개의 수를 다시 리턴함
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll data;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> data;
		update(MAX + i, data);
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> command >> p1 >> p2;
		if (command == 1){
			update(MAX + p1 - 1, p2);
		}
		else if (command == 2){
			Lnum = p1; Rnum = p2;
			answer = find_maxpair(1, 1, MAX);
			cout << answer.first + answer.second << '\n'; // 답을 출력함
		}
	}
}