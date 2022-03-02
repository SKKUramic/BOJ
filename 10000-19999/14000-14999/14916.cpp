// 14916 거스름돈
// https://www.acmicpc.net/problem/14916
#include <iostream>
using namespace std;

int MAX = 99999999;
int DP[100001] = {0, };
int min(int a, int b){
	if (a == 0 && b == 0){return MAX;}
	if (a == 0){return b;}
	if (b == 0){return a;}
	return a < b ? a : b;
}

int main(){
	int N, coin = 0;
	cin >> N;
	DP[1] = MAX; DP[2] = 1; DP[3] = MAX; DP[4] = 2; DP[5] = 1;
	for (int i = 6; i <= N; i++){
		DP[i] = min(DP[i - 2], DP[i - 5]) + 1;
	}
	if (DP[N] == MAX){cout << -1;}
	else {cout << DP[N];}
}