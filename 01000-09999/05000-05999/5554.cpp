// 5554 심부름 가는 길
#include <iostream>
using namespace std;

int main(){
	int sum = 0, num;
	for (int i = 0; i < 4; i++){
		cin >> num;
		sum += num;
	}
	cout << sum / 60 << endl;
	cout << sum % 60;
}