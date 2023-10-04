# Simple Shell project 0x16.c
 This project consist of a basic command interpreter (shell) created in c language with several features; it's dveelopement is part of the internsive learning process of sofware engineering in ALX_AFRICA School.

# Synopsis

 The simple_shell is a program that reads commands provided by user through standard input stream and attempts to execute them by means of low level system procedures. This is by using built in functions or searching for executable programs in the operating system.

 Interactive and Non-interactive.

In Interactive mode, the shell will display a prompt ($) indicating that the user can write and execute a command. After the command is run, the prompt will appear again a wait for a new command. This can go indefinitely as long as the user does not exit the shell.

Examples

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$


$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

# Return (Exit value)

Upon termination of the simple shell program, an exit value will be set according to the status of the last command executed. If no error was ever encountered, the exit value will be zero (0).

If an error is found, values that can be set are:

1 - Catchall for general errors

2 - Misuse of shell builtins

126 - Command invoked cannot execute

127 - command not found

130 - Script terminated by Control-D

# Format of Command Input

In order to give commands to the simple shell, these will need to be piped through an echo in case of Non-interactive mode.

In Interactive Mode the commands will need to be written with a keyboard when the prompt appears and then will be recognized when an enter key is pressed (new line). As soon as this happens, the Shell will attempt to execute the command through several means. In this mode, the program can be exited using the CTRL + D combination, as the CTRL + C signal is reserved only for internal script termination and it does not exit the shell.

# Built ins

The simple shell has a set of commands that work like internal functions and don't require the search for any executable program.

Built In	Description
exit	This command is used for exiting the Shell, its syntax is exit status , where status is an integer number. If no status is given, exit will use the value set by the last error encountered.
env	This command is used for displaying the system's current environment in the format variable=value. Its syntax is simply env with no options.
setenv	This command will overwrite the value of an environmental variable if it already exists, or create a new one in case it does not. Its syntax is setenv VARIABLE VALUE. If no arguments are given, then setenv will print the current environment as if env had been used.
unsetenv	This command will remove an environmental variable from the system if it exists, or leave the environment untouched if it does not. Its syntax is unsetenv VARIABLE. If no argument is given, the environment will remain the same.
cd	This command is used for changing the current working directory. Its syntax is cd DIRECTORY. If no directory is specified, cd will change directory to the value set in the environmental variable HOME. If instead of directory, a symbol - is used, then cd will change to the previous working directory, which by default is initially HOME.
help	This command will show a text explaining the usage of a built in. Its syntax is help BUILTIN. If this command is run without argument, then a list of all built ins and their syntax will be displayed. This command can be used on itself.

# Installing

You will need to clone the repositiory of the project from Github, This will contain the simple shell and what it encompase.

git clone https://github.com/timileyin42/simple_shell.git

# Authors

Akanmu Ibrahim Timileyin, Adeyemi subedat
