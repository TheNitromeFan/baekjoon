#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		int consec = 0;
		int max_consec = 0;
		for(int j = 0; j < n; ++j){
			char c;
			cin >> c;
			if(c == 'X'){
				++consec;
			}else{
				consec = 0;
			}
			max_consec = max(max_consec, consec);
		}
		cout << "The longest contiguous subsequence of X's is of length " << max_consec << '\n';
	}
	return 0;
}
