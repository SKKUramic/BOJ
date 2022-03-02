// 9946 단어 퍼즐
// https://www.acmicpc.net/problem/9946
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int case_num = 1;
	string a, b;
	cin >> a >> b;
	while (a.compare("END") != 0 || b.compare("END") != 0){
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a.compare(b) == 0){
			cout << "Case " << case_num << ": same\n";
		}
		else {
			cout << "Case " << case_num << ": different\n";
		}
		case_num++;
		cin >> a >> b;
	}
}