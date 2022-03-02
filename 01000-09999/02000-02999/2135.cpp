// 2135 문자열 압축하기
// https://www.acmicpc.net/problem/2135
#include <iostream>
#include <string>
using namespace std;

int len;
string sentence;
int DP[201][201] = {0, };
int divisors[201][30] = {0, }; // 혹시 모르니 넉넉하게

int min(int a, int b){return a < b ? a : b;}

void FindDivisors(int N){
	int idx;
	for (int n = 1; n <= N; n++){
		idx = 0;
		for (int k = 1; k < n; k++){
			if (n % k == 0){divisors[n][idx++] = k;}
		}
	}
	return;
}

int number_length(int cnt){
	int ret = 0;
	while (cnt != 0){
		ret++;
		cnt /= 10;
	}
	return ret;
}

bool compress(int start, int end, int step){
	string pivot = sentence.substr(start, step);
	for (int idx = start; idx < end; idx += step){
		if (pivot != sentence.substr(idx, step)){
			return false;
		}
	}
	return true;
}

int main(){
	int LEN, step;
	cin >> sentence;
	len = sentence.length();
	FindDivisors(len);
	for (int i = 0; i < len; i++){
		DP[i][i] = 1;
	}
	for (int k = 2; k <= len; k++){
		for (int start = 0; start <= len - k; start++){
			LEN = k; // 그냥 알파벳 개수
			for (int x = 0; divisors[k][x] != 0; x++){
				step = divisors[k][x];
				if (compress(start, start + k, step) == true){
					LEN = min(LEN, DP[start][start + step - 1] + number_length(k / step) + 2); // 지금까지의 DP + 반복되는 문자열의 개수를 숫자로 썼을 떄의 길이 + 괄호
				}
			}
			for (int i = start + 1; i < start + k; i++){
				LEN = min(LEN, DP[start][i - 1] + DP[i][start + k - 1]);
			}
			DP[start][start + k - 1] = LEN;
		}
	}
	cout << DP[0][len - 1];
}