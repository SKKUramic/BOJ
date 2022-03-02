// 21600 계단
// https://www.acmicpc.net/problem/21600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> histogram;
	int N, num, height = 1, max_height = 1;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num;
		histogram.push_back(num);
	}
	for (int n = 1; n < N; n++){
		if (height >= histogram[n]){
			height = histogram[n];
		}
		else {
			height++;
		}
		if (max_height < height) {max_height = height;}
	}
	cout << max_height;
}