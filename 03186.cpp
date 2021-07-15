#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, l, n;
	string sensor;
	cin >> k >> l >> n >> sensor;
	sensor = "0" + sensor + string(20000, '0');
	int last_seen = 1000000000, last_unseen = 0;
	bool ready = false;
	vector<int> flushes;
	for(int time = 1; time <= n + 20000; ++time){
		if(sensor[time] == '0'){
			last_unseen = time;
			if(ready && time - last_seen == l){
				flushes.push_back(time);
				ready = false;
			}
		}else{
			last_seen = time;
			if(time - last_unseen == k){
				ready = true;
			}
		}
	}
	if(!flushes.empty()){
		for(int flush : flushes){
			cout << flush << '\n';
		}
	}else{
		cout << "NIKAD\n";
	}
	return 0;
}
