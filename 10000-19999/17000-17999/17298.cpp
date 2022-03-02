// 17298 오큰수
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> big;
stack<int> ans;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, num, s_top, big_top;
	cin >> test;
	int k = 0;
	
	for (int i = 0; i < test; i++){
		cin >> num;
		s.push(num);
	}
	while (!s.empty()){
		while (1){
			if (big.empty()){break;}
			if (s.top() < big.top()){
				break;
			}
			else {
				big.pop();
			}
		}
		if (big.empty()){
			ans.push(-1);
			
		}
		else {
			ans.push(big.top());
		}
		big.push(s.top());
		s.pop();
	}
	for (int i = 0; i < test; i++){
		cout << ans.top() << ' ';
		ans.pop();
	}
}