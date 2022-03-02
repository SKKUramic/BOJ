// 12978 스크루지 민호 2
// https://www.acmicpc.net/problem/12978
#include <iostream>
#include <vector>
using namespace std;

bool visited[100001];
int DP[100001][2] = {0, }; // 0: 경찰서 없음, 1: 경찰서 있음
vector<int> Tree[100001];

int min(int a, int b){return a < b ? a : b;}

void dfs(int v){
	int e;
	visited[v] = true;
	DP[v][1] = 1;
	for (int i = 0; i < Tree[v].size(); i++){
		e = Tree[v][i];
		if (visited[e] == true){continue;}
		dfs(e);
		DP[v][0] += DP[e][1];
		DP[v][1] += min(DP[e][0], DP[e][1]);
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int city, v1, v2;
	cin >> city;
	for (int c = 0; c < city - 1; c++){
		cin >> v1 >> v2;
		Tree[v1].push_back(v2);
		Tree[v2].push_back(v1);
	}
	dfs(1);
	cout << min(DP[1][0], DP[1][1]);
}