#include <iostream>
#define MAX 2005

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int len = 0;
	static int a[MAX], min[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		int low = 1, high = len;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(a[min[mid]] > a[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		int new_len = low;
		min[new_len] = i;
		if(new_len > len){
			len = new_len;
		}
	}
	cout << n - len;
	return 0;
}
