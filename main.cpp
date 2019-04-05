//file    : main.cpp
//author  : steaKK

#include "InfixToPostfix.hpp"

int main() {

  cout << endl;
  cout << "------------I------------" << endl;
  cout << "----- INITIAL STATE -----" << endl;
  cout << "-------------------------" << endl;
  string s1 = "a * b + c * d #";
  cout << s1 << endl;

  cout << endl;
  cout << "------------I------------" << endl;
  cout << "------ SPLITTING --------" << endl;
  cout << "-------------------------" << endl;
  vector<string> v1 = InfixToPostfix::split(s1);
  InfixToPostfix::print_vector(v1);

  cout << endl;
  cout << "------------I------------" << endl;
  cout << "------- PROCCESS --------" << endl;
  cout << "-------------------------" << endl;
  vector<string> r1 = InfixToPostfix::convertInPost_iterative(v1);

  cout << endl;
  cout << "------------I------------" << endl;
  cout << "------ FINAL STATE ------" << endl;
  cout << "-------------------------" << endl;
  InfixToPostfix::print_vector(r1);

  cout << endl;
  cout << "-----------II------------" << endl;
  cout << "----- INITIAL STATE -----" << endl;
  cout << "-------------------------" << endl;
  string s2 = "a + b * ( c + d ) * e #";
  cout << s2 << endl;

  cout << endl;
  cout << "-----------II------------" << endl;
  cout << "------ SPLITTING --------" << endl;
  cout << "-------------------------" << endl;
  vector<string> v2 = InfixToPostfix::split(s2);
  InfixToPostfix::print_vector(v2);

  cout << endl;
  cout << "-----------II------------" << endl;
  cout << "------- PROCCESS --------" << endl;
  cout << "-------------------------" << endl;
  vector<string> r2 = InfixToPostfix::convertInPost_iterative(v2);

  cout << endl;
  cout << "-----------II------------" << endl;
  cout << "------ FINAL STATE ------" << endl;
  cout << "-------------------------" << endl;
  InfixToPostfix::print_vector(r2);

  // cout << "+++ " << InfixToPostfix::is_lower_precedence("+","*") << " +++" << endl;
  // cout << "+++ " << !InfixToPostfix::is_lower_precedence("+","*") << " +++" << endl;
  // for(int i=0;i<v1.size();i++) {
  //   cout << "[" << v1[i] << "]" << endl;
  //   cout << InfixToPostfix::is_operand(v1[i]) << endl;
  //   cout << InfixToPostfix::is_left_parenthesis(v1[i]) << endl;
  //   cout << InfixToPostfix::is_right_parenthesis(v1[i]) << endl;
  //   cout << InfixToPostfix::is_lower_precedence(v1[i],"*") << "," << InfixToPostfix::is_lower_precedence(v1[i],"+") << "," << InfixToPostfix::is_lower_precedence(v1[i],"(") << endl;
  // }

  cout << endl;
  return 0;
}