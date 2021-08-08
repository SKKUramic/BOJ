// 1297 TV 크기
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double diagonal, width, length;
	cin >> diagonal >> width >> length;
	double divisor = diagonal / sqrt(width * width + length * length);
	printf("%d %d", (int)(width * divisor), (int)(length * divisor));
}