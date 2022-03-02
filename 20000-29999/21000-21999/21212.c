// 21212 Cakes
// https://www.acmicpc.net/problem/21212
// 케이크를 많이 만들고 싶다. 필요한 재료량과 현재량을 비교했을 때, 최대한 케이크를 만들면 몇 개?
#include <stdio.h>

int main(){
	int ingredients, need, have, min_cake = 99999;
	scanf("%d", &ingredients);
	for (int i = 0; i < ingredients; i++){
		scanf("%d %d", &need, &have);
		if (min_cake > have / need){
			min_cake = have / need;
		}
	}
	printf("%d", min_cake);
}