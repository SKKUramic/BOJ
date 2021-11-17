// 1646 피이보나치 트리
// https://www.acmicpc.net/problem/1646
#include <iostream>
#include <string>
using namespace std;

long long fiibonacci[51];
long long N;

int min(int a, int b){return a < b ? a : b;}

string Fiibonacci_Tree(long long node){
	string ret = "";
	long long v = 1, n = N - 1;
	if (node == 1){return ret;}
	while (n > 0 && v != node){
		if (v + fiibonacci[n - 1] + 1 <= node){
			v += (fiibonacci[n - 1] + 1);
			ret = ret + "R";
		}
		else {
			v += 1;
			ret = ret + "L";
			n--;
		}
		n--;
	}
	return ret;
}

int main(){
	int idx = 0, min_len;
	long long start, end;
	string Sstart, Send;
	cin >> N >> start >> end;
	fiibonacci[0] = 1; fiibonacci[1] = 1;
	for (int i = 2; i <= 50; i++){
		fiibonacci[i] = fiibonacci[i - 1] + fiibonacci[i - 2] + 1;
	}
	if (start == end){return 0;}
	Sstart = Fiibonacci_Tree(start);
	Send = Fiibonacci_Tree(end);
	min_len = min((int)Sstart.length(), (int)Send.length());
	while (idx < min_len){
		if (Sstart[idx] != Send[idx]){break;}
		idx++;
	}
	for (int k = idx; k < Sstart.length(); k++){
		cout << 'U';
	}
	for (int k = idx; k < Send.length(); k++){
		cout << Send[k];
	}
}