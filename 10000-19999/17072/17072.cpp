// 17072 아스키 아트
// https://www.acmicpc.net/problem/17072
#include <iostream>
using namespace std;

char ascii(int r, int g, int b){
	int ret = 2126 * r + 7152 * g + 722 * b;
	if (0 <= ret && ret < 510000){return '#';}
	else if (510000 <= ret && ret < 1020000){return 'o';}
	else if (1020000 <= ret && ret < 1530000){return '+';}
	else if (1530000 <= ret && ret < 2040000){return '-';}
	else {return '.';}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, R, G, B;
	char p;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> R >> G >> B;
			cout << ascii(R, G, B);
		}
		cout << '\n';
	}
}