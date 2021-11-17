// 17260 계곡이 넘쳐흘러
// https://www.acmicpc.net/problem/17260
#include <iostream>
#include <vector>
using namespace std;

bool valid = false, visited[200001];
long long max_height = -1, height[200001];
int N, K;
vector<int> Tree[200001];

void valley_dfs(int node, long long h){
	visited[node] = true;
	if (valid == true || h > 1000000){return;} // 이미 찾았거나, 어디서 뛰어도 안 되는 경우가 되었을 때
	if (height[node] >= h){
		valid = true;
		return;
	}
	int next;
	long long next_height;
	for (int i = 0; i < Tree[node].size(); i++){
		next = Tree[node][i];
		if (visited[next] == true){continue;}
		next_height = (h - height[node]) * 2 + height[node];
		valley_dfs(next, next_height);
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2;
	cin >> N >> K;
	for (int n = 1; n <= N; n++){
		cin >> height[n];
		if (max_height < height[n]){max_height = height[n];}
	}
	for (int n = 0; n < N - 1; n++){
		cin >> v1 >> v2;
		Tree[v1].push_back(v2);
		Tree[v2].push_back(v1);
	}
	visited[K] = true;
	for (int i = 0; i < Tree[K].size(); i++){
		valley_dfs(Tree[K][i], height[K]);
	}
	if (valid){cout << 1;}
	else {cout << 0;}
}