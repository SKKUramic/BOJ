// 2252 줄 세우기
// https://www.acmicpc.net/problem/2252
// https://m.blog.naver.com/ndb796/221236874984(안경잡이개발자님)에게 많이 배웠습니다
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int InDegree[33333] = {0, }; // InDegree[i] == 0이면 i의 진입차수가 없다는 뜻이다
int result[33333] = {0, };
vector<int> topology[33333];

void topology_sort(int N){
	queue<int> q;
	for (int i = 1; i <= N; i++){
		if (InDegree[i] == 0){q.push(i);} // 진입차수가 없을 경우
	}
	for (int i = 1; i <= N; i++){
		if (q.empty()){ // 남은 정점들 모두에게 진입차수가 있을 경우, 즉 사이클이 존재할 경우
			cout << "ERROR\n";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < topology[x].size(); i++){
			int y = topology[x][i];
			if (--InDegree[y] == 0){ // y에 더 이상 진입차수가 없을 경우
				q.push(y);
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		topology[a].push_back(b);
		InDegree[b]++;
	}
	topology_sort(N);
	for (int i = 1; i <= N; i++){
		cout << result[i] << ' ';
	}
}