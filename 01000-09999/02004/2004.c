// 2004 조합 0의 개수
// https://www.acmicpc.net/problem/2004
// 다 계산했다가는 감당이 안 되는 문제, 2와 5가 몇개 있는지만 알면 됩니다.
#include <stdio.h>

long long int POW_TWO(long long int X){
	long long int ret = 0;
	long long int TWO = 2;
	while (X >= TWO){
		ret += X / TWO;
		TWO *= 2;
	}
	return ret;
}

long long int POW_FIVE(long long int X){
	long long int ret = 0;
	long long int FIVE = 5;
	while (X >= FIVE){
		ret += X / FIVE;
		FIVE *= 5;
	}
	return ret;
}

int main(){ // mCn을 계산한 값의 맨 끝에 0이 몇 개 연속으로 있는지 구하는 문제
	long long int m, n, m_n;
	long long int m_two, m_five, n_two, n_five, m_n_two, m_n_five;
	long long int two_sum = 0, five_sum = 0;
	scanf("%lld %lld", &m, &n);
	if (n == 0) {
		printf("0");
		return 0;
	}
	m_n = m - n;
	m_two = POW_TWO(m); n_two = POW_TWO(n); m_n_two = POW_TWO(m_n);
	m_five = POW_FIVE(m); n_five = POW_FIVE(n); m_n_five = POW_FIVE(m_n);
	two_sum = m_two - m_n_two - n_two;
	five_sum = m_five - m_n_five - n_five;
	printf("%lld", two_sum < five_sum ? two_sum : five_sum);
}