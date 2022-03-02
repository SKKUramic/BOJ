// 2470 두 용액
// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long int arr[100001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int diff = 2000000001;
	int len, start, end;
	int start_idx, end_idx;
	cin >> len;
	start = 0; end = len - 1;
	start_idx = 0; end_idx = len - 1;
	for (int i = 0; i < len; i++){
		cin >> arr[i];
	}
	sort(arr, arr + len);
	while (start < end){
		if (arr[end] + arr[start] == 0){
			start_idx = start;
			end_idx = end;
			break;
		}
		else if (arr[end] + arr[start] < 0){
			if (abs(arr[end] + arr[start]) < diff){
				start_idx = start;
				end_idx = end;
				diff = abs(arr[end] + arr[start]);
			}
			start++;
		}
		else if (arr[end] + arr[start] > 0){
			if (abs(arr[end] + arr[start]) < diff){
				start_idx = start;
				end_idx = end;
				diff = abs(arr[end] + arr[start]);
			}
			end--;
		}
	}
	printf("%lld %lld", arr[start_idx], arr[end_idx]);
}