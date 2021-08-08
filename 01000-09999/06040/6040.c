// 6040 Hexadecimal Conversion
// https://www.acmicpc.net/problem/6040
// 98612468213468971246으로 테스트ㄱㄱ
#include <stdio.h>
#include <string.h>

char octadecimal_number[210000];
char hexadecimal_number[110000];
char Binary_number[410000];

void hexa_to_binary(char* hexa, int len){
	int digit, idx;
	for (int i = 0; i < len; i++){
		idx = 3;
		if (hexa[i] <= '9'){
			digit = hexa[i] - '0';
		}
		else {
			digit = hexa[i] - 'A' + 10;
		}
		while (digit > 0){
			Binary_number[4 * i + idx] = (digit % 2) + '0';
			digit /= 2;
			idx--;
		}
		while (idx >= 0){
			Binary_number[4 * i + idx] = '0';
			idx--;
		}
	}
	return;
}

void binary_to_octa(char* octa, int len){
	int octa_num = 0, pow_two = 1, octa_idx = 0;
	for (int i = len - 1; i >= 0; i--){
		octa_num = octa_num + (Binary_number[i] - '0') * pow_two;
		pow_two *= 2;
		if (pow_two == 8){
			octa[octa_idx++] = octa_num + '0';
			pow_two = 1;
			octa_num = 0;
		}
	}
	octa[octa_idx] = octa_num + '0';
	return;
}

int main(){
	int hexa_len, binary_len, octa_len;
	int flags = 0;
	scanf("%s", hexadecimal_number);
	hexa_len = strlen(hexadecimal_number);
	if (hexadecimal_number[0] == '0' && hexa_len == 1){
		printf("0");
		return 0;
	}
	hexa_to_binary(hexadecimal_number, hexa_len);
	
	binary_len = strlen(Binary_number);
	binary_to_octa(octadecimal_number, binary_len);
	octa_len = strlen(octadecimal_number);
	//printf("%s\n", Binary_number);
	//printf("%s\n", octadecimal_number);
	for (int i = octa_len - 1; i >= 0; i--){
		if (flags == 0 && octadecimal_number[i] != '0'){
			flags = 1;
		}
		if (flags == 1){
			printf("%c", octadecimal_number[i]);
		}
	}
}