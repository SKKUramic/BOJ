// 4949 균형잡힌 세상
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

int len;
string sentence;
stack<char> bracket;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1){
		getline(cin, sentence);
		//scanf("%[^\n]s", sentence);
		len = sentence.length();
		//cout << sentence << '\n';
		if (len == 1 && sentence[0] == '.'){
			break;
		}
		//cout << sentence << '\n';
		for (int i = 0; i < len; i++){
			//cout << sentence << '\n';
			//cout << i << ' ' << bracket.top() << "OMG\n";
			//cout << sentence << '\n';
			if (sentence[i] == '(' || sentence[i] == '['){
				bracket.push(sentence[i]);
			}
			else if (sentence[i] == ')'){
				//cout << sentence << '\n';
				//bracket.push(sentence[i]);
				if (!bracket.empty() && bracket.top() == '('){
					//bracket.pop();
					bracket.pop();
				}
				else {
					bracket.push(sentence[i]);
					//cout << "no" << '\n';
					break;
				}
			}
			else if (sentence[i] == ']'){
				//bracket.push(sentence[i]);
				if (!bracket.empty() && bracket.top() == '['){
					//bracket.pop();
					bracket.pop();
				}
				else {
					bracket.push(sentence[i]);
					//cout << "no" << '\n';
					break;
				}
			}
			//cout << i << ' ' << bracket.top() << "OMG\n";
		}
		
		if (bracket.empty()){
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
		while (!bracket.empty()){
			bracket.pop();
		}
		//scanf("%[^\n]s", sentence);
		//getline(cin, sentence);
		//len = sentence.length();
		//cout << sentence << '\n';
	}
}