// 1764 듣보잡
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, string> good;

map<string, int> not_hear;
map<int, string> not_hear_and_see;

bool compare(good a, good b){
	return a.second < b.second;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string name;
	int N, M, size = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> name;
		not_hear[name] = 1;
	}
	for (int i = 0; i < M; i++){
		cin >> name;
		if (not_hear[name] == 1){
			not_hear_and_see[size] = name;
			size++;
		}
	}
	vector<good> si(not_hear_and_see.begin(), not_hear_and_see.end());
	sort(si.begin(), si.end(), compare);
	cout << size << '\n';
	for (int i = 0; i < size; i++){
		cout << si[i].second << '\n';
	}
}