/*
   This is the main file of FreeLab
*/



#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace::std;

#define COMMAND_SIZE 10

/* defining token structure */
struct token{
    unsigned char value;
    char type; 
};



/***************
   defining Tokenizer class consisting list of tokens and related functions 
****************/ 

class Tokenizer{ 
    private:
	token rawTokenList[COMMAND_SIZE];	/* list of token structures */
	int currPos = 0;	/* variable for insertion */
	int size = 0;		/* variable keeping track of size */
    public:
	void insert_token(const token& T ){
	    if(currPos == 0){
		size = 0;
	    }
	    // cout << "Token inserted" << endl;
	    rawTokenList[currPos].value = T.value;
	    rawTokenList[currPos].type = T.type;
	    currPos++;
	    size++;
	}

	void print_list(void){
	    for(int i = 0; i < size; i++){
		cout << "value: " <<rawTokenList[i].value << " type: " << rawTokenList[i].type << endl;
	    }
	}

	void tokenize(string expr){
	    int index = 0;
	    token tok;
	    while(expr[index] != '\0'){
		if(isdigit(expr[index])){
		    tok.value = expr[index];
		    tok.type = 'i';
		    insert_token(tok);
		}
		else if(expr[index] == ' '){
		    index++;
		    continue;
		}
		else{
		    tok.value = expr[index];
		    tok.type = 'o';
			insert_token(tok);
		    }
		    index++;
		}
		currPos = 0;
	}
};

/***************
   end of Tokenizer class
****************/

/********
  Start of main function
********/

int main(){
    Tokenizer tokenizer;
    string line;
    while(1){
	cout<<">>";
	getline(cin,line);
    
	tokenizer.tokenize(line);
	
	
	// tokenizer.print_list();	
	}
    return 0;
}

/*********
  end of main function
**********/
