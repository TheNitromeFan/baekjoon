#include <iostream>
#include <string>
#include <vector>

using namespace std;

int exact_matches(string &s1, string &s2, vector<bool> &m1, vector<bool> &m2){
	int ret = 0;
	for(int i = 0; i < 4; ++i){
		if(s1[i] == s2[i]){
			m1[i] = true;
			m2[i] = true;
			++ret;
		}
	}
	return ret;
}

int partial_matches(string &s1, string &s2, vector<bool> &m1, vector<bool> &m2){
	int ret = 0;
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(i != j && s1[i] == s2[j] && !m1[i] && !m2[j]){
				m1[i] = true;
				m2[j] = true;
				++ret;
				break;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string s1, s2;
		cin >> s1 >> s2;
		vector<bool> matched1(4), matched2(4);
		int a = exact_matches(s1, s2, matched1, matched2);
		int b = partial_matches(s1, s2, matched1, matched2);
		cout << "For secret = " << s1 << " and guess = " << s2 << ", "  << a << " circles and "
		<< b << " squares will light up.\n";
	}
	return 0;
}
