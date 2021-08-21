// 1197 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
// https://runninnonempty.tistory.com/16에서 최소 스패닝 트리에 대해 배웠습니다.
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

int V, E, v1, v2;
long long weight, weight_sum = 0;
int parent[10001];
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
	cin >> V >> E;
	for (int v = 1; v <= V; v++){
		parent[v] = v;
	}
	for (int e = 0; e < E; e++){
		cin >> v1 >> v2 >> weight;
		Tree.push_back(Edge(v1, v2, weight));
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