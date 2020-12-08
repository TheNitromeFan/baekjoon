#include <iostream>
#include <string>

using namespace std;

void flip(string &bulbs, unsigned x){
	for(unsigned i = x; i <= bulbs.length(); i += x){
		if(bulbs[i - 1] == 'Y'){
			bulbs[i - 1] = 'N';
		}else{
			bulbs[i - 1] = 'Y';
		}
	}
}

int flips(string &bulbs){
	int ret = 0;
	for(unsigned i = 1; i <= bulbs.length(); ++i){
		if(bulbs[i - 1] == 'Y'){
			++ret;
			flip(bulbs, i);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string bulbs;
	cin >> bulbs;
	cout << flips(bulbs);
	return 0;
}
