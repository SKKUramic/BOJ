// 1071 소트
// https://www.acmicpc.net/problem/1071
// 동아리 활동하면서 풀었던 문제입니다. 이게 왜 소트인지
#include <iostream>
#include <vector>
using namespace std;

int arr[1001] = {0, };

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, x;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num;
		arr[num]++;
	}
	for (int n = 0; n <= 1000; n++){
		if (arr[n] == 0){continue;} // 출력할 숫자가 없음
		if (arr[n + 1] > 0){ // 연속되는 숫자가 존재한다면
			x = n + 2; // 연속되지 않는 숫자 중 가장 작은 숫자
			while (x <= 1000 && arr[x] == 0){x++;} // 연속되지 않는 숫자들 중 존재하는 가장 작은 숫자를 구한다
			if (x > 1000){ // 출력해야 할 숫자가 n과 n + 1만 존재함, 예제 2가 바로 이 경우
				while (arr[n + 1] > 0){ // 정렬 시 연속되면 안 되므로 n + 1을 먼저 다 출력(직전에 출력한 수는 아무리 커도 n - 1)
					cout << n + 1 << ' ';
					arr[n + 1]--;
				}
				while (arr[n] > 0){
					cout << n << ' ';
					arr[n]--;
				}
			}
			else { // n, n + 1 말고도 출력할 수가 존재한다
				while (arr[n] > 0){ // 일단 n을 전부 다 출력
					cout << n << ' ';
					arr[n]--;
				}
				cout << x << ' '; // 문제 규칙을 지키기 위해 x를 딱 하나만 출력한 후, n + 1을 출력할 준비를 한다
				arr[x]--;
			}
		}
		else { // 연속되는 숫자가 존재하지 않다면 그냥 싹 다 출력한다
			while (arr[n] > 0){
				cout << n << ' ';
				arr[n]--;
			}
		}
	}
}