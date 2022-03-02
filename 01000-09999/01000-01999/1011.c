// 1011 Fly me to the Alpha Centauri
#include <stdio.h>

int main(){
	int test, start, end, distance, k = 1, count = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d", &start, &end);
		distance = end - start;
		while (distance >= 2 * k){
			distance -= 2 * k;
			count += 2;
			k++;
		}
		while (distance > 0){
			if (distance >= k){
				distance -= k;
				count++;
			}
			k--;
		}
		printf("%d\n", count);
		k = 1;
		count = 0;
	}
}