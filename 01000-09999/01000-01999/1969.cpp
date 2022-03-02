// 1969 DNA
// https://www.acmicpc.net/problem/1969
#include <iostream>
#include <string>
using namespace std;

int MinSum = 0;
int DistanceSum[1001][4] = {0, }; // A, C, G, T
string DNA[1001], AnswerDNA = "";

void HammingDNA(int N){
	int idx, minvalue;
	for (int n = 0; n < N; n++){
		minvalue = 99999999; idx = 0;
		for (int k = 0; k < 4; k++){
			if (minvalue > DistanceSum[n][k]){
				idx = k;
				minvalue = DistanceSum[n][k];
			}
		}
		if (idx == 0){AnswerDNA.push_back('A');}
		else if (idx == 1){AnswerDNA.push_back('C');}
		else if (idx == 2){AnswerDNA.push_back('G');}
		else if (idx == 3){AnswerDNA.push_back('T');}
		MinSum += minvalue;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, D;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> DNA[i];
	}
	for (int i = 0; i < N; i++){
		for (int idx = 0; idx < M; idx++){
			for (int k = 0; k < 4; k++){DistanceSum[idx][k]++;}
			if (DNA[i][idx] == 'A'){
				DistanceSum[idx][0]--;
			}
			else if (DNA[i][idx] == 'C'){
				DistanceSum[idx][1]--;
			}
			else if (DNA[i][idx] == 'G'){
				DistanceSum[idx][2]--;
			}
			else if (DNA[i][idx] == 'T'){
				DistanceSum[idx][3]--;
			}
		}
	}
	HammingDNA(M);
	cout << AnswerDNA << '\n' << MinSum;
}