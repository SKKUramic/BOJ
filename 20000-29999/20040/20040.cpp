// 20040 사이클 게임
// https://www.acmicpc.net/problem/20040
#include <iostream>
#include <vector>
using namespace std;

int parent[500001];

int FIND(int x){
    if (parent[x] == -1){
		return x;
	}
    return parent[x] = FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	if (x == y){return;}
	else {
		parent[y] = x;
		return;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool cycle = false;
	int N, M, a, b, make_cycle = 0;
	cin >> N;
	cin >> M;
	for (int n = 0; n <= N; n++){parent[n] = -1;}
	for (int m = 1; m <= M; m++){
		cin >> a >> b;
		if (FIND(a) == FIND(b) && cycle == false) {
			make_cycle = m;
			cycle = true;
		}
		Union(a, b);
	}
	cout << make_cycle;
}