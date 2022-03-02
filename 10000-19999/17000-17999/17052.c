// 17052 Lun
// https://www.acmicpc.net/problem/17052
// 거꾸로 해야 합니다
#include <stdio.h>

int remainder_one[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int main(){
	int len, idx = -1, answer, temp = 0, k;
	int sum = 0, dest = 0, double_up = 0;
	char arr[100];
	scanf("%d", &len);
	scanf("%s", arr);
	for (int i = len - 2; i >= 0; i--){
		if (arr[i] == 'x'){
			idx = double_up; 
			double_up++;
			continue;
		}
		if (double_up % 2 == 0){
			k = remainder_one[arr[i] - '0'];
		}
		else {
			k = arr[i] - '0';
		}
		sum += k;
		double_up++;
	}
	if (arr[len - 1] == 'x'){
		answer = (sum * 9) % 10;
	}
	else {
		dest = arr[len - 1] - '0';
		if (idx % 2 == 0){
			for (int i = 0; i < 10; i++){
				if (((sum + remainder_one[i]) * 9) % 10 == dest){
					answer = i;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++){
				if (((sum + i) * 9) % 10 == dest){
					answer = i;
					break;
				}
			}
			
		}
	}
	printf("%d\n", answer);
	
}