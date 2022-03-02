// 16953 A → B
// https://www.acmicpc.net/problem/16953
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long A, B;
	int answer = -1;
	pair<long long, int> p;
	cin >> A >> B;
	queue<pair<long long, int>> q;
	q.push({A, 1});
	while (!q.empty()){
		p = q.front();
		q.pop();
		if (p.first == B){
			answer = p.second;
			break;
		}
		if (p.first * 2 <= B){
			q.push({p.first * 2, p.second + 1});
		}
		if (p.first * 10 + 1 <= B){
			q.push({p.first * 10 + 1, p.second + 1});
		}
	}
	cout << answer;
}

/* 아래의 방법으로도 풀린다. 그래프 이론따위 씹어먹는 풀이
#include <stdio.h>

int main(){
	int A, B, answer = 1;
	scanf("%d %d", &A, &B);
	while (A < B){
		if (B % 2 == 0){B /= 2;}
		else if (B % 10 == 1){B /= 10;}
		else {answer = -1; break;}
		answer++;
	}
	if (A != B){answer = -1;}
	printf("%d", answer);
}
*/