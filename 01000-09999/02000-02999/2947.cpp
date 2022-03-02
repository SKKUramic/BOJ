// 2947 나무조각
// https://www.acmicpc.net/problem/2947
#include <iostream>
using namespace std;

int main(){
	int arr[5];
	for (int i = 0; i < 5; i++){cin >> arr[i];}
	for (int i = 0; i < 5; i++){
		for (int j = 1; j < 5; j++){
			if (arr[j - 1] > arr[j]){
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				for (int k = 0; k < 5; k++){
					cout << arr[k] << ' ';
				}
				cout << '\n';
			}
		}
	}
}