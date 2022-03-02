// 10804 카드 역배치
// https://www.acmicpc.net/problem/10804
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int num;
	vector<int> arr;
    for(int i = 1; i <= 20; i++){
		arr.push_back(i);
	}
    for(int i = 0; i < 10; i++){
		int a, b;
		cin >> a >> b;
		reverse(arr.begin() + (a - 1), arr.begin() + b);
	}
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << ' ';
	}
    return 0;
}