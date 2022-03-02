// 7344 나무 막대
// https://www.acmicpc.net/problem/7344
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> arr;
bool visited[5001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, N, length, weight, W;
	cin >> TC;
	while (TC-- > 0){
		int answer = 0;
		cin >> N;
		for (int n = 0; n < N; n++){
			cin >> length >> weight;
			arr.push_back({length, weight});
		}
		sort(arr.begin(), arr.end());
		for (int k = 0; k < arr.size(); k++){
			if (visited[k] == true){continue;}
			answer++;
			visited[k] = true;
			W = arr[k].second;
			for (int i = k + 1; i < arr.size(); i++){
				if (arr[i].second < W || visited[i] == true){continue;}
				visited[i] = true;
				W = arr[i].second;
			}
		}
		cout << answer << '\n';
		arr.clear();
		memset(visited, false, sizeof(visited));
	}
}