// 11948 과목선택
// https://www.acmicpc.net/problem/11948
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[6];
	for (int i = 0; i < 6; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 4);
	sort(arr + 4, arr + 6);
	printf("%d", arr[1] + arr[2] + arr[3] + arr[5]);
}