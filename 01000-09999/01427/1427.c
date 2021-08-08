// 1427 소트인사이드
#include <stdio.h>
#include <string.h>

char arr[1001];

int main(){
	int N, len;
	char temp;
	int i, j;
	scanf("%s", arr);
	len = strlen(arr);
	//printf("%d\n", len);
	for (i = 0; i < len; i++){
		temp = arr[i];
		for (j = i - 1; j >= 0; j--){
			if (arr[j] < temp){
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp;
	}
	printf("%s", arr);
	/*
	for (i = 0; i < len; i++){
		printf("%c", arr[i]);
	}
	*/
}