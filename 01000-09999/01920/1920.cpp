// 1920 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int N, M;
int S, E, F = 0;
int findarr[MAX];
int arr[MAX];
int tempArr[MAX];

void merge(int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }
    if (i > mid)
        for (int idx = j; idx <= high; idx++)
            tempArr[k++] = arr[idx];
    else
        for (int idx = i; idx <= mid; idx++)
            tempArr[k++] = arr[idx];
    for (int idx = low; idx <= high; idx++)
        arr[idx] = tempArr[idx];
}
void mergeSort(int low, int high)
{
    if (high>low)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(void)
{
	int flags = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    mergeSort(0, N - 1);
	cin >> M;
	//printf("%d\n", M);
    for (int i = 0; i < M; i++)
        scanf("%d", &findarr[i]);
    for (int i = 0; i < M; i++){
		flags = 0;
		S = 0;
		E = N - 1;
		while (E >= S){
			F = (S + E) / 2;
			//printf("%dth, S: %d, E: %d, F: %d, arr[F]: %d, findarr[i]: %d\n", i, S, E, F, arr[F], findarr[i]);
			if (arr[F] == findarr[i]){
				flags = 1;
				printf("1\n");
				break;
			}
			else if (arr[F] < findarr[i])
				S = F + 1;
			else 
				E = F - 1;
		}
		//printf("%d %d\n", S, E);
		
		if (!flags)
			printf("0\n");
		//printf("%dth, S: %d, E: %d, F: %d, arr[F]: %d, findarr[i]: %d\n\n", i, S, E, F, arr[F], findarr[i]);
	}
		
    return 0;
}