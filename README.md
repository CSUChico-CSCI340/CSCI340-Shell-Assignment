# CSCI340-Shell-Assignment
##Writing Your Own Unix Shell
Adapted from a University of Colorado shell lab assignment that gives students practice with exceptional control flow.


##Introduction
The purpose of this assignment is to become more familiar with the concepts of process control and signal-
ing. You’ll do this by writing a simple Unix shell program that supports job control.

##Logistics
The only “hand-in” will be electronic. Any clarifications and revisions to the assignment will be posted on
my web page and emailed out to the class.

##Hand Out Instructions
I recommend you use a Ubuntu Linux virtual machine to complete this assignment. Alternatively, you can
use jaguar (although this hasn’t been tested) or your native Linux install.

Download this repository as a zip file and then extract it where you would like to store your project files. Alternatively, I'd recommend cloning this repository as a local repository. An example for cloning is below assuming you are in your home directory:

<pre>
~$ git clone git@github.com:CSUChico-CSCI340/CSCI340-Shell-Assignment.git
~$ cd CSCI340-Shell-Assignment/shlab-handout/
~$ make
<pre>

This does the following:

1. Clones the remote repository to your local computer in the folder CSCI340-Shell-Assignment
2. Change directory to the shlab-handout files in the CSCI340-Shell-Assignment folder in one step
3. Test that the project files build correctly in their initial state.
4. Now that you've got the files and they work, enter your name and student ID in the header comment at the top of
tsh.c.


Looking at the *tsh.c* (tiny shell) file, you will see that it contains a functional skeleton of a simple Unix
shell. To help you get started, the less interesting functions have already been implemented; some of these
are in helper-routines.c. Your assignment is to complete the remaining empty functions listed
below. As a sanity check for you, the approximate number of lines of code for each of these functions have
been listed in the reference solution (which includes lots of comments).

* eval: Main routine that parses and interprets the command line. [70 lines]
* builtin_cmd:  Recognizes and interprets the built-in commands: quit,fg,bg, and jobs. [25 lines]
* do_bgfg: Implements the bg and fg built-in commands. [50 lines]
* waitfg: Waits for a foreground job to complete. [20 lines]
* sigchld_handler: Catches SIGCHILD signals. [80 lines]
* sigint_handler: Catches SIGINT (ctrl-c) signals. [15 lines]
* sigtstp_handler: Catches SIGTSTP (ctrl-z) signals. [15 lines]

Each time you modify your *tsh.c* file, type *make* to recompile it. To run your shell, type *tsh* to the command line:

<pre>
unix> ./tsh
tsh> [type commands to your shell here]
</pre>

##General Overview of Unix Shells
A
shell
is an interactive command-line interpreter that runs programs on behalf of the user. A shell repeat-
edly prints a prompt, waits for a
command line
on
stdin
, and then carries out some action, as directed by
the contents of the command line.
The  command  line  is  a  sequence  of  ASCII  text  words  delimited  by  whitespace.   The  first  word  in  the
command line is either the name of a built-in command or the pathname of an executable file. The remaining
words are command-line arguments. If the first word is a built-in command, the shell immediately executes
the command in the current process.  Otherwise, the word is assumed to be the pathname of an executable
program. In this case, the shell forks a child process, then loads and runs the program in the context of the
child.  The child processes created as a result of interpreting a single command line are known collectively
as a
job
. In general, a job can consist of multiple child processes connected by Unix pipes.
If the command line ends with an ampersand ”
&
”, then the job runs in the
background
, which means that
the shell does not wait for the job to terminate before printing the prompt and awaiting the next command
line.  Otherwise, the job runs in the
foreground
, which means that the shell waits for the job to terminate
before awaiting the next command line.  Thus, at any point in time, at most one job can be running in the
foreground. However, an arbitrary number of jobs can run in the background.
For example, typing the command line
tsh>
jobs
causes the shell to execute the built-in
jobs
command. Typing the command line
tsh>
/bin/ls -l -d
2
