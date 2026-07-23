# Operating Systems — Project 1 (2022–2023)

First laboratory project for the Operating Systems course of the Department of Computer Engineering and Informatics, University of Patras.

## Team

| Student | Registration number |
|---|---:|
| Νικόλαος Παπαδούρης | 1090040 |
| Αλέξανδρος Κολλώσης | 1084562 |
| Μίλτος Κουράκος | 1084621 |
| Νικόλαος Ανδρομιδάς | 1084641 |

## Repository contents

```text
.
├── README.md
├── Makefile
├── docs/
│   ├── assignment.pdf
│   └── submitted-report.pdf
├── question1/
│   ├── README.md
│   ├── access.log
│   └── logparser.sh
├── question2/
│   ├── README.md
│   ├── Makefile
│   ├── integral_seq.c
│   └── integral_msgq.c
├── question3/
│   ├── precedence_graph.dot
│   ├── precedence_graph.svg
│   └── solution.md
└── question4/
    └── scheduling_analysis.md
```

## Questions

### 1. Bash log parser

A Bash program processes `access.log` and supports printing the team IDs, displaying the log, mining usernames, filtering request methods and IP protocol versions, counting browsers and filtering records by month.

```bash
cd question1
./logparser.sh
./logparser.sh access.log--browsers
```

See [`question1/README.md`](question1/README.md) for every supported command.

### 2. Processes and System V message queues

The integral of `ln(x) × sqrt(x)` on `[1, 4]` is evaluated sequentially and with multiple child processes. Partial results are transferred to the parent process through a System V message queue.

```bash
make question2
./question2/integral_msgq
```

### 3. Interprocess synchronization

The repository contains the submitted precedence graph and the parallel pseudocode versions without semaphores, with one semaphore per edge and with the reduced semaphore set.

See [`question3/solution.md`](question3/solution.md).

### 4. Process scheduling

The scheduling analysis contains the submitted Gantt sequences and metrics for:

- FCFS
- SJF
- SRTF
- Round Robin with quantum 2
- Longest Remaining Time First Preemptive (LRTFP)

See [`question4/scheduling_analysis.md`](question4/scheduling_analysis.md).

## Build requirements

- Linux or another Unix-like system
- Bash
- GCC or Clang
- System V IPC support
- `make`

## Build

```bash
make
```

## Clean generated binaries

```bash
make clean
```

## Source documents

The original assignment and the submitted project report are included under `docs/` for reference.
