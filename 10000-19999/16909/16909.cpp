// 16909 카드 구매하기 3
// https://www.acmicpc.net/problem/16909
// (모든 구간의 최댓값의 합) - (모든 구간의 최솟값의 합)
#include <iostream>
#include <stack>
using namespace std;

int N, num;
stack<long long> s;
long long max_sum = 0, min_sum = 0;
long long arr[1000001], LEFT[1000001], RIGHT[1000001]; // 일단 다 0으로 초기화되어있음

long long find_sum(){
	for (int i = 0; i < N; i++){
		while (!s.empty() && arr[s.top()] <= arr[i]){
			s.pop();
		}
		if (s.empty()){
			LEFT[i] = i;
			s.push(i);
		}
		else {
			LEFT[i] = i - s.top() - 1;
			s.push(i);
		}
	}
	while(!s.empty()){s.pop();}
	for (int i = N - 1; i >= 0; i--){
		while (!s.empty() && arr[s.top()] < arr[i]){ // 중복으로 세는 경우를 막기 위해 역순은 등호를 붙이지 않음
			s.pop();
		}
		if (s.empty()){
			RIGHT[i] = N - 1 - i; // 혹시 몰라서
			s.push(i);
		}
		else {
			RIGHT[i] = s.top() - i - 1;
			s.push(i);
		}
	}
	while(!s.empty()){s.pop();}
	long long ret = 0;
	for (int i = 0; i < N; i++){
		ret += arr[i] * (LEFT[i] + 1) * (RIGHT[i] + 1);
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	max_sum = find_sum();
	for (int i = 0; i < N; i++){
		arr[i] *= -1;
	}
	min_sum = find_sum();
	cout << max_sum + min_sum;
}