#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string w;
		cin >> w;
		int vowels = 0;
		for(char c : w){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
				++vowels;
			}
		}
		cout << "The number of vowels in " << w << " is " << vowels << ".\n";
	}
	return 0;
}
