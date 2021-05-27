#include <iostream>
#define MAX 5000
#define MAXVAL 800000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, n;
	cin >> w >> n;
	int a[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	bool weight[MAXVAL] = {};
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if(a[i] + a[j] <= w && weight[w - a[i] - a[j]]){
				cout << "YES";
				return 0;
			}
		}
		for(int j = 0; j < i; ++j){
			if(a[i] + a[j] <= w){
				weight[a[i] + a[j]] = true;
			}
		}
	}
	cout << "NO";
	return 0;
}
