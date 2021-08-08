// 6246 풍선 놀이
// https://www.acmicpc.net/problem/6246
#include <iostream>
using namespace std;

bool balloon[10001];

int main(){
	int N, Q, start, i, count = 0;
	cin >> N >> Q;
	while (Q-- > 0){
		cin >> start >> i;
		for (int k = start; k <= N; k += i){
			balloon[k] = true;
		}
	}
	for (int k = 1; k <= N; k++){
		if (balloon[k] == false){
			count++;
		}
	}
	cout << count;
}