// Name: Rushith Singamsetty
// ID: rs5yb
// Date: 2/26/2017
// Filename: TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//Constructor
TreeCalc::TreeCalc()
{
}

//Destructor- frees memory
TreeCalc::~TreeCalc()
{
  while(!mystack.empty())
  {
    cleanTree(mystack.top());
    mystack.pop();
  } 
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr)
{
  if(ptr->left != NULL)
  {
    cleanTree(ptr->left);
  }
  if(ptr->right != NULL)
  {
    cleanTree(ptr->right);
  }
  delete ptr;
}

void TreeCalc::readInput() {
  string response;
  cout << "Enter elements one by one in postfix notation" << endl
       << "Any non-numeric or non-operator character,"
       << " e.g. #, will terminate input" << endl;
  cout << "Enter first element: ";
  cin >> response;
  //while input is legal
  while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
	 || response[0]=='-' || response[0]=='+' ) {
    insert(response);
    cout << "Enter next element: ";
    cin >> response;
  }
}

void TreeCalc::insert(const string& val)
{
  TreeNode* a = new TreeNode(val);
  if(isdigit(val[0]) || isdigit(val[1]))
  {
    mystack.push(a);
  }
  else
  {
      if(!mystack.empty())
      {
	a->right=mystack.top();
        mystack.pop();
      }
      if(!mystack.empty())
      {
	a->left=mystack.top();
        mystack.pop();
      }
      mystack.push(a);
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const
{
  cout << ptr->value << " ";
  if(ptr->left != NULL)
    printPrefix(ptr->left);
  if(ptr->right != NULL)
    printPrefix(ptr->right);
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const
{
  if(ptr->left != NULL)
  {
    cout << "(";
    printInfix(ptr->left);
  }
  if((isdigit(ptr->value[0])) || (isdigit(ptr->value[1])))
    cout << ptr->value << "";
  else
    cout << " " << ptr->value << " ";
  if(ptr->right != NULL)
  {
    printInfix(ptr->right);
    cout <<")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const
{
  if(ptr->left != NULL)
    printPostfix(ptr->left);
  if(ptr->right != NULL)
    printPostfix(ptr->right);
  cout << ptr->value << " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
  if (mystack.size()!=0 && mystack.top()!=NULL) {
    cout << "Expression tree in postfix expression: ";
    printPostfix(mystack.top());
    cout << endl;
    cout << "Expression tree in infix expression: ";
    printInfix(mystack.top());
    cout << endl;
    cout << "Expression tree in prefix expression: ";
    printPrefix(mystack.top());
    cout << endl;
  } else
    cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
//private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const
{
  int a;
  int b;
  string val = ptr->value;
  if(ptr->left != NULL)
    a = calculate(ptr->left);
  if(ptr->right != NULL)
    b = calculate(ptr->right);
  if(isdigit(val[0]) || isdigit(val[1]))
    return atoi(val.c_str());
  else
  {
      if(val == "+")
      {
	  a = a + b;
	  return a;
      }
      if(val == "-")
      {
	  a = a - b;
	  return a;
      }
      if(val == "/")
      {
	  a = a / b;
	  return a;
      }
      if(val == "*")
      {
	  a = a * b;
	  return a;
      }
      else
      {
        return a+b;
      }
  }
}

//Calls calculate, sets the stack back to a blank stack
//public calculate() method. Hides private data from user
int TreeCalc::calculate()
{
  int i = 0;
  if(!mystack.empty())
    i = calculate(mystack.top());
  if(!mystack.empty())
  {
    cleanTree(mystack.top());
    mystack.pop();
  }
  return i;
}
