// 2966 찍기
// https://www.acmicpc.net/problem/2966
#include <stdio.h>

char Adrian[3] = {'A', 'B', 'C'};
char Bruno[4] = {'B', 'A', 'B', 'C'};
char Goran[6] = {'C', 'C', 'A', 'A', 'B', 'B'};

int main(){
	int len;
	int Adrian_score = 0, Bruno_score = 0, Goran_score = 0, max_score = -1;
	char test[101];
	scanf("%d", &len);
	scanf("%s", test);
	for (int i = 0; i < len; i++){
		if (Adrian[i % 3] == test[i]){Adrian_score++;}
		if (Bruno[i % 4] == test[i]){Bruno_score++;}
		if (Goran[i % 6] == test[i]){Goran_score++;}
	}
	if (Adrian_score > max_score){max_score = Adrian_score;}
	if (Bruno_score > max_score){max_score = Bruno_score;}
	if (Goran_score > max_score){max_score = Goran_score;}
	
	printf("%d\n", max_score);
	if (Adrian_score == max_score){printf("Adrian\n");}
	if (Bruno_score == max_score){printf("Bruno\n");}
	if (Goran_score == max_score){printf("Goran\n");}
}