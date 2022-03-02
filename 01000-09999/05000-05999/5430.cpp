// 5430 AC
// https://www.acmicpc.net/problem/5430
#include <iostream>
#include <deque>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string command, input_arr;
	int TEST, n, idx, number_change;
	cin >> TEST;
	for (int i = 0; i < TEST; i++){
		deque<int> dq;
		bool flags = true;
		bool isfront = true;
		bool error_flag = false;
		cin >> command;
		cin >> n;
		cin >> input_arr;
		idx = 0;
		while (idx < input_arr.size()){
			if (input_arr[idx] != '[' && input_arr[idx] != ']' && input_arr[idx] != ','){
				number_change = input_arr[idx] - '0';
				idx++;
				while(input_arr[idx] != '[' && input_arr[idx] != ']' && input_arr[idx] != ','){
					number_change *= 10;
					number_change += input_arr[idx] - '0';
					idx++;
				}
				dq.push_back(number_change);
			}
			else {
				idx++;
			}
		}
		for (int i = 0; i < command.size(); i++){
			if (command[i] == 'R'){
				if (isfront){ // 배열이 정상일 때, 순서를 거꾸로 뒤집는다.
					isfront = false;
				}
				else { // 배열이 뒤집혀있을 때, 다시 정상으로 되돌린다.
					isfront = true;
				}
			}
			else if (command[i] == 'D'){
				if (!dq.empty()){ // 덱이 비어있지 않을 경우
					if (isfront){
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
				else { // 덱이 비어있음에도 빼려고 하면 에러 출력
					error_flag = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (!error_flag){
			cout << '[';
			if (!dq.empty()){ // 덱이 비어있지 않을 때만 덱 안의 원소들을 출력함
				if (isfront){ // 정상적 순서라면
					for (int i = 0; i < dq.size() - 1; i++){
						cout << dq[i] << ',';
					}
					cout << dq[dq.size() - 1];
				}
				else { // 거꾸로 순서라면
					for (int i = dq.size() - 1; i > 0; i--){
						cout << dq[i] << ',';
					}
					cout << dq[0];
				}	
			}
			cout << "]\n";
		}
	}
}