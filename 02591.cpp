#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string number;
	cin >> number;
	int len = number.length();
	int *arr = (int *)calloc((len + 1), sizeof(int));
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i <= len; ++i){
		if(number[i-1] != '0'){
			arr[i] = arr[i-1];
		}
		if(number[i-2] == '1' || number[i-2] == '2' || (number[i-2] == '3' && number[i-1] <= '4')){
			arr[i] += arr[i-2];
		}
	}
	cout << arr[len] << endl;
	free(arr);
	return 0;
}
