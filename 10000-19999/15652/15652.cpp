// 15652 N과 M (4)
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M - 1; i++)
			if (arr[i] > arr[i + 1])
				return;
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++){
		visited[i] = true;
		arr[cnt] = i;
		func(cnt + 1);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;

	func(0);
	return 0;
}