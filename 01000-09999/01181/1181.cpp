// 1181 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<string> word;

bool compare(string word1, string word2){
	if (word1.length() == word2.length())
		return word1 < word2;
	else 
		return word1.length() < word2.length();
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string name;
	vector<string> word;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> name;
		if (find(word.begin(), word.end(), name) == word.end())
			word.push_back(name);
	}
	sort(word.begin(), word.end(), compare);
	
	for (auto x = word.begin(); x != word.end(); x++)
		cout << *x << endl;
	return 0;
	
	/*
	for(int i = 0; i < word.size(); i++){
		cout << word[i] << '\n';
	}
	*/
}