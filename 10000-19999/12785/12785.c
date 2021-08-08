// 12785 토쟁이의 등굣길
// https://www.acmicpc.net/problem/12785
#include <stdio.h>

int path_dp[201][201] = {0, };

int main(){
	int W, H, X, Y;
	scanf("%d %d", &W, &H);
	scanf("%d %d", &X, &Y);
	for (int x = 1; x <= X; x++){
		for (int y = 1; y <= Y; y++){
			if (x == 1 || y == 1){path_dp[x][y] = 1;}
			else {path_dp[x][y] = (path_dp[x - 1][y] + path_dp[x][y - 1]) % 1000007;}
		}
	}
	for (int x = X; x <= W; x++){
		for (int y = Y; y <= H; y++){
			if (x == X || y == Y){path_dp[x][y] = path_dp[X][Y];}
			else {path_dp[x][y] = (path_dp[x - 1][y] + path_dp[x][y - 1]) % 1000007;}
		}
	}
	printf("%d", path_dp[W][H]);
}