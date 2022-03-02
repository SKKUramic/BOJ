// 2579 계단 오르기
#include <iostream>
using namespace std;

int stairs_dp[310] = {0, }; // 각 계단까지의 최대합
int stairs_score[310] = {0, }; // 각 계단의 점수

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int stairs_count, num1, num2;
	cin >> stairs_count;
	for (int i = 3; i < stairs_count + 3; i++){
		cin >> stairs_score[i];
	}
	for (int i = 3; i < stairs_count + 3; i++){
		num1 = stairs_dp[i - 3] + stairs_score[i - 1] + stairs_score[i];
		num2 = stairs_dp[i - 2] + stairs_score[i];
		stairs_dp[i] = num1 > num2 ? num1 : num2;
	}
	printf("%d", stairs_dp[stairs_count + 2]);
}