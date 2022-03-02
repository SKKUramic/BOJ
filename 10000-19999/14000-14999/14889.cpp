// 14889 스타트와 링크
#include <iostream>
using namespace std;

int N, answer = 100000, diff;
int status[21][21] = {0, };
bool visited[21];

void finding(int idx, int team_person){
	if (team_person == N / 2){
		int start = 0, link = 0;
		visited[idx] = true;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (visited[i] == true && visited[j] == true)
					start += status[i][j];
				else if (visited[i] == false && visited[j] == false)
					link += status[i][j];
			}
		}
		diff = start > link ? start - link : link - start;
		if (answer > diff)
			answer = diff;
		visited[idx] = false;
	}
	for (int i = idx + 1; i < N; i++){
		if (!visited[i]){
			visited[i] = true;
			finding(i, team_person + 1);
			visited[i] = false;
		}
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> status[i][j];
		}
	}
	visited[0] = true;
	finding(0, 1);
	visited[0] = false;
	cout << answer;
}