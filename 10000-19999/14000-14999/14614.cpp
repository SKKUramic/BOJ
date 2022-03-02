// 14614 Calculate!
// https://www.acmicpc.net/problem/14614
#include <iostream>
using namespace std;

int main(){
	int a, b;
	string c;
	cin >> a >> b >> c;
	if (((c[c.size() - 1]) - '0') % 2 == 1){
		a ^= b;
	}
	cout << a;
}