// 11564 점프왕 최준민
// https://www.acmicpc.net/problem/11564
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long k, a, b, temp, ans;
	cin >> k >> a >> b;
	if (a < 0 && b > 0){
		a = abs(a); b = abs(b);
		cout << a / k + b / k + 1; // (a부터 -1까지, 1부터 b까지, 0)
	}
	else {
		a = abs(a); b = abs(b);
		if (a > b){
			temp = a;
			a = b;
			b = temp;
		}
		ans = b / k - a / k; // (0부터 b까지) - (0부터 a까지) -> (a + 1부터 b까지)
		if (a % k == 0){ans++;} // a에 있는 초콜릿을 먹을 수 있을 경우
		cout << ans;
	}
}