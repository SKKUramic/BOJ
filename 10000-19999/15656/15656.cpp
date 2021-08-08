// 15655 N과 M (7)
// https://www.acmicpc.net/problem/15656
#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
int arr_len, print_count;

void print_arr(int num, int k, string s){
	if (num == 0){
		cout << s << '\n';
		return;
	}
	for (int i = 0; i < arr_len; i++){
		print_arr(num - 1, i, s + " " + to_string(arr[i]));
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr_len >> print_count;
	for (int i = 0; i < arr_len; i++){
		cin >> arr[i];
	}
	sort(arr, arr + arr_len);
	for (int i = 0; i < arr_len; i++){
		print_arr(print_count - 1, i, to_string(arr[i]));
	}
}