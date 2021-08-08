// 18414 X に最も近い値 (The Nearest Value)
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int X, L, R, diff = 1000000, answer;
	cin >> X >> L >> R;
	for (int i = L; i <= R; i++){
		if (diff > abs(X - i)){
			diff = abs(X - i);
			answer = i;
		}
	}
	cout << answer;
}