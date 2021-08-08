// 1620 나는야 포켓몬 마스터
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

map<string, int> pokemon_number_finder;
map<int, string> pokemon_name_finder;
// 개사기 map

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, number, k, len;
	string pokemon_name, pokemon_number;
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		cin >> pokemon_name;
		pokemon_name_finder[i] = pokemon_name;
		pokemon_number_finder[pokemon_name] = i;
	}
	for (int i = 0; i < M; i++){
		string finding;
		number = 0;
		k = 0;
		cin >> finding;
		len = finding.length();
		while (isdigit(finding[k]) != 0 && k < len){
			number = number * 10 + (finding[k] - '0');
			k++;
		}
		if (number == 0){ // 이름을 주었을 때
			cout << pokemon_number_finder[finding] << '\n';
		}
		else { // 숫자를 주었을 때
			cout << pokemon_name_finder[number] << '\n';
		}
	}
}