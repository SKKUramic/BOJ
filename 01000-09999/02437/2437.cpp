// 2437 저울
// https://www.acmicpc.net/problem/2437
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
int weight[1001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> len;
	for (int i = 0; i < len; i++){
		cin >> weight[i];
	}
	sort(weight, weight + len);
	int idx = 0, answer = 0;
	while (idx < len){
		if (answer + 1 < weight[idx]){
			break;
		}
		else {
			answer += weight[idx];
		}
		idx++;
	}
	cout << answer + 1;
}