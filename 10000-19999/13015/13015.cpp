// 13015 별 찍기 - 23
#include <iostream>
using namespace std;

int main(){
	int N, standard = 0;
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++){
		if (i == 0 || i == 2 * N - 2){
			for (int j = 0; j < N; j++)
				cout << '*';
			for (int j = 0; j < 2 * N - 3; j++)
				cout << ' ';
			for (int j = 0; j < N; j++)
				cout << '*';
		}
		else {
			for (int j = 0; j < standard; j++)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < N - 2; j++)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < (N - standard - 1) * 2; j++){
				if (j == (N - standard - 1) * 2 - 1)
					cout << '*';
				else
					cout << ' ';
			}
			for (int j = 0; j < N - 2; j++)
				cout << ' ';
			cout << '*';
		}
		if (i < N - 1)
			standard++;
		else 
			standard--;
		cout << '\n';
	}
}