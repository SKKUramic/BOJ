// 10816 숫자 카드 2
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500001;

int N, M;
int low, high, answer;
int findarr[MAX];
int arr[MAX];
int tempArr[MAX];

int lower(int target, int size_num){
	int first, last, middle;
	first = 0; last = size_num - 1;
	while (last > first){
		middle = (first + last) / 2;
		if (arr[middle] >= target)
			last = middle;
		else 
			first = middle + 1;
	}
	return last;
}

int higher(int target, int size_num){
	int first, last, middle;
	first = 0; last = size_num - 1;
	while (last > first){
		middle = (first + last) / 2;
		if (arr[middle] > target)
			last = middle;
		else 
			first = middle + 1;
	}
	return last;
}

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
void mergeSort(int low, int high){
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
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    mergeSort(0, N - 1);
	cin >> M;
    for (int i = 0; i < M; i++)
        scanf("%d", &findarr[i]);
    for (int i = 0; i < M; i++){
		low = lower(findarr[i], N);
		high = higher(findarr[i], N);
		if (high == N - 1 && arr[high] == findarr[i]) {high++;}
		cout << high - low << ' ';
	}
    return 0;
}