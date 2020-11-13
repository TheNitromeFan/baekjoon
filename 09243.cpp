#include <iostream>
#include <string>

using namespace std;

bool success(string s1, string s2, int n){
	for(unsigned idx = 0; idx < s1.length(); ++idx){
		if(((int)s1[idx] + s2[idx]) % 2 != n % 2){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	cout << "Deletion " << (success(s1, s2, n) ? "succeeded" : "failed");
	return 0;
}
