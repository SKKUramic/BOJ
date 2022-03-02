// 10817 세 수
// https://www.acmicpc.net/problem/10817
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int arr[3];
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	printf("%d", arr[1]);
}