// 9047 6174
// https://www.acmicpc.net/problem/9047
#include <stdio.h>

int main(){
	int count, num, rev_num, temp, TC;
	int index[10], index2[10];
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &num);
		count = 0;
		while (num != 6174){
			for (int i = 0; i < 10; i++){index[i] = 0; index2[i] = 0;}
			temp = 4;
			while (temp > 0){
				index[num % 10]++;
				index2[num % 10]++;
				num /= 10;
				temp--;
			}
			num = 0; rev_num = 0;
			for (int i = 9; i >= 0; i--){
				if (index[i] > 0){
					while (index[i] > 0){
						num = num * 10 + i;
						index[i]--;
					}
				}
			}
			for (int i = 0; i < 10; i++){
				if (index2[i] > 0){
					while (index2[i] > 0){
						rev_num = rev_num * 10 + i;
						index2[i]--;
					}
				}
			}
			num = num - rev_num;
			count++;
		}
		printf("%d\n", count);
	}
}