// 1922 네트워크 연결
// https://www.acmicpc.net/problem/1922
// 1197 최소 스패닝 트리와 동일한 코드입니다
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{ 
	int v1; 
	int v2; 
	long long weight; 
	Edge(int a, int b, long long c){ 
		v1 = a; 
		v2 = b; 
		weight = c; 
	}
};

int V, E, v1, v2, edge_count = 0;
long long weight, weight_sum = 0;
char c;
int parent[1001];
char School_Type[1001];
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
	cin >> V;
	cin >> E;
	for (int v = 1; v <= V; v++){
		parent[v] = v;
	}
	for (int v = 1; v <= V; v++){ // 이 학교는 남학교인가 여학교인가
		cin >> School_Type[v];
	}
	for (int e = 0; e < E; e++){
		cin >> v1 >> v2 >> weight;
		Tree.push_back(Edge(v1, v2, weight));
	}
	sort(Tree.begin(), Tree.end(), cmp);
	for (int k = 0; k < Tree.size(); k++){
		if (FIND(Tree[k].v1) != FIND(Tree[k].v2) && School_Type[Tree[k].v1] != School_Type[Tree[k].v2]){ // 부모가 다른 것은 물론, 학교의 타입도 서로 달라야 한다
			Union(Tree[k].v1, Tree[k].v2);
			weight_sum += Tree[k].weight;
			edge_count++;
		}
	}
	if (edge_count == V - 1){ // 모든 학교가 연결되어 있을 경우
		cout << weight_sum;
	}
	else {
		cout << "-1";
	}
	
}