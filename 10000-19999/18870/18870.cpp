// 18870 좌표 압축
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
typedef struct number{
	int num;
	int rank;
} number;
*/
vector<pair<int, int>> vec;
int ans[1000001];

bool compare(pair<int, int> x, pair<int, int> y){
	return x.first < y.first;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, temp, num, value;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> temp;
		vec.push_back({temp, i});
		/*
		if (find(vec.begin(), vec.end(), arr[i]) == vec.end())
			vec.push_back({arr[i], i});
		*/
	}
	sort(vec.begin(), vec.end(), compare);
	
	num = vec[0].first;
	value = 0;
	ans[vec[0].second] = 0;
	
	for (int i = 1; i < N; i++){
		if (num == vec[i].first)
			ans[vec[i].second] = value;
		else {
			num = vec[i].first;
			value++;
			ans[vec[i].second] = value;
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << ' ';
}