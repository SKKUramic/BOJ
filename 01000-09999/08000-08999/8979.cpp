// 8979 올림픽
// https://www.acmicpc.net/problem/8979
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Nation{
	int nation_number;
	int gold;
	int silver;
	int bronze;
}Nation; 

vector<Nation> Olympic;
int ranking[1001] = {0, };
int Rank = 1, same_rank = 1;

bool cmp(Nation a, Nation b){
	if (a.gold == b.gold){
		if (a.silver == b.silver){
			return a.bronze > b.bronze;
		}
		else {
			return a.silver > b.silver;
		}
	}
	else {
		return a.gold > b.gold;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int n, g, s, b;
	Nation prev, curr;
	cin >> N >> K;
	for (int k = 0; k < N; k++){
		cin >> n >> g >> s >> b;
		Olympic.push_back({n, g, s, b});
	}
	sort(Olympic.begin(), Olympic.end(), cmp);
	for (int i = 0; i < Olympic.size(); i++){
		curr = Olympic[i];
		if (i == 0){
			ranking[curr.nation_number] = Rank;
		}
		else {
			prev = Olympic[i - 1];
			if (prev.gold == curr.gold && prev.silver == curr.silver && prev.bronze == curr.bronze){
				ranking[curr.nation_number] = Rank - (i - same_rank + 1);
			}
			else {
				ranking[curr.nation_number] = Rank;
				same_rank = Rank;
			}
		}
		Rank++;
	}
	cout << ranking[K];
}