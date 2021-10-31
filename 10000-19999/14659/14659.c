// 14659 한조서열정리하고옴ㅋㅋ
// https://www.acmicpc.net/problem/14659
#include <stdio.h>

int arr[30001];

int main(){
	int N, maxhunt = -1, hunt = 0, hunter;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	hunter = arr[0];
	for (int n = 1; n < N; n++){
		if (hunter < arr[n]){
			if (maxhunt < hunt){maxhunt = hunt;}
			hunt = 0;
			hunter = arr[n];
		}
		else {
			hunt++;
		}
	}
	if (maxhunt < hunt){maxhunt = hunt;}
	printf("%d", maxhunt);
}