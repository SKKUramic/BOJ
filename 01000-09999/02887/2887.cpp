// 2887 행성 터널
// https://www.acmicpc.net/problem/2887
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

struct Point{
	long long x;
	long long y;
	long long z;
	int idx;
	Point(long long p1, long long p2, long long p3, int i){
		x = p1;
		y = p2;
		z = p3;
		idx = i;
	}
};

int V, E, X, Y, Z, cnt = 0;
long long weight, weight_sum = 0;
int parent[100001];
vector<Edge> Tree;
vector<Point> Plist;

bool xcmp(Point A, Point B){return A.x < B.x;}
bool ycmp(Point A, Point B){return A.y < B.y;}
bool zcmp(Point A, Point B){return A.z < B.z;}
long long abslen(long long a, long long b){
	if (a < b){return b - a;}
	else {return a - b;}
}

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return parent[x] = FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	if (x < y){parent[x] = y;}
	else {parent[y] = x;}
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
	for (int v = 0; v <= V; v++){
		parent[v] = v;
	}
	for (int v = 1; v <= V; v++){
		cin >> X >> Y >> Z;
		Plist.push_back(Point(X, Y, Z, v));
	}
	sort(Plist.begin(), Plist.end(), xcmp);
	for (int p = 0; p < V; p++){
		Tree.push_back(Edge(Plist[(p + V - 1) % V].idx, Plist[p].idx, abslen(Plist[(p + V - 1) % V].x, Plist[p].x)));
		Tree.push_back(Edge(Plist[p].idx, Plist[(p + 1) % V].idx, abslen(Plist[p].x, Plist[(p + 1) % V].x)));
	}
	sort(Plist.begin(), Plist.end(), ycmp);
	for (int p = 0; p < V; p++){
		Tree.push_back(Edge(Plist[(p + V - 1) % V].idx, Plist[p].idx, abslen(Plist[(p + V - 1) % V].y, Plist[p].y)));
		Tree.push_back(Edge(Plist[p].idx, Plist[(p + 1) % V].idx, abslen(Plist[p].y, Plist[(p + 1) % V].y)));
	}
	sort(Plist.begin(), Plist.end(), zcmp);
	for (int p = 0; p < V; p++){
		Tree.push_back(Edge(Plist[(p + V - 1) % V].idx, Plist[p].idx, abslen(Plist[(p + V - 1) % V].z, Plist[p].z)));
		Tree.push_back(Edge(Plist[p].idx, Plist[(p + 1) % V].idx, abslen(Plist[p].z, Plist[(p + 1) % V].z)));
	}
	sort(Tree.begin(), Tree.end(), cmp);
	for (int k = 0; k < Tree.size(); k++){
		if (cnt == V - 1){break;}
		if (FIND(Tree[k].v1) != FIND(Tree[k].v2)){ // v1과 v2가 서로 연결되어 있지 않아 연결 시 사이클이 발생하지 않을 경우
			Union(Tree[k].v1, Tree[k].v2);
			weight_sum += Tree[k].weight;
			cnt++;
		}
	}
	cout << weight_sum;
}