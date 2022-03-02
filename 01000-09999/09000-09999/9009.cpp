// 9009 피보나치
// https://www.acmicpc.net/problem/9009
#include <iostream>
#include <vector>
using namespace std;

long long fibonacci[50];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fibonacci[0] = 0; fibonacci[1] = 1;
	for (int i = 2; i < 50; i++){
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	int T;
	long long n;
	cin >> T;
	while (T-- > 0){
		vector<long long> p;
		cin >> n;
		int idx = 49;
		while (n > 0){
			if (fibonacci[idx] <= n){
				p.push_back(fibonacci[idx]);
				n -= fibonacci[idx];
			}
			idx--;
		}
		for (int i = p.size() - 1; i >= 0; i--){
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
}
