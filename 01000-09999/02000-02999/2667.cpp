// 2667 단지번호 붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int one_count = 0;
int answer = 0;
char graph[50][50];
vector<int> v;

void print(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c", graph[i][j]);
		}
		printf("\n");
	}
}

void DFS(int x, int y){
	one_count++;
	graph[x][y] = '0';
	if (x > 0 && graph[x - 1][y] == '1'){
		DFS(x - 1, y);
	}
	if (x < N - 1 && graph[x + 1][y] == '1'){
		DFS(x + 1, y);
	}
	if (y > 0 && graph[x][y - 1] == '1'){
		DFS(x, y - 1);
	}
	if (y < N - 1 && graph[x][y + 1] == '1'){
		DFS(x, y + 1);
	}
	return;
}

int main(){
	int apart_count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", graph[i]);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (graph[i][j] != '0'){
				one_count = 0;
				DFS(i, j);
				//printf("i:%d, j:%d, one_count:%d\n", i, j, one_count);
				if (one_count != 0){
					v.push_back(one_count);
					apart_count++;
				}
				//print();
				//printf("\n");
			}
		}
	}
	sort(v.begin(), v.end());
	cout << apart_count << '\n';
	for (auto iter = v.begin(); iter != v.end(); iter++){
		cout << *iter << '\n';
	}
}