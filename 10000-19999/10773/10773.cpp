// 10773 제로
#include <iostream>
#include <stack>
using namespace std;

unsigned long long int K, num, sum = 0;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<unsigned long long int> ss;
	cin >> K;
	for (int i = 0; i < K; i++){
		cin >> num;
		if (num == 0){
			sum -= ss.top();
			ss.pop();
		}
		else {
			sum += num;
			ss.push(num);
		}
	}
	cout << sum;
}