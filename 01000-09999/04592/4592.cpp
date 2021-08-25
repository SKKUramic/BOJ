// 4592 중복을 없애자
// https://www.acmicpc.net/problem/4592
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, prev;
	cin >> N;
	while (N != 0){
		vector<int> v;
		prev = -1;
		for (int n = 0; n < N; n++){
			cin >> num;
			if (prev != num){
				v.push_back(num);
			}
			prev = num;
		}
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << "$\n";
		cin >> N;
	}
}