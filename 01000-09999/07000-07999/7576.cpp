// 7576 토마토
// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>
using namespace std;

int M, N, ripen_count = 0, empty_count = 0;
int tomato[1000][1000] = {0, };
queue<int> tomato_x;
queue<int> tomato_y;

void print_tomato(int i){
	printf("%d days after\n", i);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("%d ", tomato[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int BFS(){
	if (ripen_count + empty_count == M * N){return 0;}
	int current_ripen_count, q_size, find_x, find_y;
	int days = 0;
	int end = M * N - empty_count;
	while(1){
		current_ripen_count = 0;
		q_size = tomato_x.size();
		while (q_size-- > 0){
			find_x = tomato_x.front();
			find_y = tomato_y.front();
			tomato_x.pop();
			tomato_y.pop();
			if (find_x > 0 && tomato[find_x - 1][find_y] == 0){
				tomato_x.push(find_x - 1);
				tomato_y.push(find_y);
				tomato[find_x - 1][find_y] = 1;
				current_ripen_count++;
			}
			if (find_y > 0 && tomato[find_x][find_y - 1] == 0){
				tomato_x.push(find_x);
				tomato_y.push(find_y - 1);
				tomato[find_x][find_y - 1] = 1;
				current_ripen_count++;
			}
			if (find_x < N - 1 && tomato[find_x + 1][find_y] == 0){
				tomato_x.push(find_x + 1);
				tomato_y.push(find_y);
				tomato[find_x + 1][find_y] = 1;
				current_ripen_count++;
			}
			if (find_y < M - 1 && tomato[find_x][find_y + 1] == 0){
				tomato_x.push(find_x);
				tomato_y.push(find_y + 1);
				tomato[find_x][find_y + 1] = 1;
				current_ripen_count++;
			}
		}
		if (current_ripen_count == 0){
			if (ripen_count != end){
				return -1;
			}
			else {
				return days;
			}
		}
		ripen_count += current_ripen_count;
		days++;
		//print_tomato(days);
	}
}

int main(){
	int answer;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1){
				tomato_x.push(i);
				tomato_y.push(j);
				ripen_count++;
			}
			else if (tomato[i][j] == -1){
				empty_count++;
			}
		}
	}
	answer = BFS();
	printf("%d", answer);
}