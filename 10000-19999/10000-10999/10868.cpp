// 10868 최솟값
// https://www.acmicpc.net/problem/10868
// 앗! 2357 최솟값과 최댓값보다 쉽다! 14438 수열과 쿼리 17 해답 코드와 거의 동일합니다
#include <iostream>
#include <algorithm>
#define MAX 131072
#define INF 1111111111
using namespace std;

typedef long long ll;
ll segtree[262145];
int Lnum, Rnum;

void update(int idx, ll data){
	segtree[idx] = data;
	while (idx > 1){
		idx /= 2;
		segtree[idx] = min(segtree[2 * idx], segtree[2 * idx + 1]);
	}
}

ll find_min(int node, int left, int right){
	if (right < Lnum || Rnum < left){return INF;}
	if (node >= MAX){return segtree[node];}
	if (Lnum <= left && right <= Rnum){return segtree[node];}
	int middle = (left + right) / 2;
	return min(find_min(2 * node, left, middle), find_min(2 * node + 1, middle + 1, right));
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i <= 2 * MAX; i++){
		segtree[i] = INF;
	}
	ll data;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> data;
		update(MAX + i, data);
	}
	for (int i = 0; i < M; i++){
		cin >> Lnum >> Rnum;
		cout << find_min(1, 1, MAX) << '\n';
	}
}