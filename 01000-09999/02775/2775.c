// 2775 부녀회장이 될테야
#include <stdio.h>

int people(int floor, int room){
	int person = 0;
	if (floor == 0){
		person = room;
	}
	else {
		for (int i = 1; i <= room; i++){
			person += people(floor - 1, i);
		}
	}
	return person;
}

int main(){
	int test, k, n;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", people(k, n));
	}
}