// 2217 로프
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int N, i, k;
	int ans = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for (i = 0; i < N; i++) {
        k = arr[i] * (N - i);
        if (ans < k) {
            ans = k;
        }
    }
    printf("%d\n", ans);
    free(arr);
    return 0;
}