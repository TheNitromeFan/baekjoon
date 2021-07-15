#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int max_consec = 0;
	for(int min = 1, max = 3; max <= 10; ++min, ++max){
		int consec = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] >= min && a[i] <= max){
				++consec;
			}else{
				consec = 0;
			}
			if(max_consec < consec){
				max_consec = consec;
			}
		}
	}
	cout << max_consec << '\n';
	return 0;
}
