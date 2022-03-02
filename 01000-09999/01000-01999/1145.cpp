//1145 적어도 대부분의 배수
//https://www.acmicpc.net/problem/1145
#include <iostream>
#include <algorithm>
using namespace std;

int answer[10] = {0, };

int GCD(int a, int b){
	return a % b ? GCD(b, a % b) : b; // 유클리드 호제법
}

int almost_LCM(int a, int b, int c){
	int lcm[3], gcd21, lcm21, gcd210;
	lcm[0] = a; lcm[1] = b; lcm[2] = c;
	sort(lcm, lcm + 3);
	gcd21 = GCD(lcm[2], lcm[1]);
	lcm21 = (lcm[2] / gcd21) * (lcm[1] / gcd21) * gcd21;
	gcd210 = GCD(lcm21, lcm[0]);
	return (lcm[0] / gcd210) * (lcm21 / gcd210) * gcd210;
}

int main(){
	int num[5], count = 0;
	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			for (int k = j + 1; k < 5; k++){
				answer[count++] = almost_LCM(num[i], num[j], num[k]);
			}
		}
	}
	sort(answer, answer + 10);
	cout << answer[0];
}