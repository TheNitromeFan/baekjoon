#include <iostream>
#include <string>

using namespace std;

int main(){
	int x;
	cin >> x;
	string word;
	cin >> word;
	string w0 = word;
	unsigned n = word.length();
	int cycle;
	for(cycle = 1; cycle <= x; ++cycle){
		string w = word;
		for(unsigned i = 0; i < n; ++i){
			if(i % 2 == 0){
				w[i / 2] = word[i];
			}else{
				w[n - 1 - i / 2] = word[i];
			}
		}
		if(w0 == w){
			break;
		}
		word = w;
	}
	x %= cycle;
	word = w0;
	for(int cycle = 1; cycle <= x; ++cycle){
		string w = word;
		for(unsigned i = 0; i < n; ++i){
			if(i % 2 == 0){
				w[i / 2] = word[i];
			}else{
				w[n - 1 - i / 2] = word[i];
			}
		}
		word = w;
	}
	cout << word;
	return 0;
}
