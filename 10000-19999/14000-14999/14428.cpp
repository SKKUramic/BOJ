// 14428 수열과 쿼리 16
// https://www.acmicpc.net/problem/14428
// 14427 수열과 쿼리 15 문제의 해답 코드를 응용하였습니다
#include <iostream>
#include <utility>
#define MAX 131072
#define INF 1111111111
using namespace std;

typedef long long ll;

ll Lnum, Rnum;
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
		segtree[idx] = return_minpair(segtree[2 * idx], segtree[2 * idx + 1]); // 최소 pair를 저장
	}
	return;
}

pair<ll, ll> find_pair(int node, ll left, ll right){
	if (left > Rnum || right < Lnum){return {INF, INF};} // 범위를 벗어났을 경우, 이게 답이 될 순 없음
	if (node >= MAX){return segtree[node];} // 맨 아래에 도착함
	if (Lnum <= left && right <= Rnum){return segtree[node];} // 범위 이내의 pair를 찾음
	ll middle = (left + right) / 2;
	return return_minpair(find_pair(2 * node, left, middle), find_pair(2 * node + 1, middle + 1, right)); // 작은 data 혹은 idx 값을 가진 pair를 리턴
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll num;
	int N, M, command, idx;
	cin >> N;
	for (int i = 0; i <= 2 * MAX; i++){
		segtree[i] = {INF, INF}; // 초기화
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
			cin >> Lnum >> Rnum; // 찾을 범위를 지정함
			answer = find_pair(1, 1, MAX); // 일단 맨 처음과 맨 끝을 범위로 잡고 목표 범위로 줄여나가며 찾음
			cout << answer.second << '\n'; // 범위 배열 내의 최솟값의 위치만 출력하면 됨
		}
	}
}