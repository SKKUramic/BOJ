// 2981 검문
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int answer[1001];

int GCD(int a, int b){
	if (a < b){
		return b % a ? GCD(a, b % a) : a;
	}
	else {
		return a % b ? GCD(b, a % b) : b;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, gcd, count = 0;
	//scanf("%d", &N);
	cin >> N;
	for (int i = 0; i < N; i++){
		//scanf("%d", &arr[i]);
		cin >> arr[i];
	}
	sort(arr, arr + N);
	gcd = arr[1] - arr[0];
	for (int i = 2; i < N; i++){
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}
	for (int i = 2; i * i <= gcd; i++){
		if (gcd % i == 0){
			answer[count++] = i;
			if (gcd / i != i){
				answer[count++] = gcd / i;
			}
		}
	}
	answer[count++] = gcd;
	sort(answer, answer + count);
	for (int i = 0; i < count; i++){
		cout << answer[i] << ' ';
	}
	/*
	for (int i = 0; i < count; i++){
		printf("%d\n", answer[i]);
	}
	for (int i = 0; i < count; i++){
		if (gcd / answer[i] != answer[i]){
			printf("%d\n", gcd / answer[count - i - 1]);
		}
	}
	printf("%d", gcd);*/
}