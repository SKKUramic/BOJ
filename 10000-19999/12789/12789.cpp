// 12789 도키도키 간식드리미
// https://www.acmicpc.net/problem/12789
#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;
int arr[1001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, goal = 1;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		s2.push(num);
	}
	while (!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
	while (!s1.empty()){
		if (!s2.empty() && s2.top() == goal){
			s2.pop();
			goal++;
		}
		else {
			if (s1.top() == goal){
				goal++;
			}
			else {
				s2.push(s1.top());
			}
			s1.pop();
		}
	}
	while (!s2.empty()){
		if (s2.top() != goal){
			break;
		}
		goal++; s2.pop();
	}
	if (goal > N){cout << "Nice";}
	else {cout << "Sad";}
}