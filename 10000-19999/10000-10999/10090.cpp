// 10090 Counting Inversions
// https://www.acmicpc.net/problem/10090
// 1517번과 입력 크기만 다를 뿐 동일한 문제라서 MAX의 값만 변경되었을 뿐 코드는 동일합니다.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 1048576
using namespace std;

int Lnum, Rnum;
long long answer = 0;
long long segment_tree[2097152] = {0, }; // <value, idx>

void insert(int idx){
	while (idx > 0){
		idx /= 2;
		segment_tree[idx]++;
	}
	return;
}

long long bubble_pop(int node, int left, int right){
	if (left > Rnum || right < Lnum){return 0;} // 범위를 벗어났을 경우
	if (Lnum <= left && right <= Rnum){
		return segment_tree[node];
	}
	int middle = (left + right) / 2;
	return bubble_pop(2 * node, left, middle) + bubble_pop(2 * node + 1, middle + 1, right);
}

int main(){
	ios_base :: sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	vector<pair<int, int>> arr;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num;
		arr.push_back({num, i});
	}
	sort(arr.begin(), arr.end());
	int base = 1;
	while (base < N){base *= 2;}
	for (int i = 0; i < N; i++){
		Lnum = arr[i].second + 1;
		Rnum = MAX;
		answer += bubble_pop(1, 1, MAX);
		insert(MAX + arr[i].second);
	}
	cout << answer;
}