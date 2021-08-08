// 11399 ATM
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int N, i;
	int ans = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for (i = 0; i < N; i++) {
        ans += arr[i] * (N - i);
    }
    printf("%d\n", ans);
    free(arr);
    return 0;
}