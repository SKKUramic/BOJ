// 1106 호텔
// https://www.acmicpc.net/problem/1106
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> Ad[100]; // <cost, people>
int dp[100001]; // 1원부터 100000원까지

int main(){
	int C, N;
	cin >> C >> N;
	for (int n = 0; n < N; n++){
		cin >> Ad[n].first >> Ad[n].second;
	}
	for (int n = 0; n < N; n++){
		for (int k = 1; k <= 100000; k++){
			if (k - Ad[n].first >= 0){
				dp[k] = max(dp[k], dp[k - Ad[n].first] + Ad[n].second);
			}	
		}
	}
	for (int k = 1; k <= 100000; k++){
		if (dp[k] >= C){
			cout << k;
			break;
		}
	}
}