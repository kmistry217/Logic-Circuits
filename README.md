# Logic-Circuits

1 Introduction

This assignment is designed to give you some experience in C programming while also increasing
your understanding of circuits. You will be writing a C program to simulate the output of
combinational circuits.

2 Circuit Description Directives

One of the inputs to your program will be a circuit description file that will describe a circuit using
various directives. We will now describe the various directives.

The input variables used in the circuit are provided using the INPUTVAR directive. The INPUTVAR
directive is followed by the number of input variables and the names of the input variables.
All the input variables will be named with capitalized identifiers. An identifier consists
of at least one character (A-Z) followed by a series of zero or many characters (A-Z)
or digits (0-9). For example, some identifiers are IN1, IN2, and IN3. An example specification
of the inputs for a circuit with three input variables: IN1, IN2, IN3 is as follows:

INPUTVAR 3 IN1 IN2 IN3

The outputs produced by the circuit is specified using the OUTPUTVAR directive. The OUTPUTVAR
directive is followed by the number of outputs and the names of the outputs.
An example specification of the circuit with output OUT1 is as follows:

OUTPUTVAR 1 OUT1

The circuits used in this assignment will be built using the following building blocks: NOT, AND,
OR, NAND, NOR, XOR.

The building blocks can produce temporary variables as outputs. Further, these building blocks
can use either the input variables, temporary variables, a boolean ’1’ or a ’0’ as input.
Note: Output variables will never be used as inputs in a building block.

All the temporary variables will also be named with lower case identifiers (i.e., temp1, temp2,
temp3, ...).

The specification of each building block is as follows:

• NOT: This directive represents the not gate in logic design. The directive is followed by the
name of an input and the name of an output.
An example circuit for a NOT gate (OUT1 = IN1) is as follows.
NOT IN1 OUT1

• AND: This directive represents the and gate in logic design. The directive is followed by the
names of the two inputs and the name of the output.
An example circuit for an AND gate (OUT1 = IN1.IN2) is as follows:
AND IN1 IN2 OUT1

• OR: This directive represents the or gate in logic design. The directive is followed by the
names of the two inputs and the name of the output.
An example circuit for an OR gate (OUT1 = IN1 + IN2) is as follows:
OR IN1 IN2 OUT1

• NAND: This directive represents the nand gate in logic design. The directive is followed by
the names of the two inputs and the name of the output.
An example circuit for an NAND gate (OUT1 = IN1.IN2) is as follows:
NAND IN1 IN2 OUT1

• NOR: This directive represents the nor gate in logic design. The directive is followed by the
names of the two inputs and the name of the output.
An example circuit for an NOR gate (OUT1 = IN1 + IN2) is as follows:
NOR IN1 IN2 OUT1

• XOR: This directive represents the xor gate in logic design. The directive is followed by the
names of the two inputs and the name of the output.
An example circuit for an XOR gate (OUT1 = IN1 ⊕ IN2) is as follows:
XOR IN1 IN2 OUT1



3 Describing Circuits using the Directives

It is possible to describe any combinational circuit using the above set of directives. For example,
the circuit OUT1 = IN1.IN2 + IN1.IN3 can be described as follows:

INPUTVAR 3 IN1 IN2 IN3
OUTPUTVAR 1 OUT1
AND IN1 IN2 temp1
AND IN1 IN3 temp2
OR temp1 temp2 OUT1

Note that OUT1 is the output variable. IN1, IN2, and IN3 are input variables. temp1 and temp2
are temporary variables.

As seen above, a circuit description is a sequence of directives. If every temporary variable occurs
as a output variable in the sequence before occurring as an input variable, we say that the circuit
description is sorted. You can assume that the circuit description files will be sorted.
Note: A temporary variable can occur as an output variable in at most one directive.
3

4 Format of the Input Files

As you will see in the problem statement below, your program will be given one file as input. It
contains the description of a circuit using the directives described above.
For example, say that the circuit description file contains the following:
INPUTVAR 3 IN1 IN2 IN3
OUTPUTVAR 1 OUT1
AND IN1 IN2 temp1
AND IN1 IN3 temp2
OR temp1 temp2 OUT1

5 Common instructions

• You have to a write a C program that takes a file name as command line arguments.
• The file name will be the circuit description file.
• The program should interpret and evaluate the circuit on that assignment, and output the
values of the output variables as an order of Gray code.
• The values of the output variables should be space separated and be in the same order as
the output variables in the INPUTVAR and OUTPUTVAR directive, e.g., if the circuit
description file has the directive INPUTVAR 3 IN1 IN2 IN3, and OUTPUTVAR 3 OUT1
OUT2 OUT3, then the first value should be that of the input variable IN1, IN2, IN3 and
output variable OUT1, followed by that of OUT2, and then that of OUT3.
• For every Gray code, the output should be on a new line.

6 The first problem 

You have to write a program called first as described above. You are guaranteed that the circuit
descriptions given as input to your program will be sorted. Let’s look at an example we have
encountered before.
Example Execution 1
Suppose a circuit description file named circuit.txt has the description for the circuit OUT1 =
IN1.IN2 + IN1.IN3

INPUTVAR 3 IN1 IN2 IN3
OUTPUTVAR 1 OUT1
AND IN1 IN2 temp1
AND IN1 IN3 temp2
OR temp1 temp2 OUT1

./first circuit.txt
0 0 0 0
0 0 1 0
0 1 1 0
0 1 0 0
1 1 0 1
1 1 1 1
1 0 1 1
1 0 0 0

The output of the first three columns are INPUTVAR IN1, IN2, and IN3 respectively. And the
last column denotes as the OUTPUTVAR OUT1.
Note the use of the temporary variables in the circuit description file to represent intermediate
outputs.
