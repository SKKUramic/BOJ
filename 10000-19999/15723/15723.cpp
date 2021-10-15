// 15723 n단 논법
// https://www.acmicpc.net/problem/15723
#include <iostream>
using namespace std;

bool Syllogism[30][30];
int N, M;

void Floyd(){
	for (int also = 0; also < 26; also++){
		for (int it = 0; it < 26; it++){
			for (int then = 0; then < 26; then++){
				if (Syllogism[it][also] == true && Syllogism[also][then] == true){
					Syllogism[it][then] = true;
				}
			}
		}
	}
	return;
}

int main(){
	char It, Then;
	int Aidx, Bidx;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf(" %c is %c", &It, &Then);
		Aidx = It - 'a'; 
		Bidx = Then - 'a';
		Syllogism[Aidx][Bidx] = true;
	}
	Floyd();
	scanf("%d", &M);
	for (int m = 0; m < M; m++){
		scanf(" %c is %c", &It, &Then);
		Aidx = It - 'a'; 
		Bidx = Then - 'a';
		if (Syllogism[Aidx][Bidx] == true){
			printf("T\n");
		}
		else {
			printf("F\n");
		}
	}
}