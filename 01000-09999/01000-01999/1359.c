// 1588 수열
// https://www.acmicpc.net/problem/1588
#include <stdio.h>

int Comb(int m, int k){
	if (k == 0 || k == m){return 1;}
	int S = 1, P = 1;
	for (int s = m; s > m - k; s--){
		S *= s;
	}
	for (int p = k; p >= 1; p--){
		P *= p;
	}
	return S / P;
}

int main(){
	int n, m, k, all, possible = 0;
	scanf("%d %d %d", &n, &m, &k);
	all = Comb(n, m);
	while(m >= k){
        if (n - m < m - k){
            k++;
            continue;
        }
        possible += Comb(m, k) * Comb(n - m, m - k);
        k++;
    }
	printf("%.12lf", (double)possible / (double)all);
}