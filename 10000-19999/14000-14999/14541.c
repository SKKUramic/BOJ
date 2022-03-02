// 14541 Speed Limit
// https://www.acmicpc.net/problem/14541
#include <stdio.h>

int v[10];
int t[10];

int main(){
	int n, total_miles;
	scanf("%d", &n);
	while (n != -1){
		for (int i = 0; i < n; i++){
			scanf("%d %d", &v[i], &t[i]);
		}
		for (int i = n - 1; i > 0; i--){
			t[i] -= t[i - 1];
		}
		total_miles = 0;
		for (int i = 0; i < n; i++){
			total_miles += v[i] * t[i];
		}
		printf("%d miles\n", total_miles);
		scanf("%d", &n);
	}
	return 0;
}