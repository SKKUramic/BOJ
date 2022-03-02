// 20047 동전 옮기기
// https://www.acmicpc.net/problem/20047
// https://zoomkoding.github.io/codingtest/2020/10/11/2020-ACM-ICPC-1.html(줌코딩님의 블로그)에서 배웠습니다. 재귀로 하는 게 명답이었네요
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool flag = true;
vector<int> v;
string S, T, D;
int a, b, N;
char Selected[2];

bool MoveCoin(int idx, int Finger){
	if (idx + Finger == N){return true;} // 끝까지 조사했을 때 가능한 경우
	if (S[idx] == T[idx + Finger]){
		if (MoveCoin(idx + 1, Finger) == true){return true;} // 현재 S 동전과 T 동전이 같은 동전일 때, 그 뒤로도 참일 경우
	}
	if (Finger == 2){return false;} // 아직 끝까지 조사 안 했는데 벌써 동전 2개를 다 옮겼을 때
	if (Selected[Finger] == T[idx + Finger]){
		if (MoveCoin(idx, Finger + 1) == true){return true;} // 지금 T 동전이 손가락으로 짚은 동전이고, 그 뒤로도 참일 경우
	}
	return false;
}

int main(){
	cin >> N;
	cin >> S >> T;
	cin >> a >> b;
	Selected[0] = S[a]; Selected[1] = S[b];
	int t = 0;
	for (int i = 0; i < N; i++){
		if (i == a || i == b){continue;} // S에서 동전 들어간 건 쏙 뺴먹음
		S[t++] = S[i];
	}
	flag = MoveCoin(0, 0);
	if (flag) {cout << "YES";}
	else {cout << "NO";}
}