# Robot-Factory

The purpose of this program, like a program that your own computer would try to run, is to transcribe the champions (the .s files) into a language that the Corewar tournament program can understand. It will therefore be necessary to understand the assembly language in order to translate it byte by byte.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)

## About

The Corewar tournament is a game in which several programs called Champions will fight to stay the last one alive. Corewar is actually a computer simulation in which processors will share memory to run on.
The project is based on a virtual machine in which the champions will fight for memory by all possible means in order to win, the last champion being able to signal that he is alive wins the game. In other words, the last champion to execute the live instruction is declared winner.
In other words, the Robot Factory project will be your ability to transform robot plans, files written in assembler, into tournament-ready robots, files written in bytecode.

## Getting Started

Execute the binary file.

```bash
    ./asm file_name[.s
    ```
