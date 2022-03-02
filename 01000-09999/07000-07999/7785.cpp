// 7785 회사에 있는 사람
// https://www.acmicpc.net/problem/7785
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<string> company;
	string s, where;
	int N;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> s >> where;
		if (where.compare("enter") == 0){company.insert(s);}
		else {
			company.erase(s);	
		}
	}
	set<string>::reverse_iterator iter;
	for (iter = company.rbegin(); iter != company.rend(); iter++){
		cout << *iter << '\n';
	}
}