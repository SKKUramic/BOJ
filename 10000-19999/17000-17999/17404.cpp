// 17404 RGB거리 2
// https://www.acmicpc.net/problem/17404
#include <iostream>
using namespace std;

int RGB[1001][3] = {0, }; // red = 0, green = 1, blue = 2;
int price[3][1001][3] = {0, }; // first: 이 집을 첫번째 집으로 고정하고 시작, second: price, third: color
int mini;

int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int house;
	cin >> house;
	for (int i = 0; i < house; i++){
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
	price[0][0][0] = RGB[0][0];
	price[0][1][0] = 123456789; // 0번 색 집으로 시작하며 끝남
	price[0][1][1] = RGB[0][0] + RGB[1][1];
	price[0][1][2] = RGB[0][0] + RGB[1][2];
	for (int a = 2; a < house; a++){
		price[0][a][0] = min(price[0][a - 1][1], price[0][a - 1][2]) + RGB[a][0];
		price[0][a][1] = min(price[0][a - 1][0], price[0][a - 1][2]) + RGB[a][1];
		price[0][a][2] = min(price[0][a - 1][1], price[0][a - 1][0]) + RGB[a][2];
	}
	
	price[1][0][1] = RGB[0][1];
	price[1][1][0] = RGB[0][1] + RGB[1][0];
	price[1][1][1] = 123456789; // 1번 색 집으로 시작하며 끝남
	price[1][1][2] = RGB[0][1] + RGB[1][2];
	for (int a = 2; a < house; a++){
		price[1][a][0] = min(price[1][a - 1][1], price[1][a - 1][2]) + RGB[a][0];
		price[1][a][1] = min(price[1][a - 1][0], price[1][a - 1][2]) + RGB[a][1];
		price[1][a][2] = min(price[1][a - 1][1], price[1][a - 1][0]) + RGB[a][2];
	}
	
	price[2][0][2] = RGB[0][2];
	price[2][1][0] = RGB[0][2] + RGB[1][0];
	price[2][1][1] = RGB[0][2] + RGB[1][1];
	price[2][1][2] = 123456789; // 2번 색 집으로 시작하며 끝남
	for (int a = 2; a < house; a++){
		price[2][a][0] = min(price[2][a - 1][1], price[2][a - 1][2]) + RGB[a][0];
		price[2][a][1] = min(price[2][a - 1][0], price[2][a - 1][2]) + RGB[a][1];
		price[2][a][2] = min(price[2][a - 1][1], price[2][a - 1][0]) + RGB[a][2];
	}
	mini = min(price[0][house - 1][1], price[0][house - 1][2]);
	mini = min(mini, price[1][house - 1][0]);
	mini = min(mini, price[1][house - 1][2]);
	mini = min(mini, price[2][house - 1][0]);
	mini = min(mini, price[2][house - 1][1]);
	cout << mini;
}