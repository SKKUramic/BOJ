// 7346 유전자 함수
// https://www.acmicpc.net/problem/7346
#include <iostream>
#include <cstring>
using namespace std;

int INF = 123456789;

const int score[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, -INF}
};
string Adna, Bdna;
int LengthA, LengthB;
int DP[101][101];

int retIDX(char c){
	if (c == 'A'){return 0;}
	if (c == 'C'){return 1;}
	if (c == 'G'){return 2;}
	if (c == 'T'){return 3;}
	else {return 4;}
}

int three_max(int a, int b, int c){
	if (a > b){
		if (a > c){return a;}
		else {return c;}
	}
	else {
		if (b > c){return b;}
		else {return c;}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, value1, value2, value3;
	cin >> TC;
	while (TC-- > 0){
		cin >> LengthA >> Adna;
		cin >> LengthB >> Bdna;
		memset(DP, 0, sizeof(DP));
		DP[0][0] = 0;
		for (int a = 1; a <= LengthA; a++){
			DP[a][0] = DP[a - 1][0] + score[retIDX(Adna[a - 1])][4];
		}
		for (int b = 1; b <= LengthB; b++){
			DP[0][b] = DP[0][b - 1] + score[4][retIDX(Bdna[b - 1])];
		}
		for (int a = 1; a <= LengthA; a++){
			for (int b = 1; b <= LengthB; b++){
				value1 = DP[a - 1][b - 1] + score[retIDX(Adna[a - 1])][retIDX(Bdna[b - 1])];
				value2 = DP[a - 1][b] + score[retIDX(Adna[a - 1])][4];
				value3 = DP[a][b - 1] + score[4][retIDX(Bdna[b - 1])];
				DP[a][b] = three_max(value1, value2, value3);
			}
		}
		cout << DP[LengthA][LengthB] << '\n';
	}
	
}