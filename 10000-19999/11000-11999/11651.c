// 11651 좌표 정렬하기 2

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

point sort[100001];

void merge(point* arr, int first, int mid, int last)
{
    int i, j, k;
    i = first;
    j = mid + 1;
    k = first;

    while (i <= mid && j <= last) {
        if (arr[i].y < arr[j].y)
            sort[k++] = arr[i++];
        else if (arr[i].y > arr[j].y)
            sort[k++] = arr[j++];
        else {
            if (arr[i].x < arr[j].x)
                sort[k++] = arr[i++];
            else if (arr[i].x > arr[j].x)
                sort[k++] = arr[j++];
        }
    }

    if (i <= mid) {
        while (i <= mid) 
            sort[k++] = arr[i++];
    }
    else {
        while (j <= last) 
            sort[k++] = arr[j++];
    }
    for (k = first; k <= last; k++)
        arr[k] = sort[k];
}

void mergesort(point* arr, int first, int last) {
    int mid;
    if (first < last) {
        mid = (first + last) / 2;
        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    point* arr = (point*)malloc(sizeof(point)*n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    
    mergesort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}

// 아니 밑에 거가 왜 안 되지
/*
#include <stdio.h>

typedef struct {
	int x;
	int y;
} P;

int N;
P arr[100001];
P tempArr[100001];

void merge(int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i].x < arr[j].x){
            tempArr[k++] = arr[i++];
		}
        else if (arr[i].x > arr[j].x){
            tempArr[k++] = arr[j++];
		}
		else {
			if (arr[i].y < arr[i].y){
				tempArr[k++] = arr[i++];
			}
			else if (arr[i].y > arr[j].y){
				tempArr[k++] = arr[j++];
			}
		}
    }
    if (i > mid){
        for (int idx = j; idx <= high; idx++){
            tempArr[k++] = arr[idx];
		}
		while (j <= high){tempArr[k++] = arr[j++];}
	}
    else {
        for (int idx = i; idx <= mid; idx++){
            tempArr[k++] = arr[idx];
		}
		// while (i <= mid){tempArr[k++] = arr[i++];}
	}
    for (int idx = low; idx <= high; idx++){
        arr[idx] = tempArr[idx];
	}
}

void mergeSort(int low, int high){
    if (high > low){
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(void){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
	}
    mergeSort(0, N - 1);
    for (int i = 0; i < N; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
	}
    return 0;
}
*/