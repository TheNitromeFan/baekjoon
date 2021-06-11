#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	for(int j = 1; j <= 3; ++j){
		int vacc = 0, vacc_infected = 0, control = 0, control_infected = 0;
		for(int i = 0; i < n; ++i){
			if(v[i][0] == 'Y'){
				++vacc;
				if(v[i][j] == 'Y'){
					++vacc_infected;
				}
			}else{
				++control;
				if(v[i][j] == 'Y'){
					++control_infected;
				}
			}
		}
		if(control_infected * vacc <= vacc_infected * control){
			cout << "Not Effective\n";
			continue;
		}
		double efficacy = (control_infected * vacc - vacc_infected * control) * 100.0 / (control_infected * vacc);
		cout << efficacy << '\n';
	}
	return 0;
}
