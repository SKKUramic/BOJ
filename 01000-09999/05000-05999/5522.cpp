// 5522 ์นด๋ ๊ฒ์
#include <iostream>
using namespace std;

int main(){
	int sum = 0, num;
	for (int i = 0; i < 5; i++){
		cin >> num;
		sum += num;
	}
	cout << sum;
}