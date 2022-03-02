// 1699 제곱수의 합
// https://www.acmicpc.net/problem/1699
#include <iostream>
#include <vector>
using namespace std;

vector<int> square_list;
int dp[100001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, answer = 0;
	for (int i = 1; i * i <= 100000; i++){
		square_list.push_back(i * i);
	}
	for (int i = 0; i <= 100000; i++){dp[i] = 99999999;}
	cin >> N;
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= N; i++){
		for (int idx = 0; square_list[idx] <= i && idx < square_list.size(); idx++){
			if (dp[i] > dp[i - square_list[idx]] + 1){
				dp[i] = dp[i - square_list[idx]] + 1;
			}
		}
	}
	cout << dp[N];
}