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
