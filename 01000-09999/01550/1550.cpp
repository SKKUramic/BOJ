// 1550 16진수
#include <iostream>
#include <string>
using namespace std;

int main(){
	int num = 0;
	string number;
	cin >> number;
	for (int i = 0; i < number.length(); i++) {
		num = num * 16;
		if (number[i] >= 'A' && number[i] <= 'F')
			num += number[i] - 'A' + 10;
		else 
			num += number[i] - '0';
	}
	cout << num;
}