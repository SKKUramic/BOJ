// 15727 조별과제를 하려는데 조장이 사라졌다
#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	if (t % 5 == 0){
		t = t / 5;
	}
	else {
		t = t / 5 + 1;
	}
	printf("%d", t);
}