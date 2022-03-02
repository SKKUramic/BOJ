//1076 저항
#include <stdio.h>
#include <string.h>

long long int color_value(char* arr){
	if (!strcmp(arr, "black")){
		return 0;
	}
	else if (!strcmp(arr, "brown")){
		return 1;
	}
	else if (!strcmp(arr, "red")){
		return 2;
	}
	else if (!strcmp(arr, "orange")){
		return 3;
	}
	else if (!strcmp(arr, "yellow")){
		return 4;
	}
	else if (!strcmp(arr, "green")){
		return 5;
	}
	else if (!strcmp(arr, "blue")){
		return 6;
	}
	else if (!strcmp(arr, "violet")){
		return 7;
	}
	else if (!strcmp(arr, "grey")){
		return 8;
	}
	else if (!strcmp(arr, "white")){
		return 9;
	}
	else {
		return -1;
	}
}

long long int color_time(char* arr){
	if (!strcmp(arr, "black")){
		return 1;
	}
	else if (!strcmp(arr, "brown")){
		return 10;
	}
	else if (!strcmp(arr, "red")){
		return 100;
	}
	else if (!strcmp(arr, "orange")){
		return 1000;
	}
	else if (!strcmp(arr, "yellow")){
		return 10000;
	}
	else if (!strcmp(arr, "green")){
		return 100000;
	}
	else if (!strcmp(arr, "blue")){
		return 1000000;
	}
	else if (!strcmp(arr, "violet")){
		return 10000000;
	}
	else if (!strcmp(arr, "grey")){
		return 100000000;
	}
	else if (!strcmp(arr, "white")){
		return 1000000000;
	}
	else {
		return -1;
	}
}

int main(){
	char color1[10];
	char color2[10];
	char color3[10];
	long long int v1, v2, t;
	scanf("%s", color1);
	v1 = color_value(color1);
	scanf("%s", color2);
	v2 = color_value(color2);
	scanf("%s", color3);
	t = color_time(color3);
	printf("%lld", (v1 * 10 + v2) * t);
}