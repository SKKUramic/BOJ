// 2162 선분 그룹
// https://www.acmicpc.net/problem/2162
#include <stdio.h>

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Line{
	Point P1;
	Point P2;
}Line;

int N;
int parent[3001] = {0, };
int group_count[3001] = {0, };
Line arr[3001];

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return parent[x] = FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	if (x == y){return;}
	else {
		if (y > x){parent[y] = x;}
		else {parent[x] = y;}
		//parent[y] = x;
		return;
	}
}

int CCW(Point P1, Point P2, Point P3){
	int ccw = P1.x * P2.y + P2.x * P3.y + P3.x * P1.y - (P2.x * P1.y + P3.x * P2.y + P1.x * P3.y);
	if (ccw < 0){return -1;} // 시계
	else if (ccw > 0){return 1;} // 반시계
	else {return 0;} // 직선
}

int is_normal(Point P1, Point P2){ // 역순이 아닌지 확인하는 함수
	if (P1.x < P2.x){return 1;}
	else if (P1.x == P2.x && P1.y < P2.y){return 1;}
	else {return 0;}
}

int same_point(Point P1, Point P2){ // 두 점이 같은 점일 경우
	if (P1.x == P2.x && P1.y == P2.y){return 1;}
	else {return 0;}
}

int is_intersect(Line L1, Line L2){ // 두 선분의 교차 여부
	if (same_point(L1.P1, L2.P1) + same_point(L1.P1, L2.P2) + same_point(L1.P2, L2.P1) + same_point(L1.P2, L2.P2) != 0){return 1;}
	// 두 선분이 점에서 만날 경우에도 교차하는 것
	int CCW12_3, CCW12_4, CCW34_1, CCW34_2;
	CCW12_3 = CCW(L1.P1, L1.P2, L2.P1);
	CCW12_4 = CCW(L1.P1, L1.P2, L2.P2);
	CCW34_1 = CCW(L2.P1, L2.P2, L1.P1);
	CCW34_2 = CCW(L2.P1, L2.P2, L1.P2);
	if (CCW12_3 * CCW12_4 == 0 && CCW34_1 * CCW34_2 == 0){ // 네 점이 한 직선 위에 있을 때
		if (is_normal(L2.P1, L1.P2) == 1 && is_normal(L1.P1, L2.P2) == 1){return 1;}
		else {return 0;}
	}
	else if (CCW12_3 * CCW12_4 <= 0 && CCW34_1 * CCW34_2 <= 0){return 1;}
	else {return 0;}
}

int main(){
	Point temp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d %d %d %d", &arr[i].P1.x, &arr[i].P1.y, &arr[i].P2.x, &arr[i].P2.y);
		if (is_normal(arr[i].P1, arr[i].P2) == 0){ // 선분의 두 점이 역순으로 되어 있을 경우
			temp.x = arr[i].P1.x; temp.y = arr[i].P1.y;
			arr[i].P1.x = arr[i].P2.x; arr[i].P1.y = arr[i].P2.y;
			arr[i].P2.x = temp.x; arr[i].P2.y = temp.y;
		}
	}
	for (int i = 0; i <= N; i++){parent[i] = i;}
	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++){
			if (is_intersect(arr[i], arr[j]) == 1){ // 두 선분이 교차할 경우
				Union(i, j);
			}
		}
	}
	for (int i = 1; i <= N; i++){parent[i] = FIND(i);} // 조상 갱신
	for (int i = 1; i <= N; i++){
		group_count[parent[i]]++;
	}
	int answer_group = 0, answer_count = 0, all_group = 0;
	for (int i = 1; i <= N; i++){
		if (group_count[i] != 0){all_group++;}
		if (answer_count < group_count[i]){
			answer_group = i;
			answer_count = group_count[i];
		}
	}
	printf("%d\n%d\n", all_group, answer_count);
}