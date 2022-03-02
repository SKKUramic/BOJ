// 2233 사과나무
// https://www.acmicpc.net/problem/2233
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int N;
vector<int> AppleTree[2001];
int depth[2001], TreeTraversal[4001];
int parent[2001][13];
stack<int> apple;

void MakeTree(int v){ // 사실 사용 안 해도 이 문제는 풀림
	int next;
	for (int i = 0; i < AppleTree[v].size(); i++){
		next = AppleTree[v][i];
		if (depth[next] == -1){
			parent[next][0] = v; // 다음 노드의 부모는 v
			depth[next] = depth[v] + 1; // 다음 노드의 깊이는 (v의 깊이 + 1)
			MakeTree(next);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	int idx = 1, node;
	int rotten1, rotten2, answer;
	string s;
	cin >> N;
	cin >> s;
	apple.push(0);
	for (int n = 0; n < 2 * N; n++){
		if (s[n] == '0'){
			apple.push(idx++);
			TreeTraversal[n] = apple.top();
		}
		else if (s[n] == '1'){
			TreeTraversal[n] = apple.top();
			node = apple.top();
			apple.pop();
			//AppleTree[node].push_back(apple.top());
			//AppleTree[apple.top()].push_back(node);
			depth[node] = (int)apple.size() - 1;
			parent[node][0] = apple.top();
		}
	}
	//depth[1] = 0;
	//MakeTree(1);
	for (int j = 0; j < 12; j++){
		for (int i = 2; i <= N; i++){
			if (parent[i][j] != -1){
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}
	cin >> rotten1 >> rotten2;
	rotten1 = TreeTraversal[rotten1 - 1];
	rotten2 = TreeTraversal[rotten2 - 1];
	if (depth[rotten1] < depth[rotten2]){
		int tmp = rotten1;
		rotten1 = rotten2;
		rotten2 = tmp;
	}
	int diff = depth[rotten1] - depth[rotten2];
	for (int k = 0; diff != 0; k++){
		if (diff % 2 == 1){
			rotten1 = parent[rotten1][k];
		}
		diff /= 2;
	}
	if (rotten1 != rotten2){
		for (int j = 12; j >= 0; j--){
			if (parent[rotten1][j] != -1 && parent[rotten1][j] != parent[rotten2][j]){
				rotten1 = parent[rotten1][j];
				rotten2 = parent[rotten2][j];
			}
		}
		rotten1 = parent[rotten1][0];
	}
	for (int i = 0; i < 2 * N; i++){
		if (TreeTraversal[i] == rotten1){
			cout << i + 1 << ' ';
		}
	}
}