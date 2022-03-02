// 3237 두 수의 합
// https://www.acmicpc.net/problem/3273
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
	int len, x, count = 0, start, end;
	scanf("%d", &len);
	start = 0; 
	end = len - 1;
	for (int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	sort(arr, arr + len);
	while (start < end){
		if (arr[start] + arr[end] == x){
			count++;
			start++;
		}
		else if (arr[start] + arr[end] < x){
			start++;
		}
		else {
			end--;
		}
	}
	cout << count;
}