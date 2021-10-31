// 14267 회사 문화 1
// https://www.acmicpc.net/problem/14267
#include <iostream>
#include <vector>
using namespace std;

vector<int> company[100001];
int homete_measure[100001] = {0, };
int DP[100001] = {0, };

void HOMETE(int v, int homete){
	DP[v] += homete;
	for (int i = 0; i < company[v].size(); i++){
		HOMETE(company[v][i], homete + homete_measure[v]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, superior, homete;
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		cin >> superior;
		if (superior != -1){
			company[superior].push_back(i);
		}
	}
	for (int i = 0; i < M; i++){
		cin >> superior >> homete;
		homete_measure[superior] += homete;
	}
	HOMETE(1, 0);
	for (int n = 1; n <= N; n++){
		cout << homete_measure[n] + DP[n] << ' ';
	}
}