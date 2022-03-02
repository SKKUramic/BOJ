// 9237 이장님 초대
// https://www.acmicpc.net/problem/9237
// 이게 왜 맞지
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, longest_day, DAY;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<>());
	longest_day = arr[0];
	DAY = 1;
	for (int i = 1; i < N; i++){
		longest_day--;
		if (longest_day < arr[i]){
			longest_day = arr[i];
		}
		DAY++;
	}
	DAY += longest_day;
	DAY++;
	cout << DAY;
}