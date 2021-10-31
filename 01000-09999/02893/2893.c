// 2893 XOR 도형
// https://www.acmicpc.net/problem/2893
#include <stdio.h>

typedef struct Triangle{
	long long x;
	long long y;
	long long z;
}Triangle;

int tri;
long long answer = 0;
Triangle arr[10];

void triangle_area(int idx, Triangle T, long long count){
	if (idx == tri - 1){
		if (T.x + T.y < T.z){
			long long Tlen = T.z - (T.x + T.y);
			answer += Tlen * Tlen * count;
		}
		return;
	}
	Triangle Ttemp = T;
	if (Ttemp.x < arr[idx + 1].x){Ttemp.x = arr[idx + 1].x;}
	if (Ttemp.y < arr[idx + 1].y){Ttemp.y = arr[idx + 1].y;}
	if (Ttemp.z > arr[idx + 1].z){Ttemp.z = arr[idx + 1].z;}
	triangle_area(idx + 1, Ttemp, count * -2LL);
	triangle_area(idx + 1, T, count);
	return;
}

int main(){
	scanf("%d", &tri);
	for (int t = 0; t < tri; t++){
		scanf("%lld %lld %lld", &arr[t].x, &arr[t].y, &arr[t].z);
		arr[t].z += (arr[t].x + arr[t].y);
	}
	for (int t = 0; t < tri; t++){
		triangle_area(t, arr[t], 1);
	}
	if (answer % 2 == 1){
		printf("%lld.5", answer / 2);
	}
	else {
		printf("%lld.0", answer / 2);
	}
}