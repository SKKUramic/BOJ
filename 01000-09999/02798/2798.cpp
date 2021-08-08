// 2798 블랙잭
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int arr[300001] = {0,};

int main(){
	int N, M, sum, max = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int k = j + 1; k < N; k++){
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && max < sum)
					max = sum;
			}
		}
	}
	cout << max;
}