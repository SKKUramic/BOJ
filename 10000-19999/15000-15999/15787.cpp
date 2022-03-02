// 15787 기차가 어둠을 헤치고 은하수를
// https://www.acmicpc.net/problem/15787
#include <iostream>
using namespace std;

bool visited[2100000] = {false, };
int REMAINDER = (1 << 21) - 1;
int train[100001] = {0, };

int main(){
	int train_count, command_count, answer = 0;
	int command, train_number, x;
	cin >> train_count >> command_count;
	for (int c = 0; c < command_count; c++){
		cin >> command;
		if (command == 1){
			cin >> train_number >> x;
			train[train_number] |= 1 << x;
		}
		else if (command == 2){
			cin >> train_number >> x;
			train[train_number] &= ~(1 << x);
		}
		else if (command == 3){
			cin >> train_number;
			train[train_number] = (train[train_number] << 1) & REMAINDER;
		}
		else if (command == 4){
			cin >> train_number;
			train[train_number] = (train[train_number] >> 1) & -2; // ~1 == -2
		}
	}
	for (int i = 1; i <= train_count; i++){
		if (visited[train[i]] == false){
			visited[train[i]] = true;
			answer++;
		}
	}
	cout << answer;
}