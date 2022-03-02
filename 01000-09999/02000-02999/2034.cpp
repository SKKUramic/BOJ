// 2034 반음
// https://www.acmicpc.net/problem/2034
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<pair<char, char>> answer;
	char seven_tones[12] = {'C', '?', 'D', '?', 'E', 'F', '?', 'G', '?', 'A', '?', 'B'};
	char start, end;
	int seven_tones_idx[7] = {0, 2, 4, 5, 7, 9, 11};
	int arr[10001];
	int N, tones_idx, go, count = 0;
	cin >> N;
	for (int a = 0; a < N; a++){
		cin >> arr[a];
	}
	for (int i = 0; i < 7; i++){
		tones_idx = seven_tones_idx[i];
		count = 0;
		for (int j = 0; j < N; j++){
			if (j == 0){
				start = seven_tones[tones_idx];
			}
			tones_idx += arr[j];
			while (tones_idx >= 12){tones_idx -= 12;}
			while (tones_idx < 0){tones_idx += 12;}
			if (seven_tones[tones_idx] == '?'){
				break;
			}
			count++;
			if (j == N - 1){
				end = seven_tones[tones_idx];
			}
		}
		if (count == N){
			answer.push_back({start, end});
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++){
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}
}