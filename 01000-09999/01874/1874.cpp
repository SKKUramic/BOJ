// 1874 스택 수열
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int hello[100001] = {0, };
char plus_or_minus[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, index = 0, char_index = 0, pushing = 1;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> hello[i];
	while (num >= pushing){
		s.push(pushing);
		pushing++;
		plus_or_minus[char_index++] = '+';
		while (!s.empty() && s.top() == hello[index]){
			s.pop();
			index++;
			plus_or_minus[char_index++] = '-';
		}
	}
	if (index != num){
		cout << "NO";
	}
	else {
		for (int i = 0; i < char_index; i++)
			cout << plus_or_minus[i] << '\n';
	}
}