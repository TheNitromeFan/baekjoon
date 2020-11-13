#include <iostream>
#include <string>

using namespace std;

void print_crossword(string a, string b){
	for(int i = 0; i < a.length(); ++i){
		for(int j = 0; j < b.length(); ++j){
			if(a[i] == b[j]){
				for(int k = 0; k < b.length(); ++k){
					for(int l = 0; l < a.length(); ++l){
						if(k == j){
							cout << a[l];
						}else if(l == i){
							cout << b[k];
						}else{
							cout << '.';
						}
					}
					cout << '\n';
				}
				return;
			}
		}
	}
}

int main(){
	string a, b;
	cin >> a >> b;
	print_crossword(a, b);
	return 0;
}
