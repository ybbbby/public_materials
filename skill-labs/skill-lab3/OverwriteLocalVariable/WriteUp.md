# Buffer Overflow

## Memory
In `presentation.c` we use pointers to motivate that C programs do what you *say* not what you *meant to say*.
Understand that we can even cast a pointer in to a different data type to access memory more granularly.

## Memory Segments
We all know that code gets loaded in to memory before it gets executed. But how is it actually organized?

- stack (growing down) //for memory allocation and specifically to pass parameters to functions
- heap (growing up) //for dynamic memory allocation
- bss //for uninitialized data
- data //initialized, e.g. strings go here
- text/code //the actual executable

Note that we can inspect a process's memory segments by looking at `cat /proc/<pid>/maps`

## Stack
The stack is a LIFO data structure. Function Parabeters get pushed to the stack followed by teh *Return Address* and the calling function's Stack Frame Pointer (RBP).

- c
- b
- a 
- Return Address
- Old RBP
- local var1
- local var2

The current RBP points at the Return address, the RSP is used to point at the top of the stack.
PUSH and POP do not only, push to and pop from the stack, but they also increment and decrement the RSP.

# Registers
Each process uses the following special purposes registers. It's could to have an idea of how the compiler usually uses them.
- RAX, RSX, RDX and RCX, where A is for Arithmetic, S for Source D for Destination and C for Counter.
- RBP and RSP, are the Base Pointer for the Base of the the stack frame and the Stack pointer for the top of the stack.
- RIP is the instruction pointer, retain where the program execution is at

# Overflow
In `team_auth.c` we can overwrite the `buffer` variable to turn the `flag` variable into a value unequal to 0. Remember that unequal 0 is all we need, as everything but 0 is considered `true`
 


  
