// 3806 S를 T로
// https://www.acmicpc.net/problem/3806
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int S_count[2], T_count[2];
	int TC, count, diff, case_num = 1;
	string S, T;
	cin >> TC;
	while (TC-- > 0){
		cin >> S;
		cin >> T;
		count = 0; diff = 0;
		S_count[0] = 0; S_count[1] = 0;
		T_count[0] = 0; T_count[1] = 0;
		for (int i = 0; i < S.length(); i++){
			if (S[i] != '?'){
				S_count[S[i] - '0']++;
				if (S[i] != T[i]){
					diff++;
				}
			}
			T_count[T[i] - '0']++;
		}
		for (int i = 0; i < S.length(); i++){ // ?를 T와 같은 숫자로 바꾸는 작업
			if (S[i] == '?'){
				if (T[i] == '0'){
					S[i] = '0';
					S_count[0]++;
				}
				else if (T[i] == '1'){
					if (S_count[1] < T_count[1]){
						S[i] = '1';
						S_count[1]++;
					}
					else {
						S[i] = '0';
						S_count[0]++;
						diff++;
					}
				}
				count++;
			}
		}
		if (S_count[1] > T_count[1]){ // S에 있는 1이 T에 있는 1보다 많을 경우
			cout << "Case " << case_num << ": -1\n";
		}
		else {
			while (S_count[1] != T_count[1]){ // 0에서 1로 바꾸는 작업
				count++;
				diff--;
				S_count[1]++;
				S_count[0]--;
			}
			while (diff > 0){ // 0과 1의 위치를 바꾸는 작업
				count++;
				diff -= 2;
			}
			cout << "Case " << case_num << ": " << count << "\n";
		}
		case_num++;
	}
}