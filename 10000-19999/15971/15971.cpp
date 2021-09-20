// 15971 두 로봇
// https://www.acmicpc.net/problem/15971
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pll;

int N, robot1, robot2;
ll min_length = 1234567890, LENGTH;
vector<pll> graph[100001];
vector<ll> length_list;
bool visited[100001];

void DFS(int x, ll length_sum){
	if (x == robot2){
		for (int i = 0; i < length_list.size(); i++){
			if (min_length > (length_sum - length_list[i])) {
				min_length = length_sum - length_list[i];
			}
		}
		return;
	}
	for (int i = 0; i < graph[x].size(); i++){
		if (visited[graph[x][i].first] == false){
			visited[graph[x][i].first] = true;
			length_list.push_back(graph[x][i].second);
			DFS(graph[x][i].first, length_sum + graph[x][i].second);
			length_list.pop_back();
			visited[graph[x][i].first] = false;
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v;
	cin >> N >> robot1 >> robot2;
	if (N < 3 || robot1 == robot2){
		cout << 0;
		return 0;
	}
	for (int n = 0; n < N - 1; n++){
		cin >> u >> v >> LENGTH;
		graph[u].push_back({v, LENGTH});
		graph[v].push_back({u, LENGTH});
	}
	DFS(robot1, 0);
	cout << min_length;
}