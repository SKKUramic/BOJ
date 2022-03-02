// 1904 01타일
#include <iostream>
using namespace std;

int save[1000001] = {0, };

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, answer;
	cin >> N;
	save[0] = 0; save[1] = 1; save[2] = 2;
	for (int i = 3; i <= N; i++){
		save[i] = ((save[i - 1] % 15746) + (save[i - 2] % 15746)) % 15746;
	}
	cout << save[N];
}