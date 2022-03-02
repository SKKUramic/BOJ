// 7568 덩치
#include <stdio.h>

int human[51][3]; //[0] = weight, [1] = height, [2] = ranking

int main(){
	int test, rank;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d", &human[i][0], &human[i][1]);
	}
	for (int i = 0; i < test; i++){
		rank = 1;
		for (int j = 0; j < test; j++){
			// if (i == j){continue;}
			if (human[i][0] < human[j][0] && human[i][1] < human[j][1]){rank++;}
		}
		human[i][2] = rank;
	}
	for (int i = 0; i < test; i++){
		printf("%d ", human[i][2]);
	}
}