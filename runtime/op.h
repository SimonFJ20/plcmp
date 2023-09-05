#ifndef OP_C
#define OP_C

typedef enum {
    Op_Nop,
    Op_Call,
    Op_Return,
    Op_Push,
    Op_Pop,
    Op_LoadLocal,
    Op_StoreLocal,
    Op_Alloc,
    Op_Load,
    Op_Store,
    Op_Mov,
    Op_LoadI64,
    Op_LoadF64,
    Op_LoadString,
    Op_Jump,
    Op_JumpIf,
    Op_Not,
    Op_Or,
    Op_Xor,
    Op_And,
    Op_ShiftLeft,
    Op_ShiftRight,
    Op_Negate,
    Op_Add,
    Op_Subtract,
    Op_Multiply,
    Op_Divide,
    Op_Remainder,
} Op;

#endif

