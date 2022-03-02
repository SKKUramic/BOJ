// 16172 나는 친구가 적다 (Large)
// https://www.acmicpc.net/problem/16172
// KMP 알고리즘 사용 문제, 1786 찾기 문제의 함수를 차용했습니다.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 300001

string temp, find_word;
vector<char> sentence; 
int pi[MAX];

int KMP(const vector<char> array, const string cmp){
	int start = 0, cmp_idx = 0;
	int array_len = array.size();
	int cmp_len = cmp.length();
	while (start <= array_len - cmp_len){
		if (cmp_idx < cmp_len && array[start + cmp_idx] == cmp[cmp_idx]){
			cmp_idx++;
			if (cmp_idx == cmp_len){ // 존재할 경우
				return 1;
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
	return 0;
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
	int temp_len;
	cin >> temp;
	cin >> find_word;
	temp_len = temp.length();
	for (int i = 0; i < temp_len; i++){
		if (temp[i] < '0' || temp[i] > '9'){
			sentence.push_back(temp[i]);
		}
	}
	Failure_function(find_word);
	cout << KMP(sentence, find_word);
}