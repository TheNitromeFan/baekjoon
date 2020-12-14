#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, k;
		cin >> n >> k;
		string s(k, '1');
		s.resize(n, '0');
		cout << "The bit patterns are\n";
		do{
			cout << s << "\n";
		}while(prev_permutation(s.begin(), s.end()));
		cout << "\n";
	}
	return 0;
}
