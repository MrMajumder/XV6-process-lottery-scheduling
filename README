# Greetings
In this repository, you will find the implementation of [**Lottery Scheduling**](https://www.geeksforgeeks.org/lottery-process-scheduling-in-operating-system/) during process scheduling. The default scheduling algorithm implemented is the [**First come first serve**](https://www.guru99.com/fcfs-scheduling.html) scheduling, which suffers from performance and turnaround time issues. You can find the details about one of the issues of FCFS, the convoy effect, [here](https://www.geeksforgeeks.org/convoy-effect-operating-systems/#:~:text=Convoy%20Effect%20is%20phenomenon%20associated,due%20to%20few%20slow%20processes.).

## Files to Visit
Since XV6 has a large codebase, it's easy to feel lost while modifying the OS. I myself were pretty lost during working with it. So, let me give a heads up on the files you should review first before trying to implement a process scheduling algorithm.
1. `proc.c` & `proc.h` files for implementation of the algorithm. Specifically the `scheduler()` function.
2. `sysproc.c` file for implementing a system call. 
3. `checksched.c` file where a system call for checking the ticket count during the scheduling and verifying the implementation.

## Helpful Links
Some blogs which I read during implementing the algorithm and found helpful:
1. [Shiddharth's Blog](https://01siddharth.blogspot.com/2018/04/implementing-lottery-scheduling-on-xv6.html)
2. [Coup2Code's Blog](https://coup2codes.blogspot.com/2018/04/implementing-lottery-scheduling-on-xv6.html)

## My implementation
You can find the working version of my implementation in the `1705080.patch` file. By applying this patch, you will easily find all the changes I've done along with the tricks and techniques used.
## License
NOTE: we have stopped maintaining the x86 version of xv6, and switched
our efforts to the RISC-V version
(https://github.com/mit-pdos/xv6-riscv.git)

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also https://pdos.csail.mit.edu/6.828/, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Anton Burtsev, Cody Cutler, Mike CAT, Tej Chajed, eyalz800,
Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron,Shivam Handa, Bryan Henry, Jim Huang, Alexander
Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller, Eddie Kohler, Austin
Liew, Imbar Marinescu, Yandong Mao, Matan Shabtay, Hitoshi Mitake, Carmi
Merimovich, Mark Morrissey, mtasm, Joel Nider, Greg Price, Ayan Shafqat,
Eldar Sehayek, Yongming Shen, Cam Tenny, tyfkda, Rafael Ubal, Warren
Toomey, Stephen Tu, Pablo Ventura, Xi Wang, Keiichi Watanabe, Nicolas
Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2018 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

We don't process error reports (see note on top of this file).

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run
"make". On non-x86 or non-ELF machines (like OS X, even on x86), you
will need to install a cross-compiler gcc suite capable of producing
x86 ELF binaries (see https://pdos.csail.mit.edu/6.828/).
Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC
simulator and run "make qemu".