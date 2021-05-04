#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string winner, bidder;
	int max_bid, bid;
	cin >> winner >> max_bid;
	for(int i = 1; i < n; ++i){
		cin >> bidder >> bid;
		if(bid > max_bid){
			max_bid = bid;
			winner = bidder;
		}
	}
	cout << winner;
	return 0;
}
