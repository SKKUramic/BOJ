// 1120 문자열
// https://www.acmicpc.net/problem/1120
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int diff = 9999, length_diff, Alen, Blen, count;
	string A, B;
	cin >> A;
	cin >> B;
	Alen = A.length(); Blen = B.length();
	length_diff = Blen - Alen;
	for (int d = 0; d <= length_diff; d++){
		count = 0;
		for (int idx = 0; idx < Alen; idx++){
			if (A[idx] != B[d + idx]){count++;}
		}
		if (diff > count) {diff = count;}
	}
	cout << diff;
}