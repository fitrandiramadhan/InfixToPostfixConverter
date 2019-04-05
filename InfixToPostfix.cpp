//file    : InfixToPostfix.cpp
//author  : steaKK

#include "InfixToPostfix.hpp"

//checking if its a variable or not
bool InfixToPostfix::is_operand(string _x) {
  if(_x=="+" || _x=="-" || _x=="*" || _x=="/" || _x=="(" || _x==")") return false;
  else return true;
}

//checking if its a left parenthesis or not
bool InfixToPostfix::is_left_parenthesis(string _x) {
  if(_x=="(") return true;
  else return false;
}

//checking if its a right parenthesis or not
bool InfixToPostfix::is_right_parenthesis(string _x) {
  if(_x==")") return true;
  else return false;
}

//checking if its a lower power operator or not
bool InfixToPostfix::is_lower_precedence(string _x, string _y) {
  if(_x=="*" || _x=="/" ) return false;
  else if(_x=="(") return true;
  else {
    if(_y=="+" || _y=="-" ) return false;
    else return true;
  }
}

vector<string> InfixToPostfix::convertInPost_iterative(vector<string> _x) {
  //initializing temporary variable
  vector<string> opstack;
  vector<string> statement = _x;
  vector<string> result;

  //iterator to count the state
  int n = 0;

  //iterating through the expression vector

  while(statement.size()>0) {
    n++;
    cout << endl << "STEP - " << n << endl;
    cout << "expression vector = "; print_vector(statement);
    cout << "operator stack = "; print_vector(opstack);
    cout << "result vector = "; print_vector(result);

    //if its a variable then moving it (the head of expression) to the result tail
    if(is_operand(statement.front())) {
      // cout << "aloha 1" << endl;
      result.push_back(statement.front());
      statement.erase(statement.begin());
    }
    //if its a left parenthesis then moving it (the head of expression) to the top of operator stack
    else if(is_left_parenthesis(statement.front())) {
      // cout << "aloha 2" << endl;
      opstack.push_back(statement.front());
      statement.erase(statement.begin());
    }
    //if its a right parenthesis then flushing the operator stack to the result tail (top to bottom)
    else if(is_right_parenthesis(statement.front())) {
      // cout << "aloha 3" << endl;
      //the right parenthesis itself was not added to the operator stack
      statement.erase(statement.begin());
      while(!is_left_parenthesis(opstack.back())) {
        result.push_back(opstack.back());
        opstack.pop_back();
      }
      //removing the first left parenthesis encountered on the stack (top to bottom)
      opstack.pop_back();
      // statement.erase(statement.begin());
    }
    //if its an operator then moving it (the head of expression) to the top of operator stack
    else {
      // cout << "aloha 4" << endl;
      //if the operator stack is empty then just add it to the top
      if(opstack.empty()) {
        // cout << "aloha 41" << endl;
        opstack.push_back(statement.front());
        statement.erase(statement.begin());
      }
      //if the operator stack is not empty then check first is it the operator that want to be added is stronger or equal with the operator on the top
      else {
        // cout << "aloha 42" << endl;
        // cout << !is_lower_precedence(opstack.back(),statement.front()) << " , " << !opstack.empty() << endl;
        //if the top is more powerful or equal then flush the top first until you find a less powerful operator or a "("
        //if its empty after some flushing then add the operator to the top
        while(!is_lower_precedence(opstack.back(),statement.front()) && !opstack.empty()) {
          // cout << "aloha 421" << endl;
          result.push_back(opstack.back());
          opstack.pop_back();
        }
        //this is just the addition part of the previous explanation
        opstack.push_back(statement.front());
        statement.erase(statement.begin());
      }
    }
  }

  //if the expression is already empty then make sure every operand got flushed in order (top to bottom)
  while(opstack.size()>0) {
    n++;
    cout << endl << "STEP - " << n << " FLUSHING REMAINING OPERATOR STACK" << endl;
    cout << "expression vector = "; print_vector(statement);
    cout << "operator stack = "; print_vector(opstack);
    cout << "result vector = "; print_vector(result);
    result.push_back(opstack.back());
    opstack.pop_back();
  }

  n++;
  cout << endl << "STEP - " << n << endl;
  cout << "expression vector = "; print_vector(statement);
  cout << "operator stack = "; print_vector(opstack);
  cout << "result vector = "; print_vector(result);

  return result;
}

//just some function to split the expression string into array of string
vector<string> InfixToPostfix::split(string _x) {
  string s = _x;
  string delimiter = " ";
  vector<string> result;

  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      // cout << token << endl;
      result.push_back(token);
      s.erase(0, pos + delimiter.length());
  }
  return result;
}

//printing utility for testing
void InfixToPostfix::print_vector(vector<string> _x) {
  for(int i=0;i<_x.size();i++) {
    cout << "[" << _x[i] << "]";
  }
  cout << endl;
}