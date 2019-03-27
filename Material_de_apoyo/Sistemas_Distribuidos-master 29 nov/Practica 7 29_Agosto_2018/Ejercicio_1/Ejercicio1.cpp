
#include <string>
#include <iostream>

using namespace std; 

int main(){

int n =0;
string line;
cout<<"Valor para n: ";
cin >> n;
cout<<"Valor de n: "<<n<<" :)"<<endl;
cin.ignore(10,'\n');


cout<<"Valor para line: ";
getline(cin, line);
cout<<"Valor de line: "<<line<<" :)"<<endl;

	return 0;
}