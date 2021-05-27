#include <iostream>
#include <algorithm>

using namespace std;

bool contest(int e, int em, int m, int mh, int h, int x){
	if(e + em < x || h + mh < x){
		return false;
	}
	em -= max(0, x - e);
	mh -= max(0, x - h);
	return m + em + mh >= x;
}

int search(int e, int em, int m, int mh, int h){
	int low = 0, high = 1000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(contest(e, em, m, mh, h, mid)){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, em, m, mh, h;
	cin >> e >> em >> m >> mh >> h;
	cout << search(e, em, m, mh, h);
	return 0;
}
