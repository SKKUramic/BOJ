// 2587 대표값2
// https://www.acmicpc.net/problem/2587
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int average = 0;
	int arr[5];
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
		average += arr[i];
	}
	sort(arr, arr + 5);
	cout << average / 5 << '\n' << arr[2];
}