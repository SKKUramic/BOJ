// 1506 경찰서
// https://www.acmicpc.net/problem/1506
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> answer, police, REVpolice;
stack<int> scc;
bool visited[101], REVvisited[101];
int cost[101] = {0, };
char Map[101][101];
int N, idx = 0;

void REVdfs(int v){
	REVvisited[v] = true;
	answer[idx].push_back(v);
	for (int i = 0; i < REVpolice[v].size(); i++){
		if (REVvisited[REVpolice[v][i]] == false){
			REVdfs(REVpolice[v][i]);
		}
	}
	return;
}

void dfs(int v){
	visited[v] = true;
	for (int i = 0; i < police[v].size(); i++){
		if (visited[police[v][i]] == false){
			dfs(police[v][i]);
		}
	}
	scc.push(v);
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, costsum = 0, mincost;
	cin >> N;
	police.resize(N + 1);
	REVpolice.resize(N + 1);
	for (int n = 1; n <= N; n++){cin >> cost[n];}
	for (int n = 0; n < N; n++){cin >> Map[n];}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (Map[i][j] == '1'){
				police[i + 1].push_back(j + 1);
				REVpolice[j + 1].push_back(i + 1);
			}
		}
	}
	for (int n = 1; n <= N; n++){
		if (visited[n] == false){
			dfs(n);
		}
	}
	while (!scc.empty()){
		v = scc.top(); scc.pop();
		if (REVvisited[v] == false){
			answer.resize(idx + 1);
			REVdfs(v);
			idx++;
		}
	}
	for (int i = 0; i < idx; i++){
		mincost = 9999999;
		for (int k = 0; k < answer[i].size(); k++){
			if (mincost > cost[answer[i][k]]){mincost = cost[answer[i][k]];}
		}
		costsum += mincost;
	}
	cout << costsum;
}