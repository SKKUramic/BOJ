// 2526 싸이클
// https://www.acmicpc.net/problem/2526
#include <stdio.h>

int visited[100];

int main(){
	int N, P, num = 0, temp, cycle, answer = 0;
	for (int i = 0; i < 100; i++){visited[i] = -1;}
	scanf("%d %d", &N, &P);
	temp = N % P;
	visited[temp] = num++;
	while (1){
		temp = temp * N % P;
		if (visited[temp] != -1){
			cycle = visited[temp];
			break;
		}
		visited[temp] = num++;
	}
	if (visited[0] != -1){printf("1");}
	else {
		for (int i = 0; i < P; i++){
			if (visited[i] >= cycle){answer++;}
		}
		printf("%d", answer);
	}
}