// 2110 공유기 설치
// 이진 탐색
#include <bits/stdc++.h>
using namespace std;

long long house[200001];

int main(){
	long long N, C;
	cin >> N >> C;
	for (long long i = 0; i < N; i++){
		cin >> house[i];
	}
	sort(house, house + N);
	long long left = 1;
	long long right = house[N - 1] - house[0];
	long long ans = 0;
	while (left <= right){
		long long middle = (left + right) / 2;
		long long cnt = 1;
		long long start = house[0];
		long long d = 0;
		for (long long i = 1; i < N; i++){
			d = house[i] - start;
			if (middle <= d){
				cnt++;
				start = house[i];
			}
		}
		if (cnt >= C){
			ans = middle;
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	cout << ans << endl;
}