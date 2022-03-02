// 13282 Bamboo Blossoms
// http://codersbrunch.blogspot.com/의 코드입니다
// 정말 대단하십니다ㅠㅠ
//#include <cstdio>
#include <stdio.h>

int m, n, p[8000001];
int main() {
    for (int i = 1; i <= 8e6; i++){
		for (int j = i * 2; j <= 8e6; j += i) {
			p[j] = i; //p[j]은 j의 약수 중 자기 자신을 제외한, 가장 큰 약수
		}
	}
	scanf("%d%d", &m, &n);
    while (m != 0 && n != 0) {
        for (int i = m;; i++){
			if (!~(n -= p[i] < m)) { // 이게 최고의 코드임, n = -1일 때 참이 되며, p[i] < m을 만족하면 n--이 실행된다.
				printf("%d\n", i);
				break;
			}
		} 
		scanf("%d%d", &m, &n);
    }
    return 0;
}