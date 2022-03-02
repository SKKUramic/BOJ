// 11047 동전 0
#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, count = 0;
	int coin[1000001] = {0, };
	cin >> N >> K;
	for (int i = 0; i < N; i++){
		cin >> coin[i];
	}
	N--;
	while (K > 0){
		count += K / coin[N];
		K %= coin[N];
		N--;
	}
	cout << count;
}