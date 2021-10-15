// 2547 사탕 선생 고창영
// https://www.acmicpc.net/problem/2547
#include <stdio.h>

int main(){
	long long TC, student, candy, num;
	scanf("%lld", &TC);
	while (TC-- > 0){
		candy = 0;
		scanf("%lld", &student);
		for (long long s = 0; s < student; s++){
			scanf("%lld", &num);
			candy += num;
			candy %= student;
		}
		if (candy % student == 0){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}