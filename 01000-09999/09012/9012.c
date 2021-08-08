// 9012 괄호
#include <stdio.h>
#include <string.h>

char arr[100];

void init(){
	for (int i = 0; i < 100; i++){
		arr[i] = '\0';
	}
	return;
}

int main(){
	int len, test, bracket = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%s", arr);
		len = strlen(arr);
		for (int j = 0; j < len; j++){
			if (arr[j] == '('){
				bracket++;
			}
			else if (arr[j] == ')') {
				bracket--;
				if (bracket < 0){
					break;
				}
			}
		}
		if (bracket == 0){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		bracket = 0;
		init();
	}
	return 0;
}