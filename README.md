
# pl-cmp

Programming language comparison

## language

### Grammar

```ebnf
program ::= statement*

statement ::= fn | return | while | break | if | let | assign

fn ::= "fn" id "(" params ")" block

params ::= (id ("," id)*  ","?)?

return ::= "return" expr? ";"

while ::= "while" expr block

break ::= "break" ";"

if ::= "if" expr block ("else" block)?

let ::= "let" id "=" value ";"

assign ::= expr (("="|"+="|"-=") expr)? ";"

expr ::= or

or ::= and ("or" and)*

and ::= equal ("and" equal)*

equal ::= compare (("=="|"!=") compare)?

compare ::= bit_and (("<"|">"|"<="|">="|"in")  bit_and)?

bit_or ::= bit_xor ("|" bit_xor)?

bit_xor ::= bit_and ("^" bit_and)?

bit_and ::= bitshift ("&" bitshift)?

bitshift ::= term (("<<"|">>") term)?

term ::= factor (("+"|"-") factor)*

factor ::= unary (("*"|"/"|"%") unary)*

unary ::= ("-"|"!"|"&"|"*") unary | call_index_method_member

call_index_method_member ::= operand ("(" args ")" | "[" expr "]" | "." id ("(" args ")"))*

args ::= (expr ("," expr)* ","?)?

operand ::= id | int | hex | bin | float | bool | string | group | array | object

id ::= /[a-zA-Z_][a-zA-Z0-9_]*/

int ::= /0|[1-9][0-9]*/

hex ::= /0x[0-9a-fA-F]+/

bin ::= /0b[01]+/

float ::= /0|[1-9][0-9]*\.[0-9]+/

bool ::= "true" | "false"

string ::= /"([^\\"]|(\\(\\|"|'|n|r|t|0|x[0-9a-fA-F]+)))*"/

group ::= "(" expr ")"

array ::= "[" args "]"

object ::= "{" object_entries "}"

object_entries ::= (object_entry ("," object_entry)* ","?)?

object_entry ::= id ":" expr
```

### Bytecode

#### Instructions

Name
---
Nop
Call
Return
Push
Pop
Mov
LoadLocal
StoreLocal
Load
Store
LoadBool
LoadI64
LoadF64
LoadString
Push
Pop
Jump
JumpIf
Not
Or
Xor
And
ShiftLeft
ShiftRight
Negate
Add
Subtract
Multiply
Divide
Remainder

