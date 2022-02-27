import re

def isPalindrome(inputString):
    # counting space input as palindrome
    if(inputString == " "):
        return True
    else:
        # remove any whitespaces in string
        inputString = re.sub(r'\s+', '', inputString)
        for i in range(0, int(len(inputString)/2)):
            if inputString[i] != inputString[len(inputString)-i-1]:
                return False
        return True

def main():
    inputString = input("Please input a string: ")
    checker = all([x.isalpha() or x == ' ' for x in inputString])
    if(checker):
        result = isPalindrome(inputString)
        if (result):
            print("VALID Palindrome in Grammar")
        else:
            print("INVALID Palindrome in Grammar")
    else:
        print("INVALID Palindrome in Grammar")

if __name__ == "__main__":
  main()
