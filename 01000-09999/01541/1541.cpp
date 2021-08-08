// 1541 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

int number[100] = {0, };
int number_answer[100] = {0, };
char oper[100];
bool flags = false;

int main(){
	int len, temp = 0, index = 0, answer = 0;
	string sentence;
	cin >> sentence;
	len = sentence.length();
	for (int i = 0; i < len; i++){
		if (sentence[i] >= '0' && sentence[i] <= '9'){
			temp *= 10;
			temp += sentence[i] - '0';
		}
		else {
			number[index] = temp;
			temp = 0;
			oper[index++] = sentence[i];
		}
	}
	number[index] = temp;
	oper[index++] = '?';
	temp = 0;/*
	for (int i = 0; i < index; i++){
		cout << number[i] << ' ';
		cout << oper[i] << '\n';
	}*/
	//cout << '\n';
	for (int k = 0; k < index; k++){
		if (flags == false){
			answer += number[k];
			if (oper[k] == '-'){
				flags = true;
			}
		}
		else {
			answer -= number[k];
		}
		//cout << answer << ' ';
		/*
		if (oper[k] == '-'){
			if (flags == true){
				temp += number[k];
				answer -= temp;
				temp = 0;
			}
			else { // flags == false
				answer += number[k];
				flags = true;
			}
		}
		else if (oper[k] == '+'){
			if (flags == true){
				temp += number[k];
			}
			else {
				answer += number[k];
			}
		}
		else {
			if (oper[k - 1] == '-'){ // -
				
			}
			else { // +
				
			}
		}
		*/
	}
	cout << answer;
}