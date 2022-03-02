// 15655 N과 M (10)
// https://www.acmicpc.net/problem/15664
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[8];
vector<string> already;
int arr_len, print_count;

void print_arr(int num, int k, string s){
	if (num == 0){
		for (int i = 0; i < already.size(); i++){
			if (already[i].compare(s) == 0){return;}
		}
		cout << s << '\n';
		already.push_back(s);
		return;
	}
	for (int i = k + 1; i < arr_len; i++){
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