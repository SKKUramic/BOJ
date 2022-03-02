// 2083 럭비 클럽
// https://www.acmicpc.net/problem/2083
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int age, weight;
	string name;
	cin >> name >> age >> weight;
	while (name[0] != '#' || age != 0 || weight != 0){
		if (age > 17 || weight >= 80){
			cout << name << ' ' << "Senior\n";
		}
		else {
			cout << name << ' ' << "Junior\n";
		}
		cin >> name >> age >> weight;
	}
}