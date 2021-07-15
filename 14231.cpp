#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int len = 0;
	vector<int> a(MAX);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> mini(MAX);
	for(int i = 0; i < n; ++i){
		int low = 1, high = len;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(a[mini[mid]] < a[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		int new_len = low;
		mini[new_len] = i;
		len = max(len, new_len);
	}
	cout << len << '\n';
	return 0;
}
