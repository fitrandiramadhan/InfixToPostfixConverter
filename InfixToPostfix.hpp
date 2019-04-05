//file    : InfixToPostfix.hpp
//author  : steaKK

#ifndef INFIXTOPOSTFIX_HPP
#define INFIXTOPOSTFIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class InfixToPostfix {
public:
  static vector<string> convertInPost_iterative(vector<string>);
  static vector<string> split(string);
  static bool is_operand(string);
  static bool is_left_parenthesis(string);
  static bool is_right_parenthesis(string);
  static bool is_lower_precedence(string,string);
  static void print_vector(vector<string>);
};

#endif

