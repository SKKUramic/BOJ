// 1976 여행 가자
// https://www.acmicpc.net/problem/1976
#include <iostream>
#include <vector>
using namespace std;

int parent[201];

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
	bool travel = true;
	int N, M, num, city;
	cin >> N;
	cin >> M;
	for (int n = 0; n <= N; n++){parent[n] = -1;}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> num;
			if (num == 1 && i < j) {
				Union(i, j);
			}
		}
	}
	cin >> city;
	city = FIND(city);
	for (int m = 1; m < M; m++){
		cin >> num;
		if (FIND(num) != city) {travel = false;}
	}
	if (travel == true) {cout << "YES";}
	else {cout << "NO";}
}