
<h1 align="center">Monty</h1>

<h3>
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</h3>

<h2>&diams;	Phases</h2>
<h3>
<li>Phase 1 : </li>
  <br>
  Implement the `push` and `pall` opcodes.

The `push` opcode

The opcode `push` pushes an element to the stack.

<ul>
<p>

<li>

  Usage: `push <int>`
  
&emsp;&emsp;where `<int>` is an integer

</li>
</p>

<p>

<li>

if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`

</li>

</p>

<li>
where is the line number in the file
You won’t have to deal with overflows. Use the `atoi` function.

</li>
</ul>

The pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

<ul>

<li>
  
Usage `pall`  </li>

<li>Format: see example</li>

<li>If the stack is empty, don’t print anything</li>

</ul>

```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```

</h3>
  
