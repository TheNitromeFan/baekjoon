#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	int maxConsec = 0;
	for(int i = 0; i < n; ++i){
		int j = 0;
		while(j < n && b[j] == b[i]){
			++j;
		}
		while(j < n){
			if(b[j] == b[i]){
				++j;
				continue;
			}
			int cmp = b[j];
			int consec = 0;
			while(j < n && (b[j] == cmp || b[j] == b[i])){
				if(b[j] == cmp){
					++consec;
				}
				++j;
			}
			// cout << consec << '\n';
			if(maxConsec < consec){
				maxConsec = consec;
			}
		}
		// cout << '\n';
	}
	cout << maxConsec;
	return 0;
}
