#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		string s;
		cin >> s;
		if(next_permutation(s.begin(), s.end())){
			cout << s;
		}else{
			cout << "BIGGEST";
		}
		cout << '\n';
	}
	return 0;
}
