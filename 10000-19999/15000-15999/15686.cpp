// 15686 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

int N, M;
int min_distance = 999999999;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void chicken_distance(vector<pair<int, int>> p){
	int distance = 0;
	int min, temp;
	for (int h = 0; h < house.size(); h++){
		min = 999999999;
		for (int idx = 0; idx < p.size(); idx++){
			temp = abs(house[h].first - p[idx].first) + abs(house[h].second - p[idx].second);
			if (min > temp) {min = temp;}
		}
		distance += min;
	}
	if (min_distance > distance){min_distance = distance;}
	return;
}

void choose_chicken(int choose, int k, vector<pair<int, int>> p){
	if (choose == 0){
		chicken_distance(p);
		return;
	}
	for (int i = k + 1; i < chicken.size(); i++){
		p.push_back(chicken[i]);
		choose_chicken(choose - 1, i, p);
		p.pop_back();
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int num;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < N; m++){
			cin >> num;
			if (num == 1){
				house.push_back({n, m});
			}
			else if (num == 2){
				chicken.push_back({n, m});
			}
		}
	}
	for (int i = 0; i < chicken.size(); i++){
		vector<pair<int, int>> p;
		p.push_back(chicken[i]);
		choose_chicken(M - 1, i, p);
	}
	cout << min_distance;
}