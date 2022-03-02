// 15924 너 봄에는 캡사이신이 맛있단다
// https://www.acmicpc.net/problem/15824
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll N, answer = 0, REM = 1000000007;
ll ScovilleScale[300001] = {0, };

ll Exponential(ll A, ll exp){
	ll ret = 1;
	while (exp > 0){
		if (exp % 2 == 1){
			ret = (ret * A) % REM;
		}
		A = (A * A) % REM;
		exp /= 2;
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll plus, minus;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> ScovilleScale[n];
	}
	sort(ScovilleScale, ScovilleScale + N);
	for (ll i = 0; i < N; i++){
		plus = Exponential(2, i);
		minus = Exponential(2, N - 1 - i);
		answer += (ScovilleScale[i] % REM) * plus % REM;
		answer -= (ScovilleScale[i] % REM) * minus % REM;
		answer = ((answer % REM) + REM) % REM; // 음수 방지
	}
	cout << answer;
}