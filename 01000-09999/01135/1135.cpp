// 1135 뉴스 전하기
// https://www.acmicpc.net/problem/1135
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Company[51];
bool visited[51];
int DP[51] = {0, };

int max(int a, int b){return a > b ? a : b;}
bool cmp(int a, int b){return DP[a] > DP[b];}

void dfs(int v){
	int e, ret = 0;
	vector<int> time;
	visited[v] = true;
	for (int i = 0; i < Company[v].size(); i++){
		e = Company[v][i];
		if (visited[e] == true){continue;}
		dfs(e);
		time.push_back(e);
	}
	sort(time.begin(), time.end(), cmp); // DP 시간이 큰 순서대로 정렬
	for (int i = 0; i < time.size(); i++){
		ret = max(ret, DP[time[i]] + (i + 1));
	}
	DP[v] = ret;
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, v;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> v;
		if (v != -1){Company[v].push_back(n);}
	}
	dfs(0);
	cout << DP[0];
}