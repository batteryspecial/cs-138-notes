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

# Commands in the UNIX Shell

Generally, you are running cmd-line programs with options and arguments. Whatever you type is passed to bash. Typically it looks like this.

```bash
$ cmd -opt1 -opt2 arg1 -opt3 arg2 arg3 arg4
```

An option is something you select, an argument is a specific input that may be required by an option.

A command can be onf of...
1. An alias (a simpler name) for a built-in / external cmds with pre-supplied arguments.
    - eg. `alias rm='rm -iv'`
    - You can configure your own aliases in ~/.zshrc
2. Built-in commnads.
    - eg. `echo` and `type`
3. An external program (an executable sitting on the system).
    - eg `g++`, `clang`, `mkdir`, `ls`, `nano`, `emacs`, `java`, `egrep`...

## How a Command is Parsed

Given a command 
```bash
$ cmd -opt1 -opt2 arg1 -opt3 arg2 arg3 arg4
```
- First, the shell looks for an alias called `cmd`.
- If none, look for a command called `cmd`.
- If not, look along the user's `PATH` for `cmd`.

__What is `PATH`?__

There is a predefined shell variable called `PATH` that the shll uses to search for these external libraries. For me (Mac user) it is `/usr/bin`. 

It might also be `/usr/local/bin` or `$HOME/bin`, etc. The shell will look into the paths in order, and if it really can't find anything, the shell will give an error in response.

The value of PATH is typically set within the `.bashrc` file.

```bash
$ echo $PATH
/Users/_____/Library/pnpm:/opt/homebrew/opt/node@24/bin:/Users/_____/.volta/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/opt/local/bin:/opt/local/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/pmk/env/global/bin:/opt/homebrew/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/Users/_____/.volta/bin
```

## `type / which`

Let `flurble` be a shell command. What is the meaning in your current context? Is it an alias for `flurble -frobozz`? Is it a built-in shell command? Is it an external executable?

For `tcsh` and `bash`, typing `which flurble` will tell you the answer. For `bash` only, `type flurble` might give you more info.

```bash
$ pwd
/usr/bin
$ which ls
/bin/ls
$ cd ..
$ which volta
/Users/_____/.volta/bin/volta
$ which pnpm
/Users/_____/Library/pnpm/pnpm
$ which npm 
/opt/homebrew/opt/node@24/bin/npm
```

## `ls`

List everything in your current directory. Can take in options `F` and `G`.

```bash
$ ls
OBC-Firmware % ls
CMakeLists.txt		gs			requirements.txt
Dockerfile		hil			rm46l852.ccxml
README.md		interfaces		scripts
alembic			libs			setup.cfg
alembic.ini		migrations		setup.py
cmake			obc			test
compose-dev.yaml	pyproject.toml
docker-compose.yaml	python_test
$ ls -F
_____@eduroam-campus-10-36-71-20 OBC-Firmware % ls -F
CMakeLists.txt		gs/			requirements.txt
Dockerfile		hil/			rm46l852.ccxml
README.md		interfaces/		scripts/
alembic/		libs/			setup.cfg
alembic.ini		migrations/		setup.py
cmake/			obc/			test/
compose-dev.yaml	pyproject.toml
docker-compose.yaml	python_test/
```

`-G` or `--color` adds colors to special files like folders and executables. For example, the executable `a2p1` will be shown as `a2p1*` with `ls -F`. There are also other indicators, `@` means the file has extended attributes, which you can view using `xattr`.

You can also use `ls -a` to show all files, including hidden ones. Use `ls -A` to show all files except for `.` and `..` (run `ls -a` to see what I mean). Run `ls -la` to use long listing format (verbose).

```bash
@ubuntu2404-012:~/cs138/assgts/assgt2/a2p1$ ls -la
total 98
drwxrws--x 5 _____ cs138     5 Jan 25 00:43 .
drwxrws--x 6 _____ cs138     6 Jan 16 18:16 ..
-rwxrwx--x 1 _____ cs138 92320 Jan 25 00:43 a2p1
-rw-rw---- 1 _____ cs138  7257 Jan 25 00:47 a2p1.cc
drwxrws--x 3 _____ cs138    29 Jan 25 00:47 build
drwxrws--x 2 _____ cs138    24 Jan 24 22:17 outputs-expected
drwxrws--x 2 _____ cs138    16 Jan 24 22:16 test-inputs
```

Let's start a subshell of tcsh and see what my professor has.

```bash
$ tcsh
% which ls
ls:        aliased to ls-F
$ which ls-F
ls-F: shell built-in command.
$ ls
Hearts@ balloon* balloon.cc oldStuff/
```

## `echo`

Writes arugments, separated by spaces and terminated with a newline. It is usually a good idea to use double or single quotes to enclose the message.

```bash
$ echo no place like HOME
no place like home
$ echo " no place like HOME"
 no place like home
$ echo "no place like $HOME"
no place like /Users/_____
$ echo 'no place like $HOME'
no place like $HOME
$ echo no place like $HOME
no place like /Users/_____
```

The shell finds the arguments, and although HOME looks like a system variable, there is no `$` so we are good. We can also use quotes and spaces, it does what you think it does. Note the single quote does not evaluate any commands.

# Globbing

Globbing are command-line pattern pattern expansions. It's like a wild card. You can access cmd line args by passing `int argv` and `char* argv[]` to main in C++.

Global patterns apply only to args, not commands or options. Note all examples here assume `bash`. The shell preprocesses the command.

__Special Chars__

Suppose the current dir is `/u/jdoe/cs138/a1q1` which contains files `q1x.c`, `q2y.h`, `q2y.cc`, `q3z.cpp`.

1. `*` matches 0 or more characters. `?` matches a single character.
    ```bash
    $ echo q*
    q1x.C q2y.h q2y.cc q3z.cpp
    $ echo q*.??
    q2y.cc
    ```

2. {...} matches any alternative in the set. Happens before globbing.
    ```bash
    $ echo *.{C,cc,cpp}
    q1x.C q2y.cc q3z.cpp
    ```
3. [...] matches one character in the set. Happens as a part of globbing.
    ```bash
    $ echo q[12]*
    q1x.C q2y.h q2y.cc
    ```
4. [!...] matches 1 character not in the set.
    ```bash
    $ echo q[!12]*
    q3z.cpp
    ```
5. Create ranges using `-`.
    ```bash
    q[0-3]*     # second character is 0,1,2,3
    q[a-zA-z]*  # lower or upper case letter
    q[!a-zA-Z]  # any char that is not a letter
    ```

`-` is escaped by putting it at the start or end of a set. For example `[-?*]*` matches file names starting with `-`, `?`, or `*`.

The asterisk also does not match `.`, for your own good! `ls *flurble*` will find `flurblemaster` but will not find `.flurble`.

My professor is a fan of Justin Bieber. Let's see what he does to find his favorite tunes.

```bash
$ cd /Users/migod/Music/iTunes/iTunesMusic/BiebersGold
$ ls *[Bb]ieber*.mp3
I-love-Justin-Beiber-fanSong.mp3
Bieber-SingsBruceSpringsteen-concert-full-3hours.mp3
lalalabieberlalala.mp
```

## Globbing and Quotes

Globbing is turned off inside single and double quotes.
- For single quotes, everything up to the enxt quote is protected, including newline (\n) and double quotes (").
- For double quotes, everything is protected except doublequote, backquote(~), and `$VARs`.

```bash
% cd temp /
$ ls # aliased to ls -F
Hearts> balloon* balloon.cc oldStuff/

$ echo My balloon* home is $HOME
My balloon balloon.cc is /Users/migod

$ echo My "balloon* home is $HOME"
My balloon* home is /Users/migod

% echo My 'balloon* home is $HOME'
My balloon* home is $HOME
```
