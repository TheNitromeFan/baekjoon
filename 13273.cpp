#include <iostream>
#include <string>

using namespace std;

string rom_to_arab(string rom){
	unsigned idx = 0;
	int answer = 0;
	if(idx + 3 <= rom.length() && rom[idx] == 'M' && rom[idx + 1] == 'M' && rom[idx + 2] == 'M'){
		answer += 3000;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'M' && rom[idx + 1] == 'M'){
		answer += 2000;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'M'){
		answer += 1000;
		idx += 1;
	}
	if(idx + 2 <= rom.length() && rom[idx] == 'C' && rom[idx + 1] == 'M'){
		answer += 900;
		idx += 2;
	}else if(idx + 4 <= rom.length() && rom[idx] == 'D' && rom[idx + 1] == 'C' && rom[idx + 2] == 'C' && rom[idx + 3] == 'C'){
		answer += 800;
		idx += 4;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'D' && rom[idx + 1] == 'C' && rom[idx + 2] == 'C'){
		answer += 700;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'D' && rom[idx + 1] == 'C'){
		answer += 600;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'D'){
		answer += 500;
		idx += 1;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'C' && rom[idx + 1] == 'D'){
		answer += 400;
		idx += 2;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'C' && rom[idx + 1] == 'C' && rom[idx + 2] == 'C'){
		answer += 300;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'C' && rom[idx + 1] == 'C'){
		answer += 200;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'C'){
		answer += 100;
		idx += 1;
	}
	if(idx + 2 <= rom.length() && rom[idx] == 'X' && rom[idx + 1] == 'C'){
		answer += 90;
		idx += 2;
	}else if(idx + 4 <= rom.length() && rom[idx] == 'L' && rom[idx + 1] == 'X' && rom[idx + 2] == 'X' && rom[idx + 3] == 'X'){
		answer += 80;
		idx += 4;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'L' && rom[idx + 1] == 'X' && rom[idx + 2] == 'X'){
		answer += 70;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'L' && rom[idx + 1] == 'X'){
		answer += 60;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'L'){
		answer += 50;
		idx += 1;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'X' && rom[idx + 1] == 'L'){
		answer += 40;
		idx += 2;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'X' && rom[idx + 1] == 'X' && rom[idx + 2] == 'X'){
		answer += 30;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'X' && rom[idx + 1] == 'X'){
		answer += 20;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'X'){
		answer += 10;
		idx += 1;
	}
	if(idx + 2 <= rom.length() && rom[idx] == 'I' && rom[idx + 1] == 'X'){
		answer += 9;
		idx += 2;
	}else if(idx + 4 <= rom.length() && rom[idx] == 'V' && rom[idx + 1] == 'I' && rom[idx + 2] == 'I' && rom[idx + 3] == 'I'){
		answer += 8;
		idx += 4;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'V' && rom[idx + 1] == 'I' && rom[idx + 2] == 'I'){
		answer += 7;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'V' && rom[idx + 1] == 'I'){
		answer += 6;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'V'){
		answer += 5;
		idx += 1;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'I' && rom[idx + 1] == 'V'){
		answer += 4;
		idx += 2;
	}else if(idx + 3 <= rom.length() && rom[idx] == 'I' && rom[idx + 1] == 'I' && rom[idx + 2] == 'I'){
		answer += 3;
		idx += 3;
	}else if(idx + 2 <= rom.length() && rom[idx] == 'I' && rom[idx + 1] == 'I'){
		answer += 2;
		idx += 2;
	}else if(idx + 1 <= rom.length() && rom[idx] == 'I'){
		answer += 1;
		idx += 1;
	}
	return to_string(answer);
}

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		try{
			cout << arab_to_rom(s);
		}catch(...){
			cout << rom_to_arab(s);
		}
		cout << "\n";
	}
	return 0;
}
