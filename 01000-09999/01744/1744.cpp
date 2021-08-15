// 1744 수 묶기
// https://www.acmicpc.net/problem/1744
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
long long max_sum, zero = 0;
vector<long long> negative, positive;

bool compare(long long a, long long b){return a > b;}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long num;
	int positive_idx = 0, negative_idx = 0;
	cin >> len;
	for (int i = 0; i < len; i++){
		cin >> num;
		if (num > 0){
			positive.push_back(num);
		}
		else if (num < 0){
			negative.push_back(num);
		}
		else {
			zero++;
		}
	}
	if (!positive.empty()){sort(positive.begin(), positive.end(), compare);}
	if (!negative.empty()){sort(negative.begin(), negative.end());}
	while (positive_idx + 1 < positive.size()){ // 양수는 다 곱해서 더한다
		if (positive[positive_idx] * positive[positive_idx + 1] < positive[positive_idx] + positive[positive_idx + 1]){break;} // 근데 1이 끼어있으면 말이 달라지지
		max_sum += positive[positive_idx] * positive[positive_idx + 1];
		positive_idx += 2;
	}
	while (positive_idx < positive.size()){ // 양수가 1개만 남았거나, 곱하는 것보다 더하는 게 더 이득인 상황일 때
		max_sum += positive[positive_idx++];
	}
	while (negative_idx + 1 < negative.size()){ // 음수는 절댓값이 큰 것들은 둘 다 곱해버린다
		max_sum += negative[negative_idx] * negative[negative_idx + 1];
		negative_idx += 2;
	}
	while (zero != 0){ // 음수가 남아있고 0도 좀 있다면 다 0으로 바꿔 먹는다
		negative_idx++;
		zero--;
	}
	while (negative_idx < negative.size()){ // 그래도 음수가 남아있다면 더하는 걸로 없앤다
		max_sum += negative[negative_idx++];
	}
	cout << max_sum;
}