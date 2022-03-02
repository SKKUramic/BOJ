// 15803 PLAYERJINAH’S BOTTLEGROUNDS
// https://www.acmicpc.net/problem/15803
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pair<int, int> arr[3];
	for (int i = 0; i < 3; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + 3);
	pair<int, int> A, B;
	A.first = arr[1].first - arr[0].first;
	A.second = arr[1].second - arr[0].second;
	B.first = arr[2].first - arr[1].first;
	B.second = arr[2].second - arr[1].second;
	if (A.first * B.second == B.first * A.second){
		cout << "WHERE IS MY CHICKEN?";
	}
	else {
		cout << "WINNER WINNER CHICKEN DINNER!";
	}
}