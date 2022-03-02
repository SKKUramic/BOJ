// 2231 분해합
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main(){
	int num, sum, temp, answer = 0;
	cin >> num;
	for (int i = 1; i <= 1000000; i++){
		temp = i;
		sum = i;
		while (temp > 0){
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == num){
			answer = i;
			break;
		}
	}
	cout << answer;
}