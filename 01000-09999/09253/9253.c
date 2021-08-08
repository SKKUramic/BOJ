// 9253 스페셜 저지
// https://www.acmicpc.net/problem/9253
// https://baeharam.github.io/posts/algorithm/kmp/ 말고도 여러 블로그에서 읽으면서 겨우 이해했습니다. KMP 그들은 도데체
#include <stdio.h>
#include <string.h>

char arr1[200001];
char arr2[200001];
char Input[200001];
int pi[200001] = {0, };

int main(){
	scanf("%s", arr1);
	scanf("%s", arr2);
	scanf("%s", Input);
	int len1, len2, len_input;
	int start = 1, input_idx = 0, is_same = 0;
	len1 = strlen(arr1);
	len2 = strlen(arr2);
	len_input = strlen(Input);
	while (start + input_idx < len_input){ // failure function
		if (Input[start + input_idx] == Input[input_idx]){ // 비교하고 있는 두 문자가 서로 같을 때
			input_idx++;
			pi[start + input_idx - 1] = input_idx; // 연속해서 같은 문자가 하나 더 생김
		}
		else { // 같지 않을 때
			if (input_idx == 0){ // 처음부터 틀렸으면 start를 한 칸 오른쪽으로 옮김
				start++;
			}
			else {
				start += (input_idx - pi[input_idx - 1]); // start를 적절한 위치로 옮김
				input_idx = pi[input_idx - 1]; // 연속한 문자의 개수 조정
			}
		}
	}
	//for (int i = 0 ; i < len_input; i++){printf("pi[%d]: %d\n", i, pi[i]);}
	start = 0; input_idx = 0;
	while (start <= len1 - len_input){
		if (input_idx < len_input && arr1[start + input_idx] == Input[input_idx]){
			input_idx++;
			if (input_idx == len_input){
				is_same++;
				break;	// 끝!
			}
		}
		else {
			if (input_idx == 0){start++;}
			else {
				start += (input_idx - pi[input_idx - 1]);
				input_idx = pi[input_idx - 1];
			}
		}
	}
	start = 0; input_idx = 0;
	while (start <= len2 - len_input){
		if (input_idx < len_input && arr2[start + input_idx] == Input[input_idx]){
			input_idx++;
			if (input_idx == len_input){
				is_same++;
				break;	// 끝!
			}
		}
		else {
			if (input_idx == 0){start++;}
			else {
				start += (input_idx - pi[input_idx - 1]);
				input_idx = pi[input_idx - 1];
			}
		}
	}
	if (is_same == 2){
		printf("YES");
	}
	else {
		printf("NO");
	}
}