// 12784 인하니카 공화국
// https://www.acmicpc.net/problem/12784
#include <iostream>
#include <vector>
using namespace std;

typedef struct branch{
	int end;
	int weight;
	void init(int e, int w){
		this->end = e;
		this->weight = w;
	}
}branch;

bool visited[1001];
vector<branch> Tree[1001];
int dp[1001] = {0, };

int min(int a, int b){return a < b ? a : b;}

void initialize(int N){
	for (int n = 1; n <= N; n++){
		visited[n] = false;
		Tree[n].clear();
		dp[n] = 99999999;
	}
	return;
}

void DFS(int v){
	int e, dynamite = 0;
	visited[v] = true;
	for (int i = 0; i < Tree[v].size(); i++){
		e = Tree[v][i].end;
		if (visited[e] == true){continue;}
		DFS(e);
		dynamite += min(dp[e], Tree[v][i].weight);
	}
	if (dynamite != 0){dp[v] = dynamite;}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, N, M;
	int v1, v2, weight;
	for (int n = 1; n <= 1000; n++){dp[n] = 99999999;}
	cin >> TC;
	while (TC-- > 0){
		cin >> N >> M;
		for (int m = 0; m < M; m++){
			cin >> v1 >> v2 >> weight;
			Tree[v1].push_back({v2, weight});
			Tree[v2].push_back({v1, weight});
		}
		DFS(1);
		if (dp[1] == 99999999){dp[1] = 0;}
		cout << dp[1] << '\n';
		initialize(N);
	}
}