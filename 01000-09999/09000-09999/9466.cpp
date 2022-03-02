// 9466 텀 프로젝트
// https://www.acmicpc.net/problem/9466
// https://jaimemin.tistory.com/674(꾸준함님의 블로그)에서 많이 배웠습니다. 중간에 사이클이 생기는 경우를 처리하는 방법을 몰랐습니다ㅠㅠ
#include <iostream>
using namespace std;

int count;
int hopemate[100001];
bool visited[100001]; // 
bool teammate[100001]; // 방문이 끝났는지 확인

void DFS(int n){
	visited[n] = true;
	int next = hopemate[n];
	if (visited[next] == false){ // 다음 사람도 조사를 안 했다면
		DFS(next);
	}
	else if (teammate[next] == false){ // 뭐야 방문했다면서! 아직 팀도 못 맺은 거야?
		for (int i = next; i != n; i = hopemate[i]){
			count++;
		}
		count++; // 나도 센다
	}
	teammate[n] = true;
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	cin >> T;
	while (T-- > 0){
		cin >> N;
		for (int n = 1; n <= N; n++){
			cin >> hopemate[n];
		}
		count = 0;
		for (int n = 1; n <= N; n++){
			if (visited[n] == false){ // 아직 검사를 안 했다면
				DFS(n);
			}
		}
		for (int n = 1; n <= N; n++){
			visited[n] = false;
			teammate[n] = false;
		}
		cout << N - count << '\n';
	}
}