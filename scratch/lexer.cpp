#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace::std;

class Tokenizer{
    private:
	int curr_position=0;

};

int main(){
    while(1){
    cout<<">>";
    string line;
    getline(cin,line);
    
    /*tokenize line and display result
     call tokenizer->compute resut from tokens-> display result  
    */
   
    cout<<line[0]<<endl;
    if(isdigit(line[0])){
	cout<<"it is digit"<<endl;
    }
    }
    return 0;
}
