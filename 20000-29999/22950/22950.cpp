// 22950 이진수 나눗셈
// https://www.acmicpc.net/problem/22950
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool one = false;
	int N, K, idx = 0;
	string s;
	cin >> N;
	cin >> s;
	cin >> K;
	idx = 0;
	if (K == 0){ // 모든 수는 1로 나누어 떨어짐
		cout << "YES";
		return 0;
	}
	for (int i = 0; i < N; i++){
		if (s[i] == '1'){one = true;}
	}
	if (one == false){ // 0은 나머지가 생기지 않는다
		cout << "YES";
		return 0;
	}
	if (N <= K){ // M이 0이 아니면서, N이 K 이하라면 나누어 떨어지지 않는다
		cout << "NO";
		return 0;
	}
	while (idx < K){
		if (s[N - 1 - idx] == '1'){
			cout << "NO";
			return 0;
		}
		idx++;
	}
	cout << "YES";
}