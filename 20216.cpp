#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string line;
	while(true){
		getline(cin, line);
		if(line[line.length() - 1] == '?'){
			cout << "Quack!" << endl;
		}else if(line[line.length() - 1] == '.'){
			cout << "*Nod*" << endl;
		}else{
			cout << endl;
			break;
		}
	}
	return 0;
}
