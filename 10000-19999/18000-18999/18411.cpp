// 18411 試験 (Exam)
#include <iostream>
using namespace std;

int main(){
	int arr[3];
	int temp;
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < 3; i++){
		for (int j = i; j < 2; j++){
			if (arr[j] < arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << arr[0] + arr[1];
}