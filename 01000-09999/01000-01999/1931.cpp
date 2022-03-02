// 1931 회의실 배정
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time {
	int start;
	int end;
};

bool cmp(Time f, Time s) {
	if (f.end == s.end) {
		return f.start < s.start;
	}
	else {
		return f.end < s.end;
	}
}

int main() {
	int N;
	cin >> N;
	vector<Time> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i].start >> t[i].end;
	}
	sort(t.begin(), t.end(), cmp);
	int answer = 0;
	int endtime = 0;
	for (int i = 0; i < t.size(); i++) {
		if (endtime <= t[i].start) {
			endtime = t[i].end;
			answer++;
		}
	}
	cout << answer << endl;
}