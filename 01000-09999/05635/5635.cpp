// 5635 생일
// https://www.acmicpc.net/problem/5635
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Human{
	string name;
	int year;
	int month;
	int day;
}Human;

vector<Human> Birthday;

bool cmp(Human a, Human b){
	if (a.year == b.year){
		if (a.month == b.month){
			return a.day < b.day;
		}
		return a.month < b.month;
	}
	return a.year < b.year;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Y, M, D;
	string nn;
	Human man;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> nn >> D >> M >> Y;
		man.name = nn; man.year = Y; man.month = M; man.day = D;
		Birthday.push_back(man);
	}
	sort(Birthday.begin(), Birthday.end(), cmp);
	cout << Birthday[Birthday.size() - 1].name << '\n' << Birthday[0].name;
}