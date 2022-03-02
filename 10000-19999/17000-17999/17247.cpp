// 17247 택시 거리
// https://www.acmicpc.net/problem/17247
#include <iostream>
#include <utility>
#include <cstdlib>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, num;
	pair<int, int> x = {-1, -1}, y = {-1, -1};
	cin >> N >> M;
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			cin >> num;
			if (num == 1){
				if (x.first != -1){
					y.first = n;
					y.second = m;
				}
				else {
					x.first = n;
					x.second = m;
				}
			}
		}
	}
	printf("%d", abs(x.first - y.first) + abs(x.second - y.second));
}