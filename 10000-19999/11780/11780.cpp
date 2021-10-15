// 11780 플로이드 2
// https://www.acmicpc.net/problem/11780
#include <iostream>
#include <vector>
using namespace std;

#define INF 99999999

int Graph[101][101] = {0, };
vector<int> Path[101][101];

void FLOYD_WARSHALL(int CITY){
	for (int waypoint = 1; waypoint <= CITY; waypoint++){
		for (int start = 1; start <= CITY; start++){
			for (int end = 1; end <= CITY; end++){
				if (start != end && Graph[start][end] > Graph[start][waypoint] + Graph[waypoint][end]){
					Graph[start][end] = Graph[start][waypoint] + Graph[waypoint][end];
					Path[start][end].clear();
					for (int i = 0; i < Path[start][waypoint].size(); i++){
						Path[start][end].push_back(Path[start][waypoint][i]);
					}
					Path[start][end].pop_back();
					for (int i = 0; i < Path[waypoint][end].size(); i++){
						Path[start][end].push_back(Path[waypoint][end][i]);
					}
				}
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int city, bus, size;
	int start, end, weight;
	cin >> city;
	cin >> bus;
	for (int i = 1; i <= city; i++){
		for (int j = 1; j <= city; j++){
			if (i != j){Graph[i][j] = INF;}
			Path[i][j].push_back(i);
			Path[i][j].push_back(j);
		}
	}
	for (int i = 0; i < bus; i++){
		cin >> start >> end >> weight;
		if (Graph[start][end] > weight){
			Graph[start][end] = weight;
		}
	}
	FLOYD_WARSHALL(city);
	for (int i = 1; i <= city; i++){
		for (int j = 1; j <= city; j++){
			if (Graph[i][j] == INF){
				cout << "0 ";
			}
			else {
				cout << Graph[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = 1; i <= city; i++){
		for (int j = 1; j <= city; j++){
			if (Graph[i][j] == INF || i == j){
				cout << "0\n";
			}
			else {
				cout << Path[i][j].size() << ' ';
				for (int s = 0; s < Path[i][j].size(); s++){
					cout << Path[i][j][s] << ' ';
				}
				cout << '\n';
			}
		}
	}
}