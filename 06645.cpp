#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		string code;
		cin >> n >> code;
		if(n == 0 && code == "END"){
			break;
		}
		vector<tuple<string, string, double>> v(n);
		for(int i = 0; i < n; ++i){
			string name, action;
			double price;
			cin >> name >> action >> price;
			v[i] = make_tuple(name, action, price);
		}
		cout << code << '\n';
		for(int i = 0; i < n; ++i){
			string name = get<0>(v[i]), action = get<1>(v[i]);
			double price = get<2>(v[i]);
			vector<string> ans;
			for(int j = 0; j < n; ++j){
				string name1 = get<0>(v[j]), action1 = get<1>(v[j]);
				double price1 = get<2>(v[j]);
				if((action == "sell" && action1 == "buy" && price1 >= price)
				|| (action == "buy" && action1 == "sell" && price1 <= price)){
					ans.push_back(name1);
				}
			}
			cout << name << ": ";
			if(!ans.empty()){
				for(string name1 : ans){
					cout << name1 << ' ';
				}
			}else{
				cout << "NO-ONE";
			}
			cout << '\n';
		}
	}
	return 0;
}
