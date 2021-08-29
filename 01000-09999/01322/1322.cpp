// 1322 X와 k
// https://www.acmicpc.net/problem/1322
#include <iostream>
#include <vector>
using namespace std;

long long arr[63] = {0, };
vector<long long> ans;

int main(){
	long long answer = 0;
	long long X, K;
	for (int i = 0; i < 63; i++){
		arr[i] = (1LL << i); // 1로 하면 (int)1로 인식되어서 잘못된 수가 들어감
	}
	cin >> X >> K;
	for (int i = 0; i < 63; i++){
		if ((X & arr[i]) == 0){ // 비트 연산자 &은 우선순위가 가장 낮은 연산자라서 괄호를 씌워져야 함
			ans.push_back(arr[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++){
		if ((K & (1LL << i)) != 0){
			answer += ans[i];
		}
	}
	cout << answer;
}