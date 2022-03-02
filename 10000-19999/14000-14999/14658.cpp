// 14658 하늘에서 별똥별이 빗발친다
// https://www.acmicpc.net/problem/14658
#include <iostream>
#include <utility>
using namespace std;

pair<int, int> star[100];
int N, M, L, K;

bool in_range(int x, int y, pair<int, int> star){
	return x <= star.first && star.first <= x + L && y <= star.second && star.second <= y + L;
}
// 이 함수로 생성된 트램펄린은 정작 두 별이 포함되어 있지 않을 수도 있다
// 그리고 그 두 별이 서로 같은 별일 수도 있다

int main(){
	int count, star_count, star_max = 1; // 아무리 못 해도 하나는 튕겨내지 않을까?
	scanf("%d %d %d %d", &N, &M, &L, &K);
	for (int k = 0; k < K; k++){
		scanf("%d %d", &star[k].first, &star[k].second);
	}
	for (int p1 = 0; p1 < K; p1++){
		for (int p2 = 0; p2 < K; p2++){
			count = 0;
			for (int k = 0; k < K; k++){
				if (in_range(star[p1].first, star[p2].second, star[k]) == true){
					count++;
				}
			}
			if (count > star_max){star_max = count;}
		}
	}
	cout << K - star_max;
}