#include <iostream>
#include <string>

using namespace std;

int hamming(string &s1, string &s2){
	int ret = 0;
	for(unsigned i = 0; i < s1.length(); ++i){
		if(s1[i] != s2[i]){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		cout << "Hamming distance is " << hamming(s1, s2) << ".\n";
	}
	return 0;
}
