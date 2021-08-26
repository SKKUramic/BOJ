// 2309 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>
using namespace std;

bool flag_100 = false;
bool is_not[10];
int arr[10];

int main(){
	int sum = 0;
	for (int i = 0; i < 9; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++){
		for (int j = i + 1; j < 9; j++){
			if (sum - arr[i] - arr[j] == 100){
				flag_100 = true;
				is_not[i] = true;
				is_not[j] = true;
				break;
			}
		}
		if (flag_100 == true){break;}
	}
	for (int i = 0; i < 9; i++){
		if (is_not[i] == false){
			cout << arr[i] << '\n';
		}
	}
}