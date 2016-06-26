

/***************
   defining Tokenizer class consisting list of tokens and related functions 
****************/ 

class Tokenizer{ 
    private:
	token tokenList[5];	/* list of token structures */
	int currPos = 0;	/* variable for insertion */
	int size = 0;		/* variable keeping track of size */
    public:
	void insert_token(const token& T ){
	    if(currPos == 0){
		size = 0;
	    }
	    // cout << "Token inserted" << endl;
	    tokenList[currPos].value = T.value;
	    tokenList[currPos].type = T.type;
	    currPos++;
	    size++;
	}
	void print_list(void){
	    for(int i = 0; i < size; i++){
		cout << "value: " <<tokenList[i].value << " type: " << tokenList[i].type << endl;
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
