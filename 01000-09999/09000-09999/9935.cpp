// 9935 문자열 폭발
// https://www.acmicpc.net/problem/9935
// stack을 사용하지 않은 코드입니다. 근데 왜 스택을 쓰지?
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

vector<char> v;
string is_BOMB, BOMB;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int BOMB_len = 0, is_BOMB_len = 0, BOMB_idx, v_size, BOMB_count;
	bool find_BOMB;
	cin >> is_BOMB >> BOMB;
	is_BOMB_len = is_BOMB.length();
	BOMB_len = BOMB.length();
	for (int i = 0; i < is_BOMB_len; i++){
		v.push_back(is_BOMB[i]);
		v_size = v.size();
		if (v.size() >= BOMB_len - 1){
			find_BOMB = true;
			BOMB_idx = 0;
			for (int idx = v_size - BOMB_len; idx < v_size; idx++){
				if (v[idx] != BOMB[BOMB_idx++]){
					find_BOMB = false;
					break;
				}
			}
			if (find_BOMB == true){
				int temp = BOMB_len;
				while (temp-- > 0){
					v.pop_back();
				}
			}
		}
	}
	if (v.size() != 0){
		for (int vv = 0; vv < v.size(); vv++){
			cout << v[vv];
		}
	}
	else {
		cout << "FRULA";
	}
}