// 1450 냅색문제
// https://www.acmicpc.net/problem/1450
// http://wookje.dance/2017/11/02/boj-1450-%EB%83%85%EC%83%89%EB%AC%B8%EC%A0%9C/
// wookje님의 풀이입니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int bag[30];
vector<long long int> bag1;
vector<long long int> bag2;

int N, middle;
long long int C, answer = 0;

void dfs(int start, int end, vector<long long int>& v, long long int sum){
	if (sum > C) {return;} // 넣은 짐의 총 무게가 기준보다 클 경우 벡터에 넣지 않음
	if (start > end){
		v.push_back(sum); // 넣은 짐의 총 무게가 기준보다 작으며, 모두 탐색했을 때 벡터에 넣음
		return;
	}
	else {
		dfs(start + 1, end, v, sum); // start번째 짐을 가방에 넣지 않음
		dfs(start + 1, end, v, sum + bag[start]); // start번째 짐을 가방에 넣음
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;
	middle = N / 2;
	for (int i = 0; i < N; i++){
		cin >> bag[i];
	}
	dfs(0, middle, bag1, 0);
	dfs(middle + 1, N - 1, bag2, 0);
	sort(bag1.begin(), bag1.end());
	sort(bag2.begin(), bag2.end()); // 둘 다 오름차순으로 정렬함
	int end = bag2.size() - 1;
	for (int start = 0; start < bag1.size(); start++){
		while (end >= 0 && bag1[start] + bag2[end] > C){
			end--;
		}
		answer += end + 1;
	}
	cout << answer;
}