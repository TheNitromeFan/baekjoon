#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned n;
	cin >> n;
	vector<string> channels(n, "");
	for(unsigned i = 0; i < n; ++i){
		cin >> channels[i];
	}
	string ans;
	int pointer = 0;
	while(channels[pointer] != "KBS1"){
		++pointer;
		ans += '1';
	}
	while(pointer > 0){
		swap(channels[pointer], channels[pointer - 1]);
		--pointer;
		ans += '4';
	}
	while(channels[pointer] != "KBS2"){
		++pointer;
		ans += '1';
	}
	while(pointer > 1){
		swap(channels[pointer], channels[pointer - 1]);
		--pointer;
		ans += '4';
	}
	cout << ans;
	return 0;
}
