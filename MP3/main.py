# Fayne Roxenne A. Bagaipo CMSC 124 A

# 1. Grammar rules for an arithmetic expression:
# <expr> ::= <expr>+<term> | <expr>-<term> | <term>
# <term> ::= <term>*<factor> | <term>/<factor> | <factor>
# <factor> ::= (<expr>) |<digit>
# <digit> ::= 0|1|2|3

# Eliminating Left Recursion:
# <expr> ::= <term><expr'>
# <expr'> ::= +<term><expr'> | -<term><expr'> | ε
# <term> ::= <factor><term'>
# <term'> ::= *<factor><term'> | /<factor><term'> | ε
# <factor> ::= (<expr>) | <digit>
# <digit> ::= 0|1|2|3

class Parser_Arithmetic:
  def __init__(self, inputString: str):
    self.inputString = inputString
    self.tokenList = ["<expr>"]
  
  def replaceLeft(self, parts: [str]):
    self.tokenList = [token for token in self.tokenList if token != ""]
    left = 0
    for i, token in enumerate(self.tokenList):
      if token[0] == "<" and token[-1] == ">":
        left = 1
        break

    self.tokenList = (
      self.tokenList[:left]
      + parts
      + self.tokenList[left + 1 :]
    )

  def check(self) -> str:
    return self.inputString[0]

  def line(self):
    self.inputString = self.inputString[1:]

  def lineCheck(self, inputChar: str) -> bool:
    if self.check() == inputChar:
      self.line()
      return True
    return False

  def parse(self) -> bool:
    #  Check if string ends with '$' otherwise invalid
    if self.inputString[-1] != "$":
      return False
    parseResult = self.expr()
    self.line()
    if parseResult and self.inputString == "":
      return True
    return False

  def expr(self) -> bool:
    self.replaceLeft(["<term>", "<expr'>"])
    if self.term() and self.parseExpr():
      return True
    return False
  
  def parseExpr(self) -> bool:
    if self.check() in "+-":
      self.replaceLeft([f"{self.check()}", "<term>", "<expr'>"])
      self.line()
      if self.term() and self.parseExpr():
        return True
      return False
    else:
        self.replaceLeft([""])
        return True

  def term(self) -> bool:
    self.replaceLeft(["<factor>", "<term'>"])
    if  self.parseFactor() and self.parseTerm():
      return True
    return False

  def parseTerm(self) -> bool:
    if self.check() in "*/":
      self.replaceLeft([f"{self.check()}", "<factor>", "<term'>"])
      self.line()
      if self.parseFactor() and self.parseTerm():
        return True
      return False
    else:
      self.replaceLeft([""])
      return True

  def parseFactor(self) -> bool:
    if self.check() == "(":
      self.replaceLeft(["(", "<space>", "<space>"])
      if not self.lineCheck("("):
        return False
        
      self.replaceLeft(["<expr>"])
      if not self.expr():
        return False

      if self.check() == ")":
        self.replaceLeft([")"])
      if not self.lineCheck(")"):
        return False

      return True
    else:
      self.replaceLeft(["<digit>"])
      return self.numDigit()

  def numDigit(self) -> bool:
    if self.check() in "0123":
      self.replaceLeft([self.check()])
      self.line()
      return True
    else:
      return False

# 2. Grammar rules for a multi-digit decimal number:
# <expr> ::= +<num> | -<num> | <num>
# <num> ::= <num><digits> | <digits>
# <digits> ::= <digit> | <digit>.<digit>
# <digit> ::= 0|1|2|3|4|5|6|7|8|9

# Eliminating Left Recursion:
# <expr> ::= +<num> | -<num> | <num>
# <num> ::= <digits> | <digits>.<digits>
# <digits> ::= <digit><digits'>
# <digits'> ::= <digit><digits'> | ε
# <digit> ::= 0|1|2|3|4|5|6|7|8|9

class Parser_MultiDigit:
  def __init__(self, inputString: str):
    self.inputString = inputString
    self.tokenList = ["<expr>"]
  
  def replaceLeft(self, parts: [str]):
    self.tokenList = [token for token in self.tokenList if token != ""]
    left = 0
    for i, token in enumerate(self.tokenList):
      if token[0] == "<" and token[-1] == ">":
        left = 1
        break

    self.tokenList = (
      self.tokenList[:left]
      + parts
      + self.tokenList[left + 1 :]
    )

  def check(self) -> str:
    return self.inputString[0]

  def line(self):
    self.inputString = self.inputString[1:]

  def lineCheck(self, inputChar: str) -> bool:
    if self.check() == inputChar:
      self.line()
      return True
    return False

  def parse(self) -> bool:
    #  Check if string ends with '$' otherwise invalid
    if self.inputString[-1] != "$":
      return False
    parseResult = self.expr()
    self.line() 
    if parseResult and self.inputString == "":
      return True
    return False

  def expr(self) -> bool:
    if self.check() in "+-":
      self.replaceLeft([self.check(), "<num>"])
      self.line()
    else:
      self.replaceLeft(["<num>"])
    return self.parseNum()
  
  def parseNum(self) -> bool:
    self.replaceLeft(["<digits>", "<space>"])
    if not self.digits():
      return False
    if self.check() == ".":
      self.replaceLeft([".", "<digits>"])
      self.line()
      return self.digits()
    else:
        self.replaceLeft([""])
        return True

  def digits(self) -> bool:
    self.replaceLeft(["<digit>", "<digits'>"])
    return self.numDigit() and self.parseDigits()

  def parseDigits(self) -> bool:
    if self.check() in "*0123456789":
      self.replaceLeft(["<digit>", "<digits'>"])
      if self.numDigit() and self.parseDigits():
        return True
      return False
    else:
      self.replaceLeft([""])
      return True

  def numDigit(self) -> bool:
    if self.check() in "0123456789":
      self.replaceLeft([self.check()])
      self.line()
      return True
    return False

def main():
  print("CMSC 124 - Machine Problem 3")
  print("1. Arithmetic Expression \n2. Multi-digit Decimal Number")
  inputChoice = int(input("Please choose from the two: "))
  # For 1st Input Choice (Arithmetic Expression)
  if inputChoice == 1:
    inputString = input("Please input a string: ")
    p = Parser_Arithmetic(inputString)
    if p.parse():
      print("VALID")
    else:
      print("INVALID")
  # For 2nd Input Choice (Multi-digit Decimal Number)
  elif inputChoice == 2:
    inputString = input("Please input a string: ")
    p = Parser_MultiDigit(inputString)
    if p.parse():
      print("VALID")
    else:
      print("INVALID")
  else:
    print("Invalid Choice...Exiting")

if __name__ == "__main__":
  main()
