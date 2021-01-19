/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calc;
  float result;
  string input;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";

    getline(cin,input);
    if(isNumber(input))
    {
        //push onto stack
        calc.push(stof(input));
    }
    else if(input == "=")
    {
        break;
    }
    else
        calc.compute(input);

  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
  if(calc.isEmpty())
  {
      cout << "No operands: Nothing to evaluate" << endl;
      return 0;
  }

  result = calc.peek()->number;
  calc.pop();
  if(calc.isEmpty())
  {
      cout << result << endl;
  }
  else
  {
      cout << "Invalid expression" << endl;
      return 0;
  }



  return 0;
}
