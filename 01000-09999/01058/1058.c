// 1058 친구
// https://www.acmicpc.net/problem/1058
#include <stdio.h>

int N;
int Friend_list[51][51] = {0, };

void Floyd_Warshall(int n){
	for (int k = 1; k <= n; k++){
		for (int start = 1; start <= n; start++){
			for (int end = 1; end <= n; end++){
				if (start == k || k == end || start == end){continue;}
				if (Friend_list[start][end] > Friend_list[start][k] + Friend_list[k][end]){
					Friend_list[start][end] = Friend_list[start][k] + Friend_list[k][end]; // 더 작은 값으로 갱신, 1 또는 2가 되며 이는 start와 end가 서로 친구라는 것을 보여줌
				}
			}
		}
	}
	return;
}

int main(){
	int answer = 0, count;
	char list[51];
	scanf("%d", &N);
	for (int n = 1; n <= N; n++){
		scanf("%s", list);
		for (int k = 1; k <= N; k++){
			if (list[k - 1] == 'Y'){
				Friend_list[n][k] = 1;
			}
			else {
				Friend_list[n][k] = 9999999;
			}
		}
	}
	Floyd_Warshall(N);
	for (int n = 1; n <= N; n++){
		count = 0;
		for (int k = 1; k <= N; k++){
			if (n != k && Friend_list[n][k] <= 2){count++;}
		}
		if (answer < count) {answer = count;}
	}
	printf("%d", answer);
}