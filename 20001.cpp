#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	getline(cin, line);
	int probs = 0;
	while(true){
		getline(cin, line);
		if(line == "������ ����� ��"){
			break;
		}else if(line == "����"){
			++probs;
		}else if(probs > 0){
			--probs;
		}else{
			probs += 2;
		}
	}
	if(probs == 0){
		cout << "�������� �����";
	}else{
		cout << "����";
	}
	return 0;
}
