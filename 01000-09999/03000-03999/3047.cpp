// 3047 ABC
// https://www.acmicpc.net/problem/3047
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s;
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	cin >> s;
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++){
		cout << arr[s[i] - 'A'] << ' ';
	}
}