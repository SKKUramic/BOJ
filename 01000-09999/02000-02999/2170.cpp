// 2170 선 긋기
// https://www.acmicpc.net/problem/2170
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> pll;
pll point[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int point_count;
	long long start, end, length = 0, temp;
	cin >> point_count;
	for (int i = 0; i < point_count; i++){
		cin >> point[i].first >> point[i].second;
		if (point[i].first > point[i].second){
			temp = point[i].first;
			point[i].first = point[i].second;
			point[i].second = temp;
		}
	}
	sort(point, point + point_count);
	start = point[0].first; end = point[0].second;
	for (int i = 1; i < point_count; i++){
		if (end < point[i].first){
			length += (end - start);
			start = point[i].first;
			end = point[i].second;
		}
		else {
			if (end < point[i].second){
				end = point[i].second;
			}
		}
	}
	length += (end - start);
	cout << length;
}