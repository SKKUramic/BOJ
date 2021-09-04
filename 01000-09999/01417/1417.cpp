// 1417 국회의원 선거
// https://www.acmicpc.net/problem/1417
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Dasom_vote, N, count = 0;
	cin >> N;
	cin >> Dasom_vote;
	for (int i = 0; i < N - 1; i++){
		cin >> arr[i];
	}
	if (N == 1){
		cout << count;
		return 0;
	}
	sort(arr, arr + (N - 1));
	while (Dasom_vote <= arr[N - 2]){
		Dasom_vote++; arr[N - 2]--; count++;
		sort(arr, arr + (N - 1));
	}
	cout << count;
}