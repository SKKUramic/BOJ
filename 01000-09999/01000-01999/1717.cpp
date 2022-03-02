// 1717 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>
using namespace std;

int parent[1000001];

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
	int N, M, comm, a, b;
	cin >> N >> M;
	for (int n = 0; n <= N; n++){parent[n] = -1;}
	for (int m = 0; m < M; m++){
		cin >> comm >> a >> b;
		if (comm == 0){
			Union(a, b);
		}
		else if (comm == 1){
			if (FIND(a) == FIND(b)){cout << "YES\n";}
			else {cout << "NO\n";}
		}
	}
}