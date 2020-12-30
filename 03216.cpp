#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> playback(n), download(n);
	for(int i = 0; i < n; ++i){
		cin >> playback[i] >> download[i];
	}
	int wait = download[0];
	int total_playback = 0, total_download = download[0];
	for(int i = 0; i < n - 1; ++i){
		total_download += download[i + 1];
		total_playback += playback[i];
		wait = max(wait, total_download - total_playback);
	}
	cout << wait;
	return 0;
}
