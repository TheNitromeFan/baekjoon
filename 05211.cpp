#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string comp;
	cin >> comp;
	int aminor = 0, cmajor = 0;
	if(comp[0] == 'A' || comp[0] == 'D' || comp[0] == 'E'){
		++aminor;
	}else if(comp[0] == 'C' || comp[0] == 'F' || comp[0] == 'G'){
		++cmajor;
	}
	for(unsigned i = 1; i < comp.length() - 1; ++i){
		if(comp[i] == '|' && (comp[i + 1] == 'A' || comp[i + 1] == 'D' || comp[i + 1] == 'E')){
			++aminor;
		}else if(comp[i] == '|' && (comp[i + 1] == 'C' || comp[i + 1] == 'F' || comp[i + 1] == 'G')){
			++cmajor;
		}
	}
	if(aminor == cmajor){
		if(comp[comp.length() - 1] == 'A' || comp[comp.length() - 1] == 'D' || comp[comp.length() - 1] == 'E'){
			++aminor;
		}else if(comp[comp.length() - 1] == 'C' || comp[comp.length() - 1] == 'F' || comp[comp.length() - 1] == 'G'){
			++cmajor;
		}
	}
	if(aminor > cmajor){
		cout << "A-minor";
	}else{
		cout << "C-major";
	}
	return 0;
}
