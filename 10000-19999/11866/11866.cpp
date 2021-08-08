// 11866 요세푸스 문제 0
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	int N, K, div = -1, count = 0;
	cin >> N >> K;
	cout << '<';
	for (int i = 1; i <= N; i++){
		v.push_back(i);
	}
	while (N > 0){
		div += K;
		if (div >= N){
			div %= N;
		}
		cout << v[div];
		N--;
		//count++;
		if (N > 0){
			cout << ", ";
			v.erase(v.begin() + div);
		}
		div--;
	}
	cout << '>';
	return 0;
}