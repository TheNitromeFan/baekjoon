#include <iostream>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	set<string> solved;
	map<string, int> wrong;
	for(int i = 0; i < n; ++i){
		string code, name, result, memory, time, language, length;
		cin >> code >> name >> result >> memory >> time >> language >> length;
		if(name == "megalusion" || solved.find(name) != solved.end()){
			continue;
		}
		if(result[0] == '4'){
			solved.insert(name);
			if(wrong.find(name) == wrong.end()){
				wrong[name] = 0;
			}
		}else{
			if(wrong.find(name) == wrong.end()){
				wrong[name] = 1;
			}else{
				wrong[name] += 1;
			}
		}
	}
	int numerator = solved.size();
	int denominator = numerator;
	for(string s : solved){
		denominator += wrong[s];
	}
	if(denominator == 0){
		cout << 0;
	}else{
		cout << setprecision(20) << numerator * 100.0 / denominator;
	}
	return 0;
}
