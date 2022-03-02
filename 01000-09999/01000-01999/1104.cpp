// 1104 패턴
// https://www.acmicpc.net/problem/1104
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

int main(){
	ull S1_len, S2_len;
	ull S1_start = 0, S1_end = 0, S2_start = 0, S2_end = 0;
	ull temp = 0, ans_idx = 0, MAX = 10000000000000000;
	ull N, S1_Nidx = MAX + 1, S2_Nidx = MAX + 1;
	string S1, S2;
	bool S1_zero = true, S2_zero = true;
	
	cin >> S1;
	cin >> S2;
	cin >> N;
	S1_len = S1.length();
	S2_len = S2.length();
	for (long long i = 0; i < S1_len; i++){
		if (S1[i] == '1'){
			temp = 0;
			S1_zero = false;
		}
		else {
			temp++;
		}
		if (temp == N && S1_Nidx == MAX + 1){
			S1_Nidx = i + 1 - temp;
			break;
		}
	}
	for (long long i = 0; i < S2_len; i++){
		if (S2[i] == '1'){
			temp = 0;
			S2_zero = false;
		}
		else {
			temp++;
		}
		if (temp == N && S2_Nidx == MAX + 1){
			S2_Nidx = i + 1 - temp;
			break;
		}
	}
	for (long long i = 0; i < S1_len; i++){
		if (S1[i] == '1'){break;}
		else {S1_start++;}
	}
	for (long long i = 0; i < S2_len; i++){
		if (S2[i] == '1'){break;}
		else {S2_start++;}
	}
	for (long long i = S1_len - 1; i >= 0; i--){
		if (S1[i] == '1'){break;}
		else {S1_end++;}
	}
	for (long long i = S2_len - 1; i >= 0; i--){
		if (S2[i] == '1'){break;}
		else {S2_end++;}
	}
	if (S1_zero == true && S2_zero == true){
		cout << 0;
		return 0;
	}
	else if (S1_zero == true && S2_zero == false){ // Case 1, 4
		if (S1_len * 1000000 + S2_start >= N){
			cout << 0;
		}
		else if (S2_end + S1_len * 1000000 + S2_start >= N){ // Case 8
			cout << S1_len * 1000000 + S2_len - S2_end;
		}
		else {
			cout << "-1";
		}
	}
	else if (S1_zero == false && S2_zero == true){
		if (S1_start >= N){ // Case 1
			cout << 0;
		}
		else if (S1_Nidx != MAX + 1){ // Case 1
			cout << S1_Nidx;
		}
		else if (S1_end + S1_start >= N){ // Case 3
			cout << S1_len - S1_end;
		}
		else if (S1_end + S2_len + S1_start >= N){ // Case 9
			cout << S1_len * 1000000 - S1_end;
		}
		else { // 가장 에러 잡기 힘들었던 부분 (Case 9)
			temp = (N - S1_end - S1_start) / S2_len;
			if (temp * S2_len + S1_end + S1_start < N){temp++;}
			if (temp > 200000000){
				cout << "-1";
			}
			else {
				ans_idx = S1_len * 1000000 * temp + S2_len * (temp * (temp - 1) / 2) - S1_end;
				if (ans_idx + N - 1 >= MAX){cout << "-1";}
				else {cout << ans_idx;}
			}
		}
	}
	else if (S1_zero == false && S2_zero == false){
		if (S1_start >= N){ // Case 1
			cout << 0;
		}
		else if (S1_Nidx != MAX + 1){ // Case 1
			cout << S1_Nidx;
		}
		else if (S1_end + S1_start >= N){ // Case 3
			cout << S1_len - S1_end;
		}
		else if (S1_end + S2_start >= N){ // Case 4
			cout << S1_len * 1000000 - S1_end;
		}
		else if (S2_Nidx != MAX + 1){ // Case 2
			cout << S1_len * 1000000 + S2_Nidx;
		}
		else if (S2_end + S1_start >= N){ // Case 5
			cout << S1_len * 1000000 + S2_len - S2_end;
		}
		else if (S2_end + S2_start >= N){ // Case 6
			cout << S1_len * 2000000 + S2_len * 2 - S2_end;
		}
		else {
			cout << "-1";
		}
	}
}
/*
Case 1: S1
Case 2: S2
Case 3: S1 + S1
Case 4: S1 + S2
Case 5: S2 + S1
Case 6: S2 + S2
Case 7: S1 * 10^6 + S2
Case 8: S2 + S1 + S2
Case 9: S1 + S2 + S1
Case 10: S1 + S2 + S1(S1은 1로 끝남)
*/