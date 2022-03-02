// 1038 감소하는 수
// https://www.acmicpc.net/problem/1038
#include <iostream>
#include <string>
using namespace std;

int N, FIND = 0;

void desending_number(int len, string s, int idx){
	if (FIND >= N){return;}
	if (len == 1){
		FIND++;
		if (FIND == N){
			cout << s;
		}
		return;
	}
	for (int i = 0; i < idx; i++){
		desending_number(len - 1, s + to_string(i), i);
	}
	return;
}

int main(){
	scanf("%d", &N);
	if (N > 1022){cout << "-1"; return 0;} // 9876543210은 1022번째 감소하는 수로, 이 수가 마지막임
	else if (N == 0){cout << "0"; return 0;} // 아 왜 0도 포함하냐고요
	for (int n = 1; n <= 10; n++){ // 9876543210은 10자리 수임
		for (int i = 1; i < 10; i++){
			if (FIND < N){
				desending_number(n, to_string(i), i); // ㅋㅋ 미안하다 0은 시작하면 안 된다
			}
		}
	}
}