#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string votes;
		cin >> votes;
		if(votes == "#"){
			break;
		}
		unsigned total = votes.length(), y = 0, n = 0, a = 0;
		for(char c : votes){
			switch(c){
				case 'Y':
					++y;
					break;
				case 'N':
					++n;
					break;
				case 'A':
					++a;
					break;
			}
		}
		if(2 * a >= total){
			cout << "need quorum\n";
		}else if(y > n){
			cout << "yes\n";
		}else if(y < n){
			cout << "no\n";
		}else{
			cout << "tie\n";
		}
	}
	return 0;
}
