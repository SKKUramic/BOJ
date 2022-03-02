// 5648 역원소 정렬
// https://www.acmicpc.net/problem/5648
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];

long long rev(long long num){
	long long ret = 0;
	while (num){
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long num;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		arr[n] = rev(num);
	}
	sort(arr, arr + N);
	for (int n = 0; n < N; n++){
		cout << arr[n] << '\n';
	}
}