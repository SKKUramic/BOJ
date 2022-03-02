// 10451 순열 사이클
// https://www.acmicpc.net/problem/10451
#include <iostream>
using namespace std;

int arr[1001] = {0, };
bool visited[1001] = {false, };

void DFS(int node){
	if (visited[node] == true){return;}
	visited[node] = true;
	DFS(arr[node]);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, count;
	cin >> T;
	while (T-- > 0){
		count = 0;
		cin >> N;
		for (int n = 1; n <= N; n++){
			cin >> arr[n];
		}
		for (int n = 1; n <= N; n++){
			if (visited[n] == false){
				DFS(n);
				count++;
			}
		}
		cout << count << '\n';
		for (int n = 1; n <= N; n++){
			visited[n] = false;
		}
	}
}