// 15474 鉛筆 (Pencils)
#include <iostream>
using namespace std;

int main(){
	int N, A, B, C, D, X_price = 0, Y_price = 0, N_temp;
	cin >> N >> A >> B >> C >> D;
	N_temp = N;
	while (N_temp > 0){
		X_price += B;
		N_temp -= A;
	}
	N_temp = N;
	while (N_temp > 0){
		Y_price += D;
		N_temp -= C;
	}
	if (X_price < Y_price)
		cout << X_price;
	else 
		cout << Y_price;
}