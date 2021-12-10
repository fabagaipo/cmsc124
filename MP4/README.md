EXPRESSION CONVERTER AND EVALUATOR IN C++

1. Checks which notation the inputted expression is and converts it to their respective counterparts (infix -> prefix and postfix, prefix -> infix and postfix, postfix -> infix and prefix)
2. Evaluates expression depending on what their notation is (infix, prefix, and postfix)

Test cases for Option 1:

|  Infix |  Prefix | Postfix |
|---|---| --- |
| A+B*C+D    | ++A*BCD   | ABC*+D+ |
| (A+B)*(C+D)   |  *+AB+CD | AB+CD+* |
| A*B+C*D     | +*AB*CD  | AB*CD*+ |
|  A+B+C+D | +++ABCD   | AB+C+D+ |
|  (A+B)*C  | *+ABC  | AB+C* |
| A*B+C/D  | +*AB/CD   | AB*CD/+ |
|  A*(B+C)/D  |  /*A+BCD | ABC+*D/ |
| a*(b+c/d)  | *a+b/cd   | abcd/+* |
| a*(b+c)  |  *a+bc | abc+* |
| a/b+c/d  | +/ab/cd  | ab/cd/+ |
| ((a+b)*c)-d | -*+abcd  | ab+c*d- |
| (a+(((b*c)-((d/(e^f))*g))*h)) | +a*-*bc*/d^efgh | abc*def^/g*-h*+ |

Test cases for Option 2:

|  Expression |  Evaluation |
|---|---|
| 6 2 3 + - 3 8 2 / + * 2 ^ 3 +    | 52  |
| + 9 * 2 6   |  21 |
| - + 7 * 4 5 + 2 0     | 25  |
|  - + 8 / 6 3 2 | 8   |
|  ( 5 + 10 ) / ( 20 / 4 )  | 3 |
