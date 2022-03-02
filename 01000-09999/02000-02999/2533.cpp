// 2533 사회망 서비스(SNS)
// https://www.acmicpc.net/problem/2533
#include <iostream>
#include <vector>
using namespace std;

vector<int> SNS[1000001];
bool visited[1000001];
int DP[1000001][2] = {0, }; // 0 = 일반인, 1 = 얼리 아답터? 어답터?

int min(int a, int b){return a < b ? a : b;}

void DFS(int v){
	int child;
	visited[v] = true;
	DP[v][1] = 1; // 본인이 얼리 어답터가 될 경우, 해당하는 DP값은 1이 최솟값
	for (int i = 0; i < SNS[v].size(); i++){
		child = SNS[v][i];
		if (visited[child] == false){
			DFS(child);
			DP[v][0] += DP[child][1]; // v가 일반인일 경우, chlid가 얼리 어답터이여야 함. 그때의 child의 DP값을 더함(아무리 못 해도 1은 더해짐)
			DP[v][1] += min(DP[child][0], DP[child][1]); // v가 얼리 어답터일 경우, child는 무엇이든 상관 없으므로 더 작은 값을 선택, 이를 더함
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v, N;
	cin >> N;
	for (int n = 0; n < N - 1; n++){
		cin >> u >> v;
		SNS[u].push_back(v);
		SNS[v].push_back(u);
	}
	DFS(1); // 1을 루트로 가정
	cout << min(DP[1][0], DP[1][1]);
}