// 1517 버블 소트
// https://www.acmicpc.net/problem/1517
// 10090번과 같이 풀면 좋은 문제입니다. https://pangtrue.tistory.com/307와 https://slllju.tistory.com/138을 읽고 풀었습니다. 이렇게도 사용이 가능하다니
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 524288
using namespace std;

int Lnum, Rnum;
long long answer = 0;
long long segment_tree[1048576] = {0, }; // <value, idx>

void insert(int idx){
	while (idx > 0){
		idx /= 2;
		segment_tree[idx]++; // MAX + arr[i].second 번째 숫자가 i번째로 돌아옴
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