// 4386 별자리 만들기
// https://www.acmicpc.net/problem/4386
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Edge{ 
	int v1; 
	int v2; 
	double weight; 
	Edge(int a, int b, double c){ 
		v1 = a; 
		v2 = b; 
		weight = c; 
	}
};

int star, v1, v2;
double weight, len1, len2, weight_sum = 0.00000000000;
double star_pos[101][2];
int parent[101];
vector<Edge> Tree;

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	parent[x] = y;
	return;
}

bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> star;
	for (int v = 1; v <= star; v++){
		parent[v] = v;
	}
	for (int e = 1; e <= star; e++){
		cin >> star_pos[e][0] >> star_pos[e][1];
	}
	for (int a = 1; a <= star; a++){
		for (int b = 1; b <= star; b++){
			len1 = (star_pos[a][0] - star_pos[b][0]) * (star_pos[a][0] - star_pos[b][0]);
			len2 = (star_pos[a][1] - star_pos[b][1]) * (star_pos[a][1] - star_pos[b][1]);
			Tree.push_back(Edge(a, b, sqrt(len1 + len2)));
		}
		
	}
	sort(Tree.begin(), Tree.end(), cmp);
	for (int k = 0; k < Tree.size(); k++){
		if (FIND(Tree[k].v1) != FIND(Tree[k].v2)){ // v1과 v2가 서로 연결되어 있지 않으며, 연결 시 사이클이 발생하지 않을 경우
			Union(Tree[k].v1, Tree[k].v2);
			weight_sum += Tree[k].weight;
		}
	}
	cout << weight_sum;
}