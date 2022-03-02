// 1037 약수
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int num[51] = {0, };
int N;

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &num[i]);
	}
	sort(num, num + N);
	printf("%lld", num[0] * num[N - 1]);
}