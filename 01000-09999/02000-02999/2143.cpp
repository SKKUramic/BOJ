// 2143 두 배열의 합
// https://www.acmicpc.net/problem/2143
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Lidx, Ridx;
long long T, An, Ann, Bn, Bnn, temp, answer = 0;
long long A[1001], B[1001];
vector<long long> Asum, Bsum;

int lower_bound(long long goal){
	int start = 0, count = Bnn, step;
	while (count > 0){
		step = count / 2;
		if (goal > Bsum[start + step]){
			start += (step + 1);
			count -= (step + 1);
		}
		else {count = step;}
	}
	return start;
}

int upper_bound(long long goal){
	int start = 0, count = Bnn, step;
	while (count > 0){
		step = count / 2;
		if (goal >= Bsum[start + step]){
			start += (step + 1);
			count -= (step + 1);
		}
		else {count = step;}
	}
	return start;
}

long long FindNumber(long long goal){
	Lidx = lower_bound(goal);
	Ridx = upper_bound(goal);
	return Ridx - Lidx;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	cin >> An;
	for (int a = 0; a < An; a++){cin >> A[a];}
	cin >> Bn;
	for (int b = 0; b < Bn; b++){cin >> B[b];}
	for (int i = 0; i < An; i++){
		temp = A[i];
		Asum.push_back(temp);
		for (int j = i + 1; j < An; j++){
			temp += A[j];
			Asum.push_back(temp);
		}
	}
	for (int i = 0; i < Bn; i++){
		temp = B[i];
		Bsum.push_back(temp);
		for (int j = i + 1; j < Bn; j++){
			temp += B[j];
			Bsum.push_back(temp);
		}
	}
	Ann = An * (An + 1) / 2;
	Bnn = Bn * (Bn + 1) / 2;
	sort(Asum.begin(), Asum.end()); sort(Bsum.begin(), Bsum.end());
	for (int i = 0; i < Ann; i++){
		Lidx = Ridx = Bnn - 1;
		answer += FindNumber(T - Asum[i]);
	}
	cout << answer;
}