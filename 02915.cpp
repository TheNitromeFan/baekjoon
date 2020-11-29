#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arab_to_rom(string arab){
	int n = stoi(arab);
	string answer;
	switch(n / 1000){
        case 1:
			answer += "M";
			break;
       	case 2:
			answer += "MM";
			break;
		case 3:
			answer += "MMM";
			break;
    }
    n %= 1000;
    switch(n / 100){
    	case 1:
    		answer += "C";
    		break;
		case 2:
    		answer += "CC";
    		break;
		case 3:
    		answer += "CCC";
    		break;
		case 4:
    		answer += "CD";
    		break;
		case 5:
    		answer += "D";
    		break;
		case 6:
    		answer += "DC";
    		break;
		case 7:
    		answer += "DCC";
    		break;
		case 8:
    		answer += "DCCC";
    		break;
		case 9:
    		answer += "CM";
    		break;
	}
	n %= 100;
	switch(n / 10){
    	case 1:
    		answer += "X";
    		break;
		case 2:
    		answer += "XX";
    		break;
		case 3:
    		answer += "XXX";
    		break;
		case 4:
    		answer += "XL";
    		break;
		case 5:
    		answer += "L";
    		break;
		case 6:
    		answer += "LX";
    		break;
		case 7:
    		answer += "LXX";
    		break;
		case 8:
    		answer += "LXXX";
    		break;
		case 9:
    		answer += "XC";
    		break;
	}
	n %= 10;
	switch(n){
    	case 1:
    		answer += "I";
    		break;
		case 2:
    		answer += "II";
    		break;
		case 3:
    		answer += "III";
    		break;
		case 4:
    		answer += "IV";
    		break;
		case 5:
    		answer += "V";
    		break;
		case 6:
    		answer += "VI";
    		break;
		case 7:
    		answer += "VII";
    		break;
		case 8:
    		answer += "VIII";
    		break;
		case 9:
    		answer += "IX";
    		break;
	}
	return answer;
}

int main(){
	string b;
	cin >> b;
	sort(b.begin(), b.end());
	for(int ans = 1; ans <= 99; ++ans){
		string s = arab_to_rom(to_string(ans));
		string t = s;
		sort(t.begin(), t.end());
		if(b == t){
			cout << s;
			break;
		}
	}
	return 0;
}
