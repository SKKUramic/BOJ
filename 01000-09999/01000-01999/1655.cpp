// 1655 가운데를 말해요
// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> small;
priority_queue<int, vector<int>, greater<int>> big;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, number, small_size = 0, big_size = 0; //size()함수는 일부러 안 부름ㅇㅇ
	cin >> N;
	while (N-- > 0){
		cin >> number;
		if (small_size == 0 && big_size == 0){
			small.push(number);
			small_size++;
			cout << number << '\n';
			continue;
		}
		if (small.top() > number){
			small.push(number);
			small_size++;
		}
		else {
			big.push(number);
			big_size++;
		}
		if (abs(small_size - big_size) >= 2){
			if (small_size > big_size){
				number = small.top();
				small.pop();
				big.push(number);
				small_size--; big_size++;
			}
			else {
				number = big.top();
				big.pop();
				small.push(number);
				small_size++; big_size--;
			}
		}
		if ((small_size + big_size) % 2 == 0){
			if (small.top() < big.top()){
				cout << small.top() << '\n';
			}
			else {
				cout << big.top() << '\n';
			}
		}
		else {
			if (small_size > big_size){
				cout << small.top() << '\n';
			}
			else {
				cout << big.top() << '\n';
			}
		}
	}
}