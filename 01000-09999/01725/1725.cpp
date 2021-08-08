// 1725 히스토그램
// https://www.acmicpc.net/problem/1725
// 6549번 문제의 해답 코드와 동일합니다. 고마워요 백준! 고마워요 종만북!
#include <iostream>
#include <stack>
using namespace std;

int N;
long long int max_area = 0;
stack<long long int> s;
long long int rectangle[100001];

void histogram(){
	long long int height, width, area;
	for (int i = 0; i < N; i++){
		while (!s.empty() && rectangle[s.top()] > rectangle[i]){
			height = rectangle[s.top()];
			s.pop();
			width = i;
			if (!s.empty()){
				width = i - s.top() - 1; // left = s.top() + 1, right = i - 1
			}
			area = width * height;
			if (area > max_area){max_area = area;}
		}
		s.push(i);
	}
	while (!s.empty()){
		height = rectangle[s.top()];
		s.pop();
		width = N;
		if (!s.empty()){
			width = N - s.top() - 1;
		}
		area = width * height;
		if (area > max_area){max_area = area;}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> rectangle[i];
	}
	histogram();
	cout << max_area;
}