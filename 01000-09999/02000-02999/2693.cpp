// 2693 N번째 큰 수
// https://www.acmicpc.net/problem/2693
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[10];
	int T;
	cin >> T;
	while (T-- > 0){
		for (int i = 0; i < 10; i++){cin >> arr[i];}
		sort(arr, arr + 10);
		cout << arr[7] << '\n';
	}
}