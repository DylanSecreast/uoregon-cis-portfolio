###CIS 415 – Operating Systems
####Homework Assignment 1
#####Spring 2016 – Prof. Sventek
#####Due at 5:00pm on Thursday, 14 April 2016

All questions must be answered by you without outside assistance. Submission is via Canvas.
You may submit either a plain text (.txt) or a PDF (.pdf) file. Succinct, concise answers to the
questions are preferable to long, rambling ones.

**Textbook Questions (30 points)**

1. OSC 2.18: What are the two models of interprocess communication? What are the strengths
and weaknesses of the two approaches?
2. OSC 2.19: Why is the separation of mechanism and policy desirable?
3. OSC 3.9: Describe the actions taken by a kernel to context-switch between processes?
4. OSC 3.18: What are the benefits and the disadvantages of each of the following? Consider
both the system level and the programmer level.
  1. Synchronous and asynchronous communication
  2. Automatic and explicit buffering
  3. Send by copy and send by reference
  4. Fixed-sizes and variable-sized messages
5. OSC 4.14: A system with two dual-core processors has four processors available for
scheduling. A CPU-intensive application is running on this system. All input is performed at
program start-up, when a single file must be opened. Similarly, all output is performed just
before the program terminates, when the program results must be written to a single file.
Between start-up and termination, the program is entirely CPU-bound. Your task is to
improve the performance of this application by multithreading it. The application runs on a
system that uses the one-to-one threading model (each user thread maps to a kernel thread).
  1. How many threads will you create to perform the input and output? Explain.
  2. How many threads will you create for the CPU-intensive portion of the application?
Explain.
6. OSC 4.18: Consider a multicore system and a multithreaded program written using the manyto-many
threading model. Let the number of user-level threads in the program be greater than
the number of processing cores in the system. Discuss the performance implications of the
following scenarios.
  1. The number of kernel threads allocated to the program is less than the number of
processing cores.
  2. The number of kernel threads allocated to the program is equal to the number of
processing cores.
  3. The number of kernel threads allocated to the program is greater than the number of
processing cores but is still less than the number of user-level threads.

**Process Analysis (20 points)**

Suppose you want to find out as much as you can about a running process, one where you do not
have access to the source code. Design a methodology using the Linux proc filesystem to extract
as much information as you can. You should be able to apply this to any of your running
processes. For instance, an experiment may begin something like this:
```
% sleep 600&
[1] 1363
```

You can cd to /proc/1363 and run ls, where you will see a lot files and directories. Some of the
files contain relevant information. Explain which piece of information each step of your
methodology is designed to supply, and how it relates to the program, process, and operating
system.

Note: Like all assignments in this class you are prohibited from copying any content from the
Internet or sharing ideas, code, configuration, text or anything else or getting help from
anyone in or outside of the class, except where noted. Consulting online sources is acceptable,
but under no circumstances should anything be copied. Failure to abide by this requirement will
result in sanctions ranging from zero on the assignment to dismissal from the class.
