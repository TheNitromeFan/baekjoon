#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cut(vector<int> &lengths, int k, int c, int thres, int &idx){
	int cnt = 0;
	int cur = 0;
	for(int i = k; i >= 0; --i){
		int x = lengths[i];
		if(x > thres){
			return false;
		}
		cur += x;
		if(cur > thres){
			cur = x;
			++cnt;
			idx = i;
		}
	}
	if(cnt < c){
		idx = 0;
	}
	return cnt <= c;
}

int determine_length(vector<int> &lengths, int len, int k, int c, int &idx){
	int low = 0, high = len;
	int idx1 = 0;
	while(low < high){
		int mid = (low + high) / 2;
		if(cut(lengths, k, c, mid, idx1)){
			high = mid;
			idx = idx1;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len, k, c;
	cin >> len >> k >> c;
	vector<int> pos(k);
	for(int i = 0; i < k; ++i){
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	vector<int> lengths(k + 1);
	lengths[0] = pos[0];
	for(int i = 1; i < k; ++i){
		lengths[i] = pos[i] - pos[i - 1];
	}
	lengths[k] = len - pos[k - 1];
	int idx = 0;
	int ans = determine_length(lengths, len, k, c, idx);
	cout << ans << ' ' << pos[idx];
	return 0;
}
