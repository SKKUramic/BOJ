// 9251 LCS
#include <iostream>
#include <string>
using namespace std;

int LCS[1001][1001];
string word1, word2;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int len1, len2;
	cin >> word1;
	cin >> word2;
	len1 = word1.length();
	len2 = word2.length();
	for (int i = 0; i <= len1; i++){
		for (int j = 0; j <= len2; j++){
			if (i == 0 || j == 0){
				LCS[i][j] = 0;
			}
			else if (word1[i - 1] == word2[j - 1]){
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
			}
			//cout << LCS[i][j] << ' ';
		}
		//cout << '\n';
	}
	cout << LCS[len1][len2];
}