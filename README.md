# Monty ByteCode Interpreter

## Stacks, Queues - LIFO, FIFO

This repository covers programs written in C about Data Structures, Stacks(LIFO) and Queues(FIFO).

Here we will centered in Stacks that its elements can be added or removed by push or pop following an order that is the
Last in will be the First Out. Is like a Hanoi Tower for example.

## Description
### The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.
## Objective of this project
create an interpreter for Monty ByteCodes files.
## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- All your files should end with a new line
- You allowed to use a maximum of one global variable
- No more than 5 functions per file

## How to use it
```
  git clone https://github.com/MiguelCF06/monty.git
  ```
and here make:
```
  cd monty
  ```
and compile with:
```
  gcc -Wall -Werror -Wextra -pedantic *.c -o monty
  ```

## Examples
First you have to make a ".m" file.
Here is a example of push, pop and pall:
```
  > cat bytecodes/000.m
  push 1
  push 43
  push 53
  pall
  pop
  pall
  pop
  pall
  > ./monty bytecodes/000.m
  53
  43
  1
  43
  1
  1
  ```
And here is for swap:
```
  > cat bytecodes/001.m
  push 1
  push 33
  push 45
  pall
  swap
  pall
  > ./monty bytecodes/001.m
  45
  33
  1
  33
  45
  1
  ```
## Authors
[Miguel Cipamocha](https://github.com/MiguelCF06)
[Santiago Gallego](https://github.com/Santiago-Gallego)