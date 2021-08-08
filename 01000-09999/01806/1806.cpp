// 1806 부분합
// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S, start, end, sum;
	int min_length = 999999;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		if (arr[i] == S){ // 최소 길이가 이미 식별될 경우
			cout << 1;
			return 0;
		}
	}
	//sort(arr, arr + N); // 정렬하는 줄ㅎㅎ
	start = 0; end = 0; sum = arr[0]; // 우선 start = end = 0인 상태로 시작하므로 sum = arr[0]이다.
	while (start <= end && end < N){
		if (sum < S){ // 오른쪽으로 확장하면 값이 커짐
			sum += arr[++end];
		}
		else if (sum == S){ // 위의 경우와 같음
			min_length = min(min_length, end - start + 1);
			sum += arr[++end];
		}
		else { // 왼쪽 값을 없애 sum의 값을 줄임
			min_length = min(min_length, end - start + 1);
			sum -= arr[start++];
		}
	}
	if (min_length == 999999){ // 답을 만족시키는 부분수열이 없음
		cout << 0;
		return 0;
	}
	cout << min_length;
	return 0;
}