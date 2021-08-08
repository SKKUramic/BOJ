// 18111 마인크래프트
#include <bits/stdc++.h> 
using namespace std; 

int answer_time = INT_MAX;
int answer_height;
int height[300];

int main(){
	int N, M, B, x;
	cin >> N >> M >> B;
	for (int i = 0; i < N * M; i++){
		cin >> x;
		height[x]++;
	}
	int time, block;
	for (int h = 256; h >= 0; h--){
		time = 0; block = 0;
		for (int i = 0; i < h; i++){
			time += height[i] * (h - i);
			block += height[i] * (i - h);
		} // 블록 설치
		for (int k = h + 1; k <= 256; k++){
			time += height[k] * (k - h) * 2;
			block += height[k] * (k - h);
		} // 블록 파괴
		if (block + B < 0) {continue;}
		if (time < answer_time){
			answer_time = time;
			answer_height = h;
		}
	}
	cout << answer_time << " " << answer_height << endl;
}