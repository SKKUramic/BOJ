// 7345 다항식의 나머지 연산
// https://www.acmicpc.net/problem/7345
#include <stdio.h>
#include <string.h>

int Fx[2001], Gx[2001], Hx[2001], Rx[2001];
int F, G, H, R;

int main(){
	int TC;
	scanf("%d", &TC);
	while (TC-- > 0){
		memset(Rx, 0, 2001 * sizeof(int));
		scanf("%d", &F);
		for (int f = F - 1; f >= 0; f--){scanf("%d", &Fx[f]);}
		scanf("%d", &G);
		for (int g = G - 1; g >= 0; g--){scanf("%d", &Gx[g]);}
		scanf("%d", &H);
		for (int h = H - 1; h >= 0; h--){scanf("%d", &Hx[h]);}
		for (int f = 0; f < F; f++){ // 곱셈
			for (int g = 0; g < G; g++){
				Rx[f + g] ^= (Fx[f] & Gx[g]);
			}
		}
		R = F + G; // Fx와 Gx 둘을 곱한 다항식 Rx의 최고차항 계수
		while (1){
			if (Rx[R] == 0){R--; continue;} // 최고차항이 있어야 하는데 없으면 그냥 스킵함
			if (R + 1 < H){break;} // 나눈 식보다 최고차항이 낮으면 나머지가 결정된 것이므로 종료
			for (int r = R, h = H - 1; h >= 0; r--, h--){ // Rx와 Hx의 계수를 맞춘 후, 뺄샘
				Rx[r] ^= Hx[h];
			}
			R--;
		}
		printf("%d ", R + 1);
		for (int r = R; r >= 0; r--){printf("%d ", Rx[r]);}
		printf("\n");
	}
}