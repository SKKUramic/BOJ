// 2422 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
// https://www.acmicpc.net/problem/2422
#include <iostream>
using namespace std;

bool donotmix[201][201];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, x, y, count = 0;
	cin >> N >> M;
	for (int m = 0; m < M; m++){
		cin >> x >> y;
		donotmix[x][y] = true; donotmix[y][x] = true;
	}
	for (int a = 1; a <= N; a++){
		for (int b = a + 1; b <= N; b++){
			for (int c = b + 1; c <= N; c++){
				if (donotmix[a][b] == true || donotmix[b][c] == true || donotmix[c][a] == true){
					continue;
				}
				count++;
			}
		}
	}
	cout << count;
}