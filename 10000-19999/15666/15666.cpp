// 15666 N과 M (12)
// https://www.acmicpc.net/problem/15666
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[10];
vector<string> we_haved_printed; // ㅋㅋ 경우의 수를 다 저장하면 되지 뭐
int arr_len, print_count;

void print_arr(int num, int k, string s){
	if (num == 0){
		for (int x = 0; x < we_haved_printed.size(); x++){
			if (we_haved_printed[x].compare(s) == 0){ // 이미 중복이 있다면 리턴
				return;
			}
		}
		cout << s << '\n';
		we_haved_printed.push_back(s);
		return;
	}
	for (int idx = k; idx < arr_len; idx++){
		print_arr(num - 1, idx, s + " " + to_string(arr[idx]));
	}
	return;
}

int main(){
	cin >> arr_len >> print_count;
	for (int i = 0; i < arr_len; i++){
		cin >> arr[i];
	}
	sort(arr, arr + arr_len);
	for (int k = 0; k < arr_len; k++){
		print_arr(print_count - 1, k, to_string(arr[k]));
	}
}