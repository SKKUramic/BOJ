// 18436 수열과 쿼리 37
// https://www.acmicpc.net/problem/18436
#include <iostream>
#include <utility>
#define MAX 131072
using namespace std;

typedef long long ll;
int N, M, Lnum, Rnum;
ll command, p1, p2;
pair<ll, ll> answer; // <홀수, 짝수>
pair<ll, ll> segtree[262144]; // Ai ~ Aj 중 가장 큰 값 두 개를 pair에 저장함

pair<ll, ll> operator +(pair<ll, ll> left, pair<ll, ll> right){ // pair<ll, ll>끼리의 덧셈 정의
	int x = left.first + right.first;
	int y = left.second + right.second;
	return make_pair(x, y);
}

void update(ll idx, ll num){
	if (num % 2 == 1){segtree[idx] = {1, 0};} // 홀수일 경우 <홀수 1개, 짝수 0개>
	else {segtree[idx] = {0, 1};} // 짝수일 경우 <홀수 0개, 짝수 1개>
	while (idx > 1){
		idx /= 2;
		segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1]; // i~j까지의 홀수의 개수와 짝수의 개수를 저장
	}
	return;
}

pair<ll, ll> find_pair(int node, ll left, ll right){
	if (left > Rnum || right < Lnum){return {0, 0};} // 범위를 벗어났을 경우
	if (node >= MAX){return segtree[node];}
	if (Lnum <= left && right <= Rnum){return segtree[node];}
	ll middle = (left + right) / 2;
	return find_pair(2 * node, left, middle) + find_pair(2 * node + 1, middle + 1, right);
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
			answer = find_pair(1, 1, MAX);
			cout << answer.second << '\n'; // 짝수의 개수를 출력함
		}
		else if (command == 3){
			Lnum = p1; Rnum = p2;
			answer = find_pair(1, 1, MAX);
			cout << answer.first << '\n'; // 홀수의 개수를 출력함
		}
	}
}