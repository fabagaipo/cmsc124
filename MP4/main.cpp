#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}

bool isOperand(char x){
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

// Checks precedence of operator
int getPrecedence(char C) {
    if (C == '-' || C == '+') {
        return 1;
    }else if (C == '*' || C == '/') {
        return 2;
    }else if (C == '^') {
        return 3;
    }else {
        return 0;
    }
}

// Identify type of notation for expression
int identify(string check) {
	char last = check.back();
	char first = check[0];

	if (last == '+' || last == '-' || last == '/' || last == '*' || last == '^') {
		return 3; // if postfix
	}else if(first == '+' || first == '-' || first == '/' || first == '*' || first == '^') {
		return 2; // if prefix
	}else if(isalnum(first) || first == '(') {
		return 1; // if infix
	}else {
		return 0;
	}
}

// Remove whitespace from input
string removeWhitespace(string str) {
    stringstream ss;
    string temp;

    ss << str;
    str = "";
    while (!ss.eof()) {
        ss >> temp;
        str = str + temp;
    }
    return str;
}

// Infix to Postfix
string inToPost(string infix) {
   stack<char> stk;
   stk.push('#');    
   string postfix = ""; 
   string::iterator it;

   for(it = infix.begin(); it!=infix.end(); it++) {
      if(isalnum(char(*it)))
         postfix += *it; 
      else if(*it == '(') {
         stk.push('(');
      } else if(*it == '^') {
         stk.push('^');
      } else if(*it == ')') {
         while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top();
            stk.pop();
         }
         stk.pop();
      }else {
         if(getPrecedence(*it) > getPrecedence(stk.top()))
            stk.push(*it);
         else {
            while(stk.top() != '#' && getPrecedence(*it) <= getPrecedence(stk.top())) {
               postfix += stk.top();
               stk.pop();
            }
            stk.push(*it);
         }
      }
   }
   while(stk.top() != '#') {
      postfix += stk.top();
      stk.pop();
   }
   return postfix;
}

// Reverse Function for Infix to Prefix
string reverseInfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> stk;
    string output;
 
    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])){
            output += infix[i];
 
        }else if (infix[i] == '('){
            stk.push('(');
        }else if (infix[i] == ')') {
            while (stk.top() != '(') {
                output += stk.top();
                stk.pop();
            }
            stk.pop();
        }else {
            if (isOperator(stk.top())) {
                if(infix[i] == '^') {
                      while (getPrecedence(infix[i]) <= getPrecedence(stk.top())) {
                         output += stk.top();
                         stk.pop();
                       }
                     
                }else {
                    while (getPrecedence(infix[i]) < getPrecedence(stk.top())) {
                         output += stk.top();
                         stk.pop();
                       }
                     
                }
                stk.push(infix[i]);
            }
        }
    }
      while(!stk.empty()){
          output += stk.top();
        stk.pop();
    }
    return output;
}

// Infix to Prefix
string inToPre(string infix) {
   string prefix;
   reverse(infix.begin(), infix.end());
   string::iterator it;

   for(it = infix.begin(); it != infix.end(); it++) {
      if(*it == '(')
         *it = ')';
      else if(*it == ')')
         *it = '(';
   }

   prefix = reverseInfix(infix);                 
   reverse(prefix.begin(), prefix.end());    
   return prefix;
}

// Prefix to Infix
string preToInfix(string pre_exp) {
  stack<string> stk;
 
  int length = pre_exp.size();
 
  for (int i = length - 1; i >= 0; i--) {
 
    if (isOperator(pre_exp[i])) {
      string op1 = stk.top();   stk.pop();
      string op2 = stk.top();   stk.pop();
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";

      stk.push(temp);
    }else {
      stk.push(string(1, pre_exp[i]));
    }
  }
  return stk.top();
}

// Prefix to Postfix
string preToPost(string pre_exp) {
 
    stack<string> stk;
    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = op1 + op2 + pre_exp[i];
            stk.push(temp);
        }else {
            stk.push(string(1, pre_exp[i]));
        }
    }
    return stk.top();
}

// Postfix to Infix
string postToIn(string exp) {
    stack<string> stk;
 
    for (int i=0; exp[i]!='\0'; i++) {
        if (isOperand(exp[i])) {
           string op(1, exp[i]);
           stk.push(op);
        }else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }
    return stk.top();
}

// Postfix to Prefix
string postToPre(string post_exp) {
    stack<string> stk;
    int length = post_exp.size();

    for (int i = 0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            string temp = post_exp[i] + op2 + op1;
            stk.push(temp);
        }else {
            stk.push(string(1, post_exp[i]));
        }
    }
 
    string ans = "";
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

// For Expression Evaluation: 

// Infix Evaluator
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
}
 
float infixEval(string tokens){
    int i;
    stack <int> values;
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){

        if(tokens[i] == ' '){
            continue;
        }else if(tokens[i] == '(') {
            ops.push(tokens[i]);
        }else if(isdigit(tokens[i])) {
            int val = 0;

            while(i < tokens.length() && isdigit(tokens[i])){
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            values.push(val);
              i--;

        }else if(tokens[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty()){
               ops.pop();
            }
        }else {
            while(!ops.empty() && getPrecedence(ops.top())
                                >= getPrecedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
     
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

// Postfix Evaluator
float scanNum(char ch){
   int value;
   value = ch;
   return float(value-'0');
}
int isOperation(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;
      return -1;
   }

int isNumerical(char ch){
      if(ch >= '0' && ch <= '9'){
         return 1;
      }else{
          return -1;
      }
   }

float operation(int a, int b, char op){
      if(op == '+') {
         return b+a;
      }else if(op == '-') {
         return b-a;
      }else if(op == '*') {
         return b*a;
      }else if(op == '/') {
         return b/a;
      }else if(op == '^') {
         return pow(b,a);
      }else {
          return INT_MIN;
      }
}

float postfixEval(string postfix){
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      if(isOperation(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isNumerical(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

// Main Function:
int main() {
    string expr;
    int choice = 1;
    while(choice > 0 && choice < 4){
        cout << "Choose from the options:\n 1. Notation Conversion \n 2. Expression Evaluation \n 3. Exit" << endl;
        cout << "Input:" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            cout << "Input expression to be converted: " << endl;
            getline(cin, expr);
            expr = removeWhitespace(expr);
            if(identify(expr) == 1) {
	            cout << "Prefix: " << inToPre(expr) << endl;
                cout << "Postfix: " << inToPost(expr) << endl;
            }else if(identify(expr) == 2) {
                cout << "Infix: " << preToInfix(expr) << endl;
                cout << "Postfix: " << preToPost(expr) << endl;
            }else if(identify(expr) == 3) {
                cout << "Infix: " << postToIn(expr) << endl;
                cout << "Prefix: " << postToPre(expr) << endl;
            }else {
                cout << "Invalid" << endl;
            }

        }else if(choice == 2) {
            cout << "Input expression to be evaluated: " << endl;
            getline(cin, expr);
            expr = removeWhitespace(expr);
            if(identify(expr) == 1) {
                cout << "Evaluation: " << infixEval(expr) << endl;
            }else if(identify(expr) == 2) {
                expr = preToPost(expr);
                cout << "Evaluation: " << postfixEval(expr) << endl;
            }else if(identify(expr) == 3) {
                cout << "Evaluation: " << postfixEval(expr) << endl;
            }else {
                cout << "Invalid" << endl;
            }
        }else if(choice == 3) {
            cout << "Exiting..." << endl;
        }else {
            cout << "Invalid choice... Try again." << endl;
        }
    }
    return 0;
}
