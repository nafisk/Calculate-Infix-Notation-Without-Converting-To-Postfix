//This program uses the stl library to deal with stack
//It cover all the requirements asked for in the promt 
//and has been tested thoroughly for many different cases
//Program By Nafis Khan
//Calculating Expressions directly using infix notaions

#include <iostream>
#include <stack>
using namespace std;

//calculates values between ()
void calcParent ( stack<int> &intStack, stack<char> &charStack );

//calculates the main arithmatic functions
int arithmaticCalc ( int x, int y, char z){
  int result;

  switch (z) {
    case '+':
    result = x + y;
    break;
    case '-':
    result = x - y;
    break;
    case '*':
    result = x * y;
    break;
    case '/':
    result = x / y;
    break;
    default:
    cout << "\nError. Use Correct Operator\n";
  }
  return result;
}

//Main Calculating function
int infixCalculator ( string infix ){

  //takes in the numeric values
  stack <int> intStack; 
  //takes in the operator values
  stack <char> charStack;

  //For loop for inserting the charecters    //Converts to int: infix[i] - '0'

	string numString = "";
  for (int i = 0; i < infix.length(); i++ ) {
		
    //removing the spaces
    if ( infix[i] == ' ' ) {
    }
    //putting numbers to the intStack
    else if ( isdigit(infix[i]) ){ 
      numString += infix[i];                                     
      
      //accounts for numbers bigger than a single digit, eg. 10, 100, 1000
      if ( i+1 == infix.length() || !isdigit(infix[i+1]) ) {
		    
        int num = stoi(numString);
				numString = "";

        //if there is a minus in the stack, it is used to turn the current number into a negative number
        //so that we do not have to deal with negative numbers later
        if (!charStack.empty() && charStack.top() == '-'){
          intStack.push(num * -1);
          charStack.pop(); 
          if (intStack.size() == 1 && intStack.top() < 0){}
          else {
            charStack.push('+');  //pushing a + to have something in place of the - in the charStack
          }
        }
        else {
          intStack.push(num);
        }

        //For multiplying/Dividing and inserting into stack immediately
        //Mult and Div is done immediately and the result is pushed onto the stack to keep it simple
        if ( charStack.empty() ) { //doing nothing
        }
        else {
          if ( charStack.top() == '*' || charStack.top() == '/'){
            int second = intStack.top(); intStack.pop(); int first = intStack.top(); intStack.pop();
            int result;
            result= arithmaticCalc( first, second, charStack.top());
            charStack.pop();
            intStack.push(result);
          }
          
        }

     }
    }
    //Inserting Operator Inside Stack
    else {
      charStack.push( infix[i] ); 

      //Processes -- and -+
      if ( charStack.top() == '-'){
        charStack.pop();
        
        if(!charStack.empty() && charStack.top() == '-'){
          charStack.pop();
          charStack.push('+');
        } 
        else if (!charStack.empty() && charStack.top() == '+') {
          charStack.pop();
          charStack.push('-');
        }
        else charStack.push('-');
      }

      //Processes ++ and +-
      if ( charStack.top() == '+'){
        charStack.pop();
        
        if(!charStack.empty() && charStack.top() == '-'){
          charStack.pop();
          charStack.push('-');
        } 
        else if (!charStack.empty() && charStack.top() == '+') {
          charStack.pop();
          charStack.push('+');
        }
        else charStack.push('+');
      }

      //Processes the parenthesis using its own function
      if( charStack.top() == ')' ) {
        calcParent( intStack, charStack );
      }

    }
  }
    
    //Calculating result using data from stack
    while ( intStack.size() != 1){
      int second = intStack.top(); intStack.pop();
      int first = intStack.top(); intStack.pop();
      intStack.push(arithmaticCalc(first, second, charStack.top() ) );
      charStack.pop();
    }


		return intStack.top();
}

void calcParent ( stack<int> &intStack, stack<char> &charStack ){
  charStack.pop(); //getting rid of ')'
    
    //The Multiplication and division is already done while inserting and the minuses are dealt with
    //before hand so the only operation that needs to be some is addition
    if(charStack.top() == '+'){
      int second = intStack.top(); intStack.pop(); int first = intStack.top(); intStack.pop();
      intStack.push(arithmaticCalc(first, second, charStack.top() ) );
      charStack.pop();
      }
  
  charStack.pop(); //getting rid of '('

}



int main() {

  string infix;
  int result;

  cout << "\t\t\t~Stack Project~" << endl;
  cout << "\t\t\t---------------" << endl;
  cout << "\t\t\t\tBy Nafis Khan\n";
  cout << "\t\t\t\t---------------\n\n\n";

  cout << "Please Enter the Infix Expression(No equals needed): "; 
  getline(cin, infix); cout << endl; //taking inputs as an entire line


  result = infixCalculator(infix);
  
  cout << "The result of the expression is: " << result;

	return 0;
}