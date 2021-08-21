// 11049 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049
#include <iostream>
#include <utility>
#define INT_MAX 2147483647
using namespace std;

int dp[500][500] = {0, };
pair<int, int> matrix[500];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, a, b, temp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		matrix[i] = {a, b};
	}
	for (int i = 1; i < N; i++){
		for (int idx = 0; idx < N - i; idx++){
			dp[idx][idx + i] = INT_MAX;
			for (int k = idx; k < idx + i; k++){
				temp = dp[idx][k] + dp[k + 1][idx + i] + matrix[idx].first * matrix[k].second * matrix[idx + i].second;
				// (a번째 행렬부터 b번째 행렬의 최소 곱 횟수) + (c번째 행렬부터 d번째 행렬의 최소 곱 횟수) + (남은 두 행렬의 곱 횟수)
				// 남은 두 행렬 => <a번 행렬의 행 개수, b번 행렬의 열 개수>, <c번 행렬의 행 개수, d번 행렬의 열 개수>
				// 따라서 남은 두 행렬의 곱 횟수는 (a번 행렬의 행 개수) * (b번 행렬의 열 개수) * (d번 행렬의 열 개수)이다. (문제 조건에 따라 b번 행렬의 열 개수와 c번 행렬의 행 개수는 서로 같다)
				if (dp[idx][idx + i] > temp){
					dp[idx][idx + i] = temp;
				}
			}
		}
	}
	cout << dp[0][N - 1];
}