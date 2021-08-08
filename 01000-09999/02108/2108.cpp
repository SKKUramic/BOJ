// 2108 통계학
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500001;

int N, many = 0, flag = 0;
int average = 0, much;
int counter[8001] = {0, };
int arr[MAX];
int tempArr[MAX];

void merge(int low, int mid, int high)
{
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
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		average += arr[i];
		counter[arr[i] + 4000]++;
	}
    mergeSort(0, N - 1);
	for (int i = 0; i <= 8000; i++){
		if (counter[i] > many){
			many = counter[i];
		}
	}
	for (int i = 0; i <= 8000; i++){
		if (counter[i] == many){
			much = i - 4000;
			if (flag == 0){
				flag++;
			}
			else if (flag == 1){
				break;
			}
		}
	}
	printf("%.0f\n", (double)average / N);
	printf("%d\n", arr[N / 2]);
	printf("%d\n", much);
	printf("%d\n", arr[N - 1] - arr[0]);
	/*
    for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
    */
	return 0;
}