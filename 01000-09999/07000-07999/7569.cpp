// 7569 토마토
// https://www.acmicpc.net/problem/7569
// 동명의 문제인 7576번 문제와 매우 비슷합니다.
#include <iostream>
#include <queue>
using namespace std;

int M, N, H, ripen_count = 0, empty_count = 0;
int tomato[100][100][100] = {0, };
queue<int> tomato_x;
queue<int> tomato_y;
queue<int> tomato_z;

void print_tomato(int i){
	printf("%d days after\n", i);
	for (int z = 0; z < H; z++){
		for (int x = 0; x < N; x++){
			for (int y = 0; y < M; y++){
				printf("%d", tomato[z][x][y]);
			}
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int BFS(){
	if (ripen_count + empty_count == M * N * H){return 0;}
	int current_ripen_count, q_size, find_x, find_y, find_z;
	int days = 0;
	int end = M * N * H - empty_count;
	while(1){
		current_ripen_count = 0;
		q_size = tomato_x.size();
		while (q_size-- > 0){
			find_x = tomato_x.front();
			find_y = tomato_y.front();
			find_z = tomato_z.front();
			tomato_x.pop();
			tomato_y.pop();
			tomato_z.pop();
			if (find_x > 0 && tomato[find_z][find_x - 1][find_y] == 0){ // 앞
				tomato_x.push(find_x - 1);
				tomato_y.push(find_y);
				tomato_z.push(find_z);
				tomato[find_z][find_x - 1][find_y] = 1;
				current_ripen_count++;
			}
			if (find_y > 0 && tomato[find_z][find_x][find_y - 1] == 0){ // 왼쪽
				tomato_x.push(find_x);
				tomato_y.push(find_y - 1);
				tomato_z.push(find_z);
				tomato[find_z][find_x][find_y - 1] = 1;
				current_ripen_count++;
			}
			if (find_x < N - 1 && tomato[find_z][find_x + 1][find_y] == 0){ // 뒤
				tomato_x.push(find_x + 1);
				tomato_y.push(find_y);
				tomato_z.push(find_z);
				tomato[find_z][find_x + 1][find_y] = 1;
				current_ripen_count++;
			}
			if (find_y < M - 1 && tomato[find_z][find_x][find_y + 1] == 0){ // 오른쪽
				tomato_x.push(find_x);
				tomato_y.push(find_y + 1);
				tomato_z.push(find_z);
				tomato[find_z][find_x][find_y + 1] = 1;
				current_ripen_count++;
			}
			if (find_z > 0 && tomato[find_z - 1][find_x][find_y] == 0){ // 아래
				tomato_x.push(find_x);
				tomato_y.push(find_y);
				tomato_z.push(find_z - 1);
				tomato[find_z - 1][find_x][find_y] = 1;
				current_ripen_count++;
			}
			if (find_z < H - 1 && tomato[find_z + 1][find_x][find_y] == 0){ // 위
				tomato_x.push(find_x);
				tomato_y.push(find_y);
				tomato_z.push(find_z + 1);
				tomato[find_z + 1][find_x][find_y] = 1;
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
	scanf("%d %d %d", &M, &N, &H);
	for (int z = 0; z < H; z++){
		for (int x = 0; x < N; x++){
			for (int y = 0; y < M; y++){
				scanf("%d", &tomato[z][x][y]);
				if (tomato[z][x][y] == 1){
					tomato_x.push(x);
					tomato_y.push(y);
					tomato_z.push(z);
					ripen_count++;
				}
				else if (tomato[z][x][y] == -1){
					empty_count++;
				}	
			}
		}
	}
	answer = BFS();
	printf("%d", answer);
}