#include <iostream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	map<string, tuple<int, int, int>> coffee;
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int c, p;
		cin >> c >> p;
		int delivery = 100 / p;
		for(int i = 0; i < c; ++i){
			string type;
			int small, medium, large;
			cin >> type >> small >> medium >> large;
			coffee[type] = make_tuple(small, medium, large);
		}
		for(int j = 0; j < p; ++j){
			string name, size, order;
			cin >> name >> size >> order;
			int price = delivery;
			if(size == "small"){
				price += get<0>(coffee[order]);
			}else if(size == "medium"){
				price += get<1>(coffee[order]);
			}else if(size == "large"){
				price += get<2>(coffee[order]);
			}
			if(price % 5 == 1){
				--price;
			}else if(price % 5 == 4){
				++price;
			}
			cout << name << " " << price << "\n";
		}
	}
	return 0;
}
