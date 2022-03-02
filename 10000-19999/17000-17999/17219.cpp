// 17219 비밀번호 찾기
#include <iostream>
#include <map>
using namespace std;

map<string, string> site;
string site_address, password;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i< N; i++){
		cin >> site_address >> password;
		site[site_address] = password;
	}
	for (int i = 0; i < M; i++){
		cin >> site_address;
		cout << site[site_address] << '\n';
	}
}