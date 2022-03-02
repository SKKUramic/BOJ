// 2261 가장 가까운 두 점
// https://www.acmicpc.net/problem/2261
// https://suuntree.tistory.com/233와 https://www.acmicpc.net/blog/view/25에서 배웠습니다. 왜 x좌표와 y좌표를 set에 넣을 때 바꿔줘야 시간초과가 안 뜨는 건지 모르겠네요.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef pair<int, int> pii;

vector<pii> point;
set<pii> s; // set에 들어가는 좌표들은 vector와 달리 y좌표 기준으로 정렬되어 있다

int dist(pii a, pii b){
	int x = a.first - b.first;
	int y = a.second - b.second;
	return x * x + y * y;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x, y, ans, d, start_idx = 0;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> x >> y;
		point.push_back({x, y});
	}
	sort(point.begin(), point.end());
	s.insert({point[0].second, point[0].first});
	s.insert({point[1].second, point[1].first});
	ans = dist(point[0], point[1]);
	for (int i = 2; i < N; i++){
		while (start_idx < i){
			d = point[i].first - point[start_idx].first;
			if (d * d <= ans){break;} // 지금의 점과 set 내의 점들의 거리가 현재 최단거리보다 짧으면 최단거리를 갱신해야 함
			else {
				s.erase({point[start_idx].second, point[start_idx].first});
				start_idx++;
			}
		}
		auto start = s.lower_bound({point[i].second - sqrt(ans), -100000});
		auto end = s.upper_bound({point[i].second + sqrt(ans), 100000});
		for (auto it = start; it != end; it++){ // 만약 set에 y좌표 기준 정렬이 아닌 x좌표 기준 정렬로 하면 시간 초과가 난다
			ans = min(ans, dist(*it, point[i]));
		}
		s.insert({point[i].second, point[i].first});
	}
	cout << ans;
	return 0;
}