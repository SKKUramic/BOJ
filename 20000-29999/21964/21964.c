// 21964 선린인터넷고등학교 교가
// https://www.acmicpc.net/problem/21964
#include <stdio.h>

int main(){
	int len;
	char arr[100001];
	scanf("%d", &len);
	scanf("%s", arr);
	for (int i = len - 5; i < len; i++){
		printf("%c", arr[i]);
	}
}