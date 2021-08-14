// 3015 오아시스 재결합
// https://www.acmicpc.net/problem/3015
#include <iostream>
#include <utility>
#include <stack>
using namespace std;

stack<pair<int, int>> oasis; // <이 사람의 키, 이 사람이랑 같은 키의 사람(연속으로 선 경우만)>

int main(){
	int N, height, serial;
	long long pair_count = 0;
	cin >> N;
	while (N-- > 0){
		cin >> height;
		while (!oasis.empty() && oasis.top().first < height){ // 지금 줄에 서는 사람이 맨 뒷 사람보다 키가 크면 앞으로 설 사람들은 이 사람들을 못 보므로 지금까지의 쌍을 결과값에 더함
			pair_count += oasis.top().second;
			oasis.pop();
		}
		if (oasis.empty() == true){ // 지금 줄 설 사람이 가장 키 큰 사람임ㅋㅋ
			oasis.push({height, 1});
		}
		else {
			if (oasis.top().first == height){
				serial = oasis.top().second;
				pair_count += serial; // 키가 같은 사람끼리는 서로를 볼 수 있음
				oasis.pop(); // 일단 키가 같은 사람들의 집합은 제외함
				if (!oasis.empty()){pair_count++;} // 줄에 나보다 큰 사람이 있었을 때
				oasis.push({height, serial + 1});
			}
			else { // 지금 설 사람이 현재의 맨 뒷 사람보다 작으면
				oasis.push({height, 1});
				pair_count++; // 줄에 내 앞사람이 보임
			}
		}
	}
	cout << pair_count;
}