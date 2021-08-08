// 1074 Z
#include <bits/stdc++.h>

using namespace std;

int position(int pos, int N, int r, int c){
	int cor = pow(2, N - 1);
	int plus = cor * cor;
	if (N == 0){
		if (r == 1){
			if (c == 1){
				pos += 3;
			}
			else {
				pos += 2;
			}
		}
		else {
			if (c == 1){
				pos += 1;
			}
			else {
				
			}
		}
	}
	else {
		if (r >= cor){
			if (c >= cor){ // 오른쪽 아래에 있을 때
				pos += plus * 3;
				c -= cor;
			}
			else { // 왼쪽 아래에 있을 때
				pos += plus * 2;
			}
			r -= cor;
		}
		else {
			if (c >= cor){ // 오른쪽 위에 있을 때
				pos += plus;
				c -= cor;
			}
			else { // 왼쪽 위에 있을 때
				// 아무것도 없음
			}
		}
	}
	if (N == 0){
		return pos;
	}
	return position(pos, N - 1, r, c);
}

int main(){
	int N, r, c, ans;
	int pos = 0;
	cin >> N >> r >> c;
	ans = position(pos, N, r, c);
	cout << ans;
}