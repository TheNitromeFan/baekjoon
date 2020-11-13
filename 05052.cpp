#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_substring(string shorter, string longer){
	if(shorter.length() > longer.length()){
		swap(shorter, longer);
	}
	for(int i = 0; i < shorter.length(); ++i){
		if(shorter[i] != longer[i]){
			return false;
		}
	}
	return true;
}

bool is_consistent(vector<string> &strings){
	for(int i = 0; i < strings.size() - 1; ++i){
		if(is_substring(strings[i], strings[i+1])){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<string> strings;
		strings.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> strings[i];
		}
		sort(strings.begin(), strings.end());
		cout << (is_consistent(strings) ? "YES" : "NO") << '\n';
	}
	return 0;
}
