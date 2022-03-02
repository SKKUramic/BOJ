// 1013 Contact
// https://www.acmicpc.net/problem/1013
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	int T;
	string message;
	deque<char> contact;
	bool is_valid_massage;
	cin >> T;
	while (T-- > 0){
		cin >> message;
		is_valid_massage = true;
		for (int i = 0; i < message.length(); i++){
			contact.push_back(message[i]);
		}
		while (!contact.empty()){
			if (contact.front() == '1'){
				// 100 추출
				contact.pop_front();
				if (contact.empty()){
					is_valid_massage = false;
					break;
				}
				else if (contact.front() == '0'){
					contact.pop_front();
				}
				else if (contact.front() == '1'){
					is_valid_massage = false;
					break;
				}
				if (contact.empty()){
					is_valid_massage = false;
					break;
				}
				else if (contact.front() == '0'){
					contact.pop_front();
				}
				else if (contact.front() == '1'){
					is_valid_massage = false;
					break;
				}
				
				while (!contact.empty() && contact.front() == '0'){ // + 추출
					contact.pop_front();
				}
				// 1 추출
				if (contact.empty()){
					is_valid_massage = false;
					break;
				}
				else if (contact.front() == '0'){ // 사실 필요 없음
					is_valid_massage = false;
					break;
				}
				else if (contact.front() == '1'){
					contact.pop_front();
				}
				// + 추출 전 0 검사
				if (contact.empty()){
					break;
				}
				else if (contact.front() == '0'){ // 01을 pop함
					contact.pop_front();
					if (contact.empty()){
						is_valid_massage = false;
						break;
					}
					else if (contact.front() == '0'){
						is_valid_massage = false;
						break;
					}
					else if (contact.front() == '1'){
						contact.pop_front();
						continue; // 다시 분기로
					}
				}
				else if (contact.front() == '1'){
					while (!contact.empty() && contact.front() == '1'){
						contact.pop_front();
						if (contact.empty()){
							break;
						}
						else if (contact.front() == '0'){
							contact.pop_front();
							if (contact.empty()){
								is_valid_massage = false;
								break;
							}
							else if (contact.front() == '0'){ // 100
								contact.push_front('0');
								contact.push_front('1');
								break;
							}
							else if (contact.front() == '1'){ // 101이므로 01만 다시 넣음
								contact.push_front('0');
								break;
							}
						}
					}	
				}
			}
			else if (contact.front() == '0'){
				contact.pop_front();
				if (contact.front() == '1'){
					contact.pop_front();
				}
				else {
					is_valid_massage = false;
					break;
				}
			}
		}
		if (is_valid_massage){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		while (!contact.empty()){contact.pop_front();}
	}
}