// 1016 제곱ㄴㄴ수
// https://www.acmicpc.net/problem/1016
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long min, max;
	cin >> min >> max;
	vector<bool> nono_sqaure_num(max - min + 1, false);
	long long i = 2, stand, answer = 0;
	while (i * i <= max){
		stand = (min / (i * i)) * (i * i);
		if (stand < min) {stand += i * i;}
		while (stand <= max){
			nono_sqaure_num[stand - min] = true;
			stand += i * i;
		}
		i++;
	}
	for (long long i = 0; i < max - min + 1; i++){
		if (nono_sqaure_num[i] == false){
			answer++;
		}
	}
	cout << answer;
}