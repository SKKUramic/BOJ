// 14888 연산자 끼워넣기
#include <iostream>
//#define INT_MIN –2147483648
//#define INT_MAX 2147483647
using namespace std;

int number, answer;
int num[12] = {0, };
bool visit[12];
int math_sign[4] = {0, 0, 0, 0}; // 0 +, 1 -, 2 x, 3 /
int min_ = 1200000000, max_ = -1200000000;//–2147483648;

void find_maxmin(int value_, int idx){
	int result = 0;
	if (idx == number - 1){
		if (value_ > max_){
			max_ = value_;
		}
		if (value_ < min_){
			min_ = value_;
		}
		return;
	}
	//visit[idx] = true;
	if (!visit[idx]){
		visit[idx] = true;
		if (math_sign[0] != 0){
			//cout << 0 << '\n';
			math_sign[0]--;
			result = value_ + num[idx];
			find_maxmin(result, idx + 1);
			math_sign[0]++;
		}
		if (math_sign[1] != 0){
			//cout << 1 << '\n';
			math_sign[1]--;
			result = value_ - num[idx];
			find_maxmin(result, idx + 1);
			math_sign[1]++;
		}
		if (math_sign[2] != 0){
			//cout << 2 << '\n';
			math_sign[2]--;
			result = value_ * num[idx];
			find_maxmin(result, idx + 1);
			math_sign[2]++;
		}
		if (math_sign[3] != 0){
			//cout << 3 << '\n';
			math_sign[3]--;
			result = value_ / num[idx];
			find_maxmin(result, idx + 1);
			math_sign[3]++;
		}
	}
	visit[idx] = false;
	return;
}

int main(){
	//int number;
	cin >> number;
	cin >> answer;
	for (int i = 0; i < number - 1; i++)
		cin >> num[i];
	cin >> math_sign[0] >> math_sign[1] >> math_sign[2] >> math_sign[3];
	//idx = 0;
	find_maxmin(answer, 0);
	cout << max_ << '\n';
	cout << min_;
}