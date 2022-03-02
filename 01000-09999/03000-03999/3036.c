// 3036 링
#include <stdio.h>

int ring[100];
int gcd[100];

int Euclidean(int a, int b){
	return a % b ? Euclidean(b, a % b) : b;
}

int main(){
	int ring_count, ring_stand;
	scanf("%d", &ring_count);
	scanf("%d", &ring_stand);
	for (int i = 0; i < ring_count - 1; i++){
		scanf("%d", &ring[i]);
		gcd[i] = ring_stand > ring[i] ? Euclidean(ring_stand, ring[i]) : Euclidean(ring[i], ring_stand);
	}
	for (int i = 0; i < ring_count - 1; i++){
		printf("%d/%d\n", ring_stand / gcd[i], ring[i] / gcd[i]);
	}
}