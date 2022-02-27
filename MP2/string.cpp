#include <iostream>

using namespace std;

int main(){
  string inputString, temp;
  bool checkGrammar = true;
  cout<<"Please input a string: ";
  getline(cin, inputString);

  for(char c: inputString){
    if(c != ' '){
      temp += c;
    }
  }

  int counter = 0;
  for(char c: temp){
    if(c == '('){
      counter++;
    }else if(c == ')'){
      counter--;
    }
  }

  if(counter != 0){
    cout<<inputString<<" is not in the grammar";
    return 0;
  }

  for(int i = 0; i < temp.size() - 1; i++){
    char current = temp[i];
    char next = temp[i+1];
    if(current == 'x' || current == 'y' || current == 'z'){
      if(next == '+' || next == '-' || next == ')'){
        continue;
      }else{
        checkGrammar = false;
        break;
      }
    }else if(current == '~'){
      if(next == 'x' || next == 'y' || next == 'z'){
        continue;
      }else{
        checkGrammar = false;
        break;
      }
    }else if(current == '('){
      if(next == 'x' || next == 'y' || next == 'z' || next == '~'){
        continue;
      }else{
        checkGrammar = false;
        break;
      }
    }else if(current == '+' || current == '-'){
      if(next == 'x' || next == 'y' || next == 'z' || next == '(' || next == '~'){
        continue;
      }else{
        checkGrammar = false;
        break;
      }
    }
  }

  if(checkGrammar){
    cout<<"Valid string in the grammar";
  }else{
    cout<<"Invalid string in the grammar";
  }

  return 0;
}
