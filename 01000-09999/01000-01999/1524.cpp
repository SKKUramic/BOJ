// 1524 세준세비
// https://www.acmicpc.net/problem/1524
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> S_soilders;
priority_queue<int, vector<int>, greater<int>> B_soilders;

int main(){
	int T, S_soilders_count, B_soilders_count, temp;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d %d", &S_soilders_count, &B_soilders_count);
		for (int s = 0; s < S_soilders_count; s++){
			scanf("%d", &temp);
			S_soilders.push(temp);
		}
		for (int b = 0; b < B_soilders_count; b++){
			scanf("%d", &temp);
			B_soilders.push(temp);
		}
		while (S_soilders_count != 0 && B_soilders_count != 0){
			if (S_soilders.top() < B_soilders.top()){
				//printf("S_soilders %d pop out!\n", S_soilders.top());
				S_soilders.pop();
				S_soilders_count--;
			}
			else {
				//printf("B_soilders %d pop out!\n", B_soilders.top());
				B_soilders.pop();
				B_soilders_count--;
			}
		}
		if (S_soilders_count != 0){
			printf("S\n");
		}
		else if (B_soilders_count != 0){
			printf("B\n");
		}
		else {
			printf("C\n");
		}
		while (!S_soilders.empty()){S_soilders.pop();}
		while (!B_soilders.empty()){B_soilders.pop();}
	}
}