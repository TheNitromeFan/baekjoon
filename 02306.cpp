#include <iostream>
#include <string>
#define MAX (500 + 1)

using namespace std;

int main(){
	string dna;
	cin >> dna;
	int str[MAX][MAX] = {};
	int ans = 0;
	for(unsigned len = 2; len <= dna.length(); ++len){
		for(unsigned i = 0; i + len <= dna.length(); ++i){
			unsigned j = i + len;
			if(((dna[i] == 'a' && dna[j - 1] == 't') || (dna[i] == 'g' && dna[j - 1] == 'c')) && str[i][j] < str[i + 1][j - 1] + 2){
				str[i][j] = str[i + 1][j - 1] + 2;
			}
			for(unsigned k = i + 1; k < j; ++k){
				if(str[i][j] < str[i][k] + str[k][j]){
					str[i][j] = str[i][k] + str[k][j];
				}
			}
			if(ans < str[i][j]){
				ans = str[i][j];
			}
		}
	}
	/*
	for(unsigned i = 0; i <= dna.length(); ++i){
		for(unsigned j = 0; j <= dna.length(); ++j){
			cout << str[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	cout << ans;
	return 0;
}
