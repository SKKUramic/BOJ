// 10984 내 학점을 구해줘
// https://www.acmicpc.net/problem/10984
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, double> arr[11];

int main(){
	int TC, N, credit, c;
	double score, s;
	cin >> TC;
	while (TC-- > 0){
		cin >> N;
		credit = 0; score = 0.0;
		for (int n = 0; n < N; n++){
			cin >> c >> s;
			credit += c;
			score += s * c;
		}
		printf("%d %.1lf\n", credit, score / credit);
	}
}