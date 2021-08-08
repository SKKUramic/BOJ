// 16916 부분 문자열
// https://www.acmicpc.net/problem/16916
// 1786 찾기 문제의 코드와 입력 부분을 제외하면 동일합니다. 이걸 먼저 풀어봤어야 했는데
#include <iostream>
#include <string>
using namespace std;

#define MAX 1000001

string arr, input;
int pi[MAX];
int answer_pos[MAX];
int answer_idx = 0;

int KMP(const string array, const string cmp){
	int start = 0, cmp_idx = 0, count = 0;
	int array_len = array.length();
	int cmp_len = cmp.length();
	while (start <= array_len - cmp_len){
		if (cmp_idx < cmp_len && array[start + cmp_idx] == cmp[cmp_idx]){
			cmp_idx++;
			if (cmp_idx == cmp_len){
				count++;
				answer_pos[answer_idx++] = start; // 같은 문자열이 존재할 경우 첫 글자의 위치를 배열에 넣음
			}
		}
		else {
			if (cmp_idx == 0){start++;}
			else {
				start += (cmp_idx - pi[cmp_idx - 1]);
				cmp_idx = pi[cmp_idx - 1];
			}
		}
	}
	return count;
}

void Failure_function(const string array){
	int start = 1, array_idx = 0;
	int len = array.length();
	pi[0] = 0;
	while (start + array_idx < len){ // failure function
		if (array[start + array_idx] == array[array_idx]){ // 비교하고 있는 두 문자가 서로 같을 때
			array_idx++;
			pi[start + array_idx - 1] = array_idx; // 연속해서 같은 문자가 하나 더 생김
		}
		else { // 같지 않을 때
			if (array_idx == 0){ // 처음부터 틀렸으면 start를 한 칸 오른쪽으로 옮김
				start++;
			}
			else {
				start += (array_idx - pi[array_idx - 1]); // start를 적절한 위치로 옮김
				array_idx = pi[array_idx - 1]; // 연속한 문자의 개수 조정
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer_count;
	cin >> arr;
	cin >> input;
	Failure_function(input);
	answer_count = KMP(arr, input);
	if (answer_count != 0){ // arr 문자열 안에 input이 존재한다면
		cout << '1';
	}
	else {
		cout << '0';
	}
}