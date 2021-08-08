// 2495 연속구간
#include <stdio.h>
#include <stdlib.h>

int main() {
	int F, X, keep, count, keep_count;
	int answer[3];
	for (int x = 0; x < 3; x++) {
		keep = -1;
		count = 1;
		keep_count = 1;
		scanf("%d", &X);
		keep = X % 10;
		F = keep;
		X /= 10;
		while (X > 0) {
			keep = X % 10;
			if (keep == F) {
				keep_count++;
				if (count < keep_count) {
					count = keep_count;
				}
			}
			else if (keep != F) {
				F = keep;
				keep_count = 1;
			}
			X /= 10;
		}
		answer[x] = count;
	}
	printf("%d\n%d\n%d", answer[0], answer[1], answer[2]);
}