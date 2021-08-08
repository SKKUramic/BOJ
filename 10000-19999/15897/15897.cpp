// 15897 잘못 구현한 에라토스테네스의 체
// https://www.acmicpc.net/problem/15897
// https://js1jj2sk3.tistory.com/109에 소개된 코드입니다. 이런 풀이도 있군요ㄷㄷ
#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long int count = 0, temp_count;
	cin >> n;
	n--; // 보정을 위해 n을 1 뺌
	for (int i = n + 1; i != 0; i = n / ((n / i) + 1)){ // n + 1이 원래 값
		count += (n / i + 1) * (i - (n / ((n / i) + 1))); 
	}
	// (n / i + 1): 사이클 횟수, n--을 한 이후 i = n + 1이 초기값인 이유는 만약 보정이 없었으면 (n / i + 1) = 2가 되었기 때문이다.
	// (n / ((n / i) + 1)): 사이클 횟수가 (n / i + 1)회보다 큰 수들 중 가장 큰 수
	// (i - (n / ((n / i) + 1))): 사이클 횟수가 (n / i + 1)회인 수의 개수, 현재 i는 포함되며, 다음 i의 값은 포함되지 않는다. 즉, 그 수의 개수를 k라고 할 때 (다음 i) < k < (현재 i)
	/*
	for (int i = 1; i <= N; i++){
		temp_count = 0;
		temp_count += (N / i) + ((N % i == 0) ? 0 : 1);
		cout << "i: " << i << ", current_count: " << temp_count << '\n';
		count += temp_count;
	}*/ //타임아웃
	cout << count;
}