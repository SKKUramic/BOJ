// 2230 수 고르기
// https://www.acmicpc.net/problem/2230
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long arr[100001];

int main(){
	long long diff_min = 999999999999, diff;
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	sort(arr, arr + N);
	int left = 0, right = 0;
	while (left < N && right < N){ // 어느 하나라도 배열 바깥으로 나간다면 종료
		if (diff_min == M){break;}
		diff = abs(arr[right] - arr[left]);
		if (diff >= M){ // 차이가 M 이상일 때
			diff_min = min(diff, diff_min); // 최솟값을 넣음
			if (right < N){left++;} // 아직 차이가 M 이상이므로 left를 한 칸 옮김
		}
		else {
			if (left < N){right++;} // 차이가 M 미만이므로 right를 한 칸 옮김
		}
	}
	cout << diff_min;
}