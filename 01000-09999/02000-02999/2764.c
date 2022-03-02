// 2764 마지막 사진 찍기
// https://www.acmicpc.net/problem/2764
#include <stdio.h>
#include <string.h>

long long DP[31][16][11][9][6];
int L, L1, L2, L3, L4, L5;
int Line[5];

int main(){
	int T;
	scanf("%d", &T);
	while (T-- > 0){
		memset(DP, 0, sizeof(DP));
		memset(Line, 0, sizeof(Line));
		DP[1][0][0][0][0] = 1;
		scanf("%d", &L);
		for (int i = 0; i < L; i++){scanf("%d", &Line[i]);}
		L1 = Line[0]; L2 = Line[1]; L3 = Line[2]; L4 = Line[3]; L5 = Line[4];
		for (int i1 = 0; i1 <= L1; i1++){
			for (int i2 = 0; i2 <= L2; i2++){
				for (int i3 = 0; i3 <= L3; i3++){
					for (int i4 = 0; i4 <= L4; i4++){
						for (int i5 = 0; i5 <= L5; i5++){
							long long* ret = &DP[i1][i2][i3][i4][i5];
							if (i1 != 0){*ret += DP[i1 - 1][i2][i3][i4][i5];}
							if (i2 != 0 && i1 >= i2){*ret += DP[i1][i2 - 1][i3][i4][i5];} else {continue;}
							if (i3 != 0 && i2 >= i3){*ret += DP[i1][i2][i3 - 1][i4][i5];} else {continue;}
							if (i4 != 0 && i3 >= i4){*ret += DP[i1][i2][i3][i4 - 1][i5];} else {continue;}
							if (i5 != 0 && i4 >= i5){*ret += DP[i1][i2][i3][i4][i5 - 1];} else {continue;}
							//printf("%d %d %d %d %d : %lld\n", i1, i2, i3, i4, i5, *ret);
						}	
					}
				}
			}
		}
		printf("%lld\n", DP[L1][L2][L3][L4][L5]);
	}
}