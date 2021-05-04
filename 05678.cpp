#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i];
		}
		bool combo = false;
		int mark = 0, leti = 0;
		for(int i = 0; i < n; ++i){
			mark += a[i];
			leti += b[i];
			if(i >= 2 && !combo && a[i] == a[i - 1] && a[i] == a[i - 2] && b[i] == b[i - 1] && b[i] == b[i - 2]){
				combo = true;
			}else if(i >= 2 && !combo && a[i] == a[i - 1] && a[i] == a[i - 2]){
				mark += 30;
				combo = true;
			}else if(i >= 2 && !combo && b[i] == b[i - 1] && b[i] == b[i - 2]){
				leti += 30;
				combo = true;
			}
		}
		if(mark > leti){
			cout << 'M';
		}else if(mark < leti){
			cout << 'L';
		}else{
			cout << 'T';
		}
		cout << '\n';
	}
	return 0;
}
