// 2997 네 번째 수
//https://www.acmicpc.net/problem/2997
#include <iostream>
#include <algorithm>
using namespace std;

int arr[4];

int main(){
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	if (arr[1] - arr[0] == arr[2] - arr[1]){
		cout << arr[2] + (arr[1] - arr[0]);
	}
	else if (arr[1] - arr[0] > arr[2] - arr[1]){
		cout << arr[1] - (arr[2] - arr[1]);
	}
	else {
		cout << arr[2] - (arr[1] - arr[0]);
	}
}