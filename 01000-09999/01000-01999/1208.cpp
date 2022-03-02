// 1208 부분수열의 합 2
// https://www.acmicpc.net/problem/1208
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[40];
int N, S;
long long int counter, S_count = 0;
vector<int> v1;
vector<int> v2;

void dfs(int start, int end, vector<int>& v, int sum){
	if (start > end) {
		v.push_back(sum);
		return;
	}
	dfs(start + 1, end, v, sum);
	dfs(start + 1, end, v, sum + arr[start]);
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	dfs(0, N / 2, v1, 0);
	dfs(N / 2 + 1, N - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int end = v2.size() - 1;
	for (int i = 0; i < v1.size(); i++){
		counter = upper_bound(v2.begin(), v2.end(), S - v1[i]) - lower_bound(v2.begin(), v2.end(), S - v1[i]);
		S_count += counter;
	}
	if (S == 0){S_count--;} // S가 0이면 공집합간의 합도 답으로 인식하므로 이를 제거함
	cout << S_count;
}