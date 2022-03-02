// 16566 카드 게임
// https://www.acmicpc.net/problem/16566
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int parent[4000001] = {0, };
int N, M, K;

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return parent[x] = FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	//cout << x << ' ' << y << '\n';
	if (x == y){return;}
	else {
		if (x > y){parent[y] = x;}
		else {parent[x] = y;}
		return;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, answer, idx;
	cin >> N >> M >> K;
	for (int m = 0; m < M; m++){
		cin >> num;
		parent[num] = num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int n = 1; n <= N; n++){
		if (parent[n] == 0){parent[n] = n + 1;}
	}
	for (int k = 0; k < K; k++){
		cin >> num;
		idx = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
		answer = FIND(arr[idx]);
		idx = lower_bound(arr.begin(), arr.end(), answer) - arr.begin();
		cout << answer << '\n';
		if (idx < M - 1){Union(answer, arr[idx + 1]);}
	}
}