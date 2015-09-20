testGenerator generates multiple choice flash card questions based on the information
provided in the input file

To compile:

```
$ make clean
$ make
```

To run examples, use the bash script:
```
$ ./run-example
```

To use the executable directly:
```
$ ./testGenerator <input file>
```

Formatting of the input file:
```
<keyword>: <description>
...
<keyword>: <description>
<empty line>
<keyword number>, <keyword number>, ... 
...
<keyword number>, <keyword number>, ... 
```

The keyword numbers are separated by commas. 
Also, the keyword numbers on the same line are grouped together. The generator
picks maximum five keywords randomly from the same group/line for each question.
Only one keyword among the ones chosen is the correct answer. 
The keywords may be reused in multiple groups.
Check the examples to see the format.

While running the test:

```
<question> about some <keyword>?
A <description>
B <description>
C <description>
D <description>
E <description>
```

User should enter one of a, b, c, d, e, q. Answer choice should be in lowercase.
q exists the test and does accounting.

Files and Directories:

results        - where the results are saved

examples       - directory that contains the examples

testGenerator  - executable

src            - source files 
