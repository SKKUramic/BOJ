// 1300 K번째 수
// https://www.acmicpc.net/problem/1300
// 욱제님의 풀이(http://wookje.dance/2017/02/20/boj-1300-K%EB%B2%88%EC%A7%B8-%EC%88%98/)를 보고 이해한 후 작성한 코드입니다. 이게 이분 탐색?
#include <iostream>
#include <algorithm>
using namespace std;

long long int answer, n, k;

long long BinarySearch(long long int left, long long int right){
	if (left > right){
		return left;
	}
	long long int middle = (left + right) / 2; // 양쪽 끝의 중간 지점
	long long int count = 0;
	for (int i = 1; i <= n; i++){
		if (n > middle / i){
			count += middle / i; // i행의 배수들 중 middle보다 작은 수들의 개수
		}
		else { // middle / i이 N보다 크면 그냥 N개 모두를 포함하는 것으로 가정한다.
			count += n;
		}
	}
	if (count < k){ // middle보다 작은 숫자가 k보다 작을 때 middle의 크기를 키운다.
		return BinarySearch(middle + 1, right);
	}
	else { // middle보다 작은 숫자가 k개보다 많을 때, middle의 크기를 작게 한다.
		return BinarySearch(left, middle - 1);
	}
}

int main(){
	cin >> n >> k;
	answer = BinarySearch(1, k); // 맨 왼쪽과 맨 오른쪽의 주소를 넣음
	cout << answer;
}