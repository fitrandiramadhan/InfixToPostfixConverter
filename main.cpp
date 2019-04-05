//file    : main.cpp
//author  : steaKK

#include "InfixToPostfix.hpp"

int main() {
  string s1 = "a * b + c * d #";
  string s2 = "a + b * ( c + d ) * e #";

  cout << s1 << endl;
  cout << s2 << endl;

  cout << "---------------" << endl;

  vector<string> v1 = InfixToPostfix::split(s1);
  vector<string> v2 = InfixToPostfix::split(s2);

  InfixToPostfix::print_vector(v1);
  InfixToPostfix::print_vector(v2);

  // cout << "+++ " << InfixToPostfix::is_lower_precedence("+","*") << " +++" << endl;
  // cout << "+++ " << !InfixToPostfix::is_lower_precedence("+","*") << " +++" << endl;


  cout << "---------------" << endl;

  // for(int i=0;i<v1.size();i++) {
  //   cout << "[" << v1[i] << "]" << endl;
  //   cout << InfixToPostfix::is_operand(v1[i]) << endl;
  //   cout << InfixToPostfix::is_left_parenthesis(v1[i]) << endl;
  //   cout << InfixToPostfix::is_right_parenthesis(v1[i]) << endl;
  //   cout << InfixToPostfix::is_lower_precedence(v1[i],"*") << "," << InfixToPostfix::is_lower_precedence(v1[i],"+") << "," << InfixToPostfix::is_lower_precedence(v1[i],"(") << endl;
  // }

  vector<string> r1 = InfixToPostfix::convertInPost_iterative(v1);
  vector<string> r2 = InfixToPostfix::convertInPost_iterative(v2);

  InfixToPostfix::print_vector(r1);
  InfixToPostfix::print_vector(r2);

  return 0;
}