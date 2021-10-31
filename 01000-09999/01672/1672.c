// 1672 DNA 해독
// https://www.acmicpc.net/problem/1672
#include <stdio.h>
#include <string.h>

char DNA[1000001];

char Nucleic(char an, char an_1){
	if (an == an_1){return an;}
	if (an == 'A'){
		if (an_1 == 'G'){
			return 'C';
		}
		else if (an_1 == 'C'){
			return 'A';
		}
		else if (an_1 == 'T'){
			return 'G';
		}
	}
	else if (an == 'G'){
		if (an_1 == 'A'){
			return 'C';
		}
		else if (an_1 == 'C'){
			return 'T';
		}
		else if (an_1 == 'T'){
			return 'A';
		}
	}
	else if (an == 'C'){
		if (an_1 == 'A'){
			return 'A';
		}
		else if (an_1 == 'G'){
			return 'T';
		}
		else if (an_1 == 'T'){
			return 'G';
		}
	}
	else if (an == 'T'){
		if (an_1 == 'A'){
			return 'G';
		}
		else if (an_1 == 'G'){
			return 'A';
		}
		else if (an_1 == 'C'){
			return 'G';
		}
	}
	return '!'; // ERROR
}

int main(){
	int DNA_len;
	scanf("%d %s", &DNA_len, DNA);
	if (DNA_len == 1){
		printf("%c", DNA[0]);
		return 0;
	}
	for (int i = DNA_len - 1; i > 0; i--){
		DNA[i - 1] = Nucleic(DNA[i], DNA[i - 1]);
	}
	printf("%c", DNA[0]);
}