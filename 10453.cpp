#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string A, B;
		cin >> A >> B;
		vector<int> a, b;
		for(int j = 0; j < (int)A.length(); ++j){
			if(A[j] == 'a'){
				a.push_back(j);
			}
		}
		for(int j = 0; j < (int)B.length(); ++j){
			if(B[j] == 'a'){
				b.push_back(j);
			}
		}
		if(a.size() != b.size()){
			cout << "-1\n";
			continue;
		}
		int swaps = 0;
		for(int k = 0; k < (int)a.size(); ++k){
			swaps += abs(a[k] - b[k]);
		}
		cout << swaps << '\n';
	}
	return 0;
}
