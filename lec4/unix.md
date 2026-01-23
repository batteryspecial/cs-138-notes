# Operating Systems

An operating system provides an abstraction layer for clients to interact with the underlying resources of a computer. The OS manages apps, time sharing, communication, fair use of CPU, memory, and devices. It also prevents misbehavior and the UI can be graphical or command line.

![alt text](<截屏2026-01-22 下午10.36.55.png>)

## The Shell

Humans don't interact with the raw OS directly. The user can use the native OS GUI (if there is one), or a shell (command line interface). Applications can talk to the raw OS, or the OS GUI, or the CLI (shell scripts).

__MacOS__
- Two layers. A GUI sits on top of the Darwin UNIX dialec.
- iOs also sits on top of Darwin, but Darwin is inaccessible to normal users in iOS.
- Similarly, Android and KindleOS sits on top of Linux. Windows 95/98/ME did the asme thing with DOS.

# A Brief History of UNIX

![alt text](https://upload.wikimedia.org/wikipedia/commons/8/8a/Simh-pdp11-unix-sysiii.png "UNIX System III running on a PDP-11 simulator")

UNIX was a massive achievement in computing systems. UNIX focused on "doing one thing well" and combining processes into a pipeline. The UNIX operating system and the C programming language were developed together.

Early versions of UNIX were written in PDP-7 Assembly. Later rewritten in C, which was a __huge__ win because C was a high-level programming language which humans could understand. Later, C++ was also developed there by Stroustrup et al.

__What does UNIX stand for?__
UNIX is not an acronym; it's Kernighan's lame joke, a play on MULTICS (Multiplexed Information and Computing Service), another well known OS at the time.

![alt text](https://upload.wikimedia.org/wikipedia/commons/d/d6/Multics-Login.png "Login screen for the BAN.AI public Multics server.")

## Versions of UNIX

AT&T's licensing allowed people to make their own variants.
- BSD UNIX (late 1970s) at UC-Berkeley, reimplementation with brand new code and new design ideas.
- OS X, __iOS__ are both based on NextStep (Steve Jobs' old company), which is in turn based on BSD; "Darwin"
- Android, KindleOS are based on __Linux__ (mid-1990s, open source project)
- Solaris / SunOS (early 1980s, Sun Microsystems, now owned by Oracle)
- AIX, HP-UX, SCO, ... other commercial Unices

# GNU

The name for some African wildebeest in Afrikaans. In 1984, Richard M. Stallman founds the GNU (Gnu's Not Unix) project and later the FSF (Free Software Foundation). His goal was to provide a truly free UNIX-like operating system. Free like speech, not free like beer. The GPL license "virus" ensures software remains free.

GNU continues to have MASSIVE impact today.
- Most of the web runs on technology based on open standards
- Open source software systems include: GNU-Linux/BSD, Firefox/Chrome, GCC/LLVM, Apache, LibreOffice

As you can see there are some big names up there.

## The Original Components of the GNU System

1. GCC (Gnu Compiler Collection)
    - gcc, g++, ...
2. ` glibc` (Gnu C library)
3. GNU coreutilities (`ls`, `cp`/`rm`/`mv`, `chmod`, ...)
4. Some other stuff too (a shell, `gdb`, ...)
5. Not an actual OS kernel!

These are all from-scratch entirely-new-code re-implementations of existing tools from the (proprietary) UNIX. With GPL, this means they are free in any future derivative work.

# Linux

In a time where there were many commercial UNIX systems, Finnish student Linus Torvalds started Linux as a part time project in 1991; many programmers join in "for fun"; v1.0 released in 1994.

__What is Linux?__
- Technically it's just the OS kernel (bridge between components and system calls).
- A Linux distro (e.g., Ubuntu, Debian, ArchLinux) contains a lot of "free software" (much of it, GNU) so people can actually use it.
- Richard calls it GNU/Linux

# The UNIX File System

The UNIX file system is organized under "/", the root directory.

![alt text](http://www.openbookproject.net/tutorials/getdown/unix/images/lesson2/UnixDirectoryTree.png)

For example you could host your personal site under `public_html`.

Pretty much all OSs have a file system of some kind, your home directory (folder) is where your stuff is stored, not the system stuff, and not the stuff of the others who use your computer.

My home dir is in `/Users/infin` on MacOS. At the command line, you can reference your home dir by ~ or $HOME. `~infin` represents the home directory of `infin`, no slash.

`sh` was the first practical, widely-used UNIX shell. Later relatives, like `bash` and `ksh` were created, intended to allow programmers to write shell scripts. Other common shells include `csh`, `tcsh` are meant for live "end users"

## Commands in the UNIX Shell

By default we start in the home dir.
- `cd` takes you back home.
- `cd -` takes you to the last dir.
- `cd ..` takes you to the parent of the current dir.
- `cd .` leaves you where you are (why?).

### Example on My Professor's Device
```bash
% pwd
/Users/migod
% cd temp
% ls
Hearts> balloon.cc oldStuff/
% g++ -o balloon balloon.cc
% ./balloon
clear balloon
red balloon
green balloon
green balloon
% cd Hearts/
% ls
Card.cc Makefile.bak* Trick.cc hearts.xcodeproj/
Card.h Options.h* Trick.h hearts.xml.zip
CardPile.cc Player.cc build/ ideas
CardPile.h Player.h deck1* main.cc
Deck.cc RandomPlayer.cc deck2* mkPrintable*
Deck.h RandomPlayer.h deck3* printme/
Globals.h SmartPlayer.cc hearts.1
Makefile SmartPlayer.h hearts.mdr
% cat Makefile
# Make sure you're using /usr/ccs/bin/make and not GNU make.
# Use the "which make" command to find out which you're
% make
g++ -c –g Card.cc
g++ -c –g CardPile.cc
g++ -c –g Deck.cc
g++ -c –g Trick.cc
g++ -c –g Player.cc
g++ -c –g SmartPlayer.cc
g++ -c –g RandomPlayer.cc
g++ -c –g main.cc
g++ -g -o hearts Card.o CardPile.o Deck.o Trick.o Player.o SmartPlayer.o
RandomPlayer.o main.o
% ./hearts
Here are the hands of each player for hand number 1
Abe has these cards:
Seven of Diamonds
Queen of Spades
Queen of Hearts
```

