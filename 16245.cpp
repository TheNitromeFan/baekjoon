#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int k;
	cin >> n >> k;
	vector<long long> bus(k + 1);
	for(int i = 1; i <= k; ++i){
		long long x, y;
		cin >> x >> y;
		bus[i] = 3 * x + y;
	}
	vector<int> red, blue, black, yellow;
	long long row, col;
	unordered_set<long long> seats;
	row = 1;
	col = 1;
	seats.clear();
	for(int i = 1; i <= k; ++i){
		seats.insert(bus[i]);
		if(bus[i] == 3 * row + col){
			red.push_back(i);
			while(seats.find(3 * row + col) != seats.end()){
				if(col == 2){
					++row;
					col = 1;
				}else{
					col = 2;
				}
			}
		}
	}
	row = 1;
	col = 2;
	seats.clear();
	for(int i = 1; i <= k; ++i){
		seats.insert(bus[i]);
		if(bus[i] == 3 * row + col){
			blue.push_back(i);
			while(seats.find(3 * row + col) != seats.end()){
				if(col == 1){
					++row;
					col = 2;
				}else{
					col = 1;
				}
			}
		}
	}
	row = n;
	col = 1;
	seats.clear();
	for(int i = 1; i <= k; ++i){
		seats.insert(bus[i]);
		if(bus[i] == 3 * row + col){
			black.push_back(i);
			while(seats.find(3 * row + col) != seats.end()){
				if(col == 2){
					--row;
					col = 1;
				}else{
					col = 2;
				}
			}
		}
	}
	row = n;
	col = 2;
	seats.clear();
	for(int i = 1; i <= k; ++i){
		seats.insert(bus[i]);
		if(bus[i] == 3 * row + col){
			yellow.push_back(i);
			while(seats.find(3 * row + col) != seats.end()){
				if(col == 1){
					--row;
					col = 2;
				}else{
					col = 1;
				}
			}
		}
	}
	cout << red.size();
	for(int i : red){
		cout << ' ' << i;
	}
	cout << '\n';
	cout << blue.size();
	for(int i : blue){
		cout << ' ' << i;
	}
	cout << '\n';
	cout << black.size();
	for(int i : black){
		cout << ' ' << i;
	}
	cout << '\n';
	cout << yellow.size();
	for(int i : yellow){
		cout << ' ' << i;
	}
	cout << '\n';
	cout << k;
	for(int i = 1; i <= k; ++i){
		cout << ' ' << i;
	}
	cout << '\n';
	return 0;
}
