Recursive-descent parser in Python for:

1. Arithmetic Expression
2. Multi-digit Decimal Number

Other Possible Test Cases for 1:

|  Valid |  Invalid |
|---|---|
| 1+1$   | 5+2$  |
| 1+2$   |  1+1-(1+1$ |
| 1-2$,    | (1+1-(1+1)$  |
|  1+1-1+1$ | (1+1-(1+1)))$  |
|  1+1-(1+1)$ | 12312a$  |
| (1+1)-(1+1)$  | 123a121$  |
|  (1+1-(1+1))$ |  a23121$ |
| 1+(2*3)$  | 10+10$  |
| ((2*3))+1$  |  (1+(2*3)$ |
| 1*((2*3))+1$  | 1+(2*3)1$  |
| 1/((2*3))+1$ | 1+(2*3)11$  |
|   | 1+(2*3)+11$  |
|   | 1(2*3)$  |
|   |  1(2*3)+1$ |  

Other Possible Test Cases for 2:

| Valid  | Invalid  |
|---|:-:|
|  111.1$ |  111.1.1$ |
|  1111.111$ |  1.$ |
|  11231.111$ | a12312$  |
|   |  a1231.1$ |
|   | +31231.a1231$  |
|   |  1111a111.111$ |
|   | 111d1112.1121.112a$  |
|   | sada.1231$  |
|   |  asdas123.12$ |
|   |  fff.1$ |
|   | @.11$  |
|   |  1211.$ |
