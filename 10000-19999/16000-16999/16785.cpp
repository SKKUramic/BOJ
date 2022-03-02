// 16785 ソーシャルゲーム (Social Game)
#include <iostream>
using namespace std;

int main(){
	long int A, B, C, answer = 0;
	cin >> A >> B >> C;
	while (C > 0){
		answer++;
		C -= A;
		if (answer % 7 == 0){
			C -= B;	
		}
	}
	cout << answer;
}