// 2156 포도주 시식
#include <bits/stdc++.h>
using namespace std;

int arr[10010] = { 0, };
int DP[10010] = { 0, };

int main(){
	int N, num1, num2, num3;
	int ans = 0;
	cin >> N;
	for (int i = 3; i < N + 3; i++){
		cin >> arr[i];
	}
	for (int i = 3; i < N + 3; i++){
		num1 = DP[i - 2] + arr[i]; // 한칸 띄우고 새롭게 한 잔 마신 경우
		num2 = DP[i - 3] + arr[i - 1] + arr[i]; // 연속으로 두 잔 마신 경우
		DP[i] = num1 > num2 ? num1 : num2;
		DP[i] = DP[i] > DP[i - 1] ? DP[i] : DP[i - 1]; // 연속 두 잔 안 마신 경우가 더 클 수도 있음?
		ans = ans > DP[i] ? ans : DP[i];
	}
	cout << ans << endl;
	return 0;
}