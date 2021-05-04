#include <iostream>
#include <vector>

using namespace std;

bool fibonacci(vector<int> &seq){
	for(unsigned i = 2; i < seq.size(); ++i){
		if(seq[i] != seq[i - 1] + seq[i - 2]){
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
		int k;
		cin >> k;
		vector<int> seq(k);
		for(int i = 0; i < k; ++i){
			cin >> seq[i];
		}
		if(fibonacci(seq)){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << '\n';
	}
	return 0;
}
