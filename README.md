# Operating Systems — Project 1

First laboratory project for the **Operating Systems** course, academic year **2022–2023**.

The project includes Bash scripting, process creation and communication through System V message queues, interprocess synchronization and process-scheduling analysis.



## Repository files

```text
.
├── README.md
├── access.log
├── logparser.sh
├── integral_seq.c
├── integral_msgq.c
├── precedence_graph.svg
├── solution.md
└── scheduling_analysis.md
```

## Question 1 — Bash log parser

The `logparser.sh` script processes the supplied Apache-style log file, `access.log`.

Supported operations include:

- displaying the registration numbers of the team members;
- printing the complete log file;
- counting and filtering user IDs;
- filtering HTTP requests by `GET` or `POST`;
- filtering records by IPv4 or IPv6;
- counting browser-related strings;
- filtering records by month.

Make the script executable:

```bash
chmod +x logparser.sh
```

Examples:

```bash
./logparser.sh
./logparser.sh access.log
./logparser.sh access.log--usrid
./logparser.sh access.log-method
./logparser.sh access.log--servprot
./logparser.sh access.log--browsers
./logparser.sh access.log--datum
```

For the interactive operations, the requested value is entered after the program starts.

## Question 2 — Processes and message queues

The integral

```text
f(x) = ln(x) × sqrt(x),  x ∈ [1, 4]
```

is calculated using the midpoint numerical-integration method.

- `integral_seq.c`: sequential implementation.
- `integral_msgq.c`: multiprocess implementation using `fork()` and a System V message queue for transferring partial results from child processes to the parent process.



The expected numerical result is approximately:

```text
4.28245881
```

> The programs use one billion integration intervals, so execution may take significant time depending on the system.

## Question 3 — Interprocess synchronization

The third question concerns the synchronization of twelve operations in a pharmaceutical packaging production line.

- `precedence_graph.svg` contains the precedence graph.
- `solution.md` contains the parallel pseudocode, the semaphore-based synchronization solution and the reduced-semaphore version.

## Question 4 — Process scheduling

The scheduling analysis is contained in `scheduling_analysis.md` and covers:

- FCFS — First Come First Served;
- SJF — Shortest Job First;
- SRTF — Shortest Remaining Time First;
- Round Robin with time quantum 2;
- LRTFP — Longest Remaining Time First Preemptive.

The file includes Gantt sequences, waiting times, response times, turnaround times, context-switch counts and comparisons with FCFS.

## Requirements

- Linux or another Unix-like operating system
- Bash
- GCC or Clang
- System V IPC support

## Notes

This repository presents the source code, diagrams and written solutions developed for the first Operating Systems laboratory project.
