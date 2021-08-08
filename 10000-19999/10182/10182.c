// 10182 AcidBase
// https://www.acmicpc.net/problem/10182
#include <stdio.h>
#include <math.h>

int main(){
	int T; double acid, pH;
	char H_or_OH[4];
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%s = %lf", H_or_OH, &acid);
		if (H_or_OH[0] == 'H'){ // H
			pH = -log10(acid);
		}
		else { // OH
			pH = 14.0 + log10(acid);
		}
		pH = floor(pH * 100 + 0.5) / 100;
		printf("%.2lf\n", pH);
	}
}