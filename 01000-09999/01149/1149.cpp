// 1149 RGM거리
#include <iostream>
using namespace std;

int RGB[1001][3] = {0, }; // red = 0, green = 1, blue = 2;
int price[1001][3] = {0, }; // first: price, second: color
int mini;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int house;
	cin >> house;
	for (int i = 0; i < house; i++){
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
	price[0][0] = RGB[0][0];
	price[0][1] = RGB[0][1];
	price[0][2] = RGB[0][2];
	for (int a = 1; a < house; a++){
		price[a][0] = price[a - 1][1] < price[a - 1][2] ? price[a - 1][1] + RGB[a][0] : price[a - 1][2] + RGB[a][0];
		price[a][1] = price[a - 1][2] < price[a - 1][0] ? price[a - 1][2] + RGB[a][1] : price[a - 1][0] + RGB[a][1];
		price[a][2] = price[a - 1][0] < price[a - 1][1] ? price[a - 1][0] + RGB[a][2] : price[a - 1][1] + RGB[a][2];
	}
	mini = price[house - 1][0];
	if (mini > price[house - 1][1]) {mini = price[house - 1][1];}
	if (mini > price[house - 1][2]) {mini = price[house - 1][2];}
	cout << mini;
}