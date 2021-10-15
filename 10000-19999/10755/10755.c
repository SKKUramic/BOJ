// 10775 공항
// https://www.acmicpc.net/problem/10775
#include <stdio.h>

int Gate, Plane;
int PlaneList[100001];
int parent[100001];

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return parent[x] = FIND(parent[x]);
	//return FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	parent[x] = y;
	return;
}

int main(){
	int answer = 0, docking_gate;
	scanf("%d", &Gate);
	scanf("%d", &Plane);
	for (int i = 0; i <= Gate; i++){parent[i] = i;}
	for (int p = 0; p < Plane; p++){
		scanf("%d", &PlaneList[p]);
	}
	for (int p = 0; p < Plane; p++){
		docking_gate = FIND(PlaneList[p]); // p번째 비행기가 도킹할 게이트
		if (docking_gate == 0){break;}
		Union(docking_gate, docking_gate - 1);
		answer++;
		//for (int i = 0; i <= Gate; i++){printf("%d ", parent[i]);} printf("\n");
	}
	printf("%d", answer);
}