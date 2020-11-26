#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, x;
		cin >> n >> x;
		vector<int> s(n);
		for(int i = 0; i < n; ++i){
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		unsigned idx1 = 0, idx2 = s.size() - 1;
		int disks = 0;
		while(idx1 < idx2){
			if(s[idx1] + s[idx2] <= x){
				++idx1;
				--idx2;
			}else{
				--idx2;
			}
			++disks;
		}
		if(idx1 == idx2){
			++disks;
		}
		cout << "Case #" << a0 << ": " << disks << "\n";
	}
	return 0;
}
