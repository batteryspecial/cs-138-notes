# Operating Systems

An operating system provides an abstraction layer for clients to interact with the underlying resources of a computer. The OS manages apps, time sharing, communication, fair use of CPU, memory, and devices. It also prevents misbehavior and the UI can be graphical or command line.

![alt text](<截屏2026-01-22 下午10.36.55.png>)

## The Shell

Humans don't interact with the raw OS directly. The user can use the native OS GUI (if there is one), or a shell (command line interface). Applications can talk to the raw OS, or the OS GUI, or the CLI (shell scripts).

__MacOS__
- Two layers. A GUI sits on top of the Darwin UNIX dialec.
- iOs also sits on top of Darwin, but Darwin is inaccessible to normal users in iOS.
- Similarly, Android and KindleOS sits on top of Linux. Windows 95/98/ME did the asme thing with DOS.

## A Brief History of UNIX

![alt text](https://upload.wikimedia.org/wikipedia/commons/8/8a/Simh-pdp11-unix-sysiii.png "UNIX System III running on a PDP-11 simulator")

UNIX was a massive achievement in computing systems. UNIX focused on "doing one thing well" and combining processes into a pipeline. The UNIX operating system and the C programming language were developed together.

Early versions of UNIX were written in PDP-7 Assembly. Later rewritten in C, which was a __huge__ win because C was a high-level programming language which humans could understand. Later, C++ was also developed there by Stroustrup et al.



__What does UNIX stand for?__
UNIX is not an acronym; it's Kernighan's lame joke, a play on MULTICS (Multiplexed Information and Computing Service), another well known OS at the time.

![alt text](https://upload.wikimedia.org/wikipedia/commons/d/d6/Multics-Login.png "Login screen for the BAN.AI public Multics server.")

## Versions of UNIX

AT&T's licensing allowed people to make their own variants.

__BSD UNIX__
- BSD UNIX (late 1970s) at UC-Berkeley, reimplementation with brand new code and new design ideas.
- OS X, iOS are both based on NextStep (Steve Jobs' old company), which is in turn based on BSD; "Darwin"