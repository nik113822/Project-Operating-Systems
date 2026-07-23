# Question 4 — Process scheduling

The following tables reproduce the schedules and calculations in the submitted report.

## Input processes

| Process | Arrival time | Execution time | PID |
|---|---:|---:|---:|
| A | 0 | 6 | 3 |
| B | 0 | 4 | 1 |
| Γ | 2 | 1 | 2 |
| Δ | 3 | 3 | 5 |
| E | 4 | 5 | 4 |
| Z | 5 | 7 | 1 |

## FCFS

Gantt sequence:

```text
0        4          10  11     14          19              26
|   B    |     A     | Γ |  Δ   |     E     |       Z       |
```

| Process | Completion/turnaround calculation | Waiting/response calculation |
|---|---:|---:|
| A | 10 − 0 = 10 | 4 − 0 = 4 |
| B | 4 − 0 = 4 | 0 |
| Γ | 11 − 2 = 9 | 10 − 2 = 8 |
| Δ | 14 − 3 = 11 | 11 − 3 = 8 |
| E | 19 − 4 = 15 | 14 − 4 = 10 |
| Z | 26 − 5 = 21 | 19 − 5 = 14 |

- Mean completion/turnaround time: **11.2**
- Mean waiting/response time: **7.3**
- Allocations counted in the report: one per process.

## SJF

```text
0        4  5     8          13            19              26
|   B    |Γ|  Δ   |     E     |      A      |       Z       |
```

| Process | Completion/turnaround | Waiting/response |
|---|---:|---:|
| A | 19 | 13 |
| B | 4 | 0 |
| Γ | 3 | 2 |
| Δ | 5 | 2 |
| E | 9 | 4 |
| Z | 21 | 14 |

- Mean completion/turnaround time: **10.2**
- Mean waiting/response time: **5.8**
- Allocations counted in the report: one per process.

## SRTF

```text
0    2  3    5     8          13            19              26
| B  |Γ| B  |  Δ   |     E     |      A      |       Z       |
```

| Process | Completion/turnaround | Waiting/response |
|---|---:|---:|
| A | 19 | 13 |
| B | 5 | 0 |
| Γ | 1 | 1 |
| Δ | 5 | 2 |
| E | 9 | 4 |
| Z | 21 | 14 |

- Mean completion/turnaround time: **10.0**
- Mean waiting/response time: **5.7**
- Allocations counted in the report: A=1, B=2, Γ=1, Δ=1, E=1, Z=1.

## Round Robin, quantum = 2

Submitted sequence and intervals:

| Interval | Process |
|---|---|
| 0–2 | B |
| 2–4 | A |
| 4–6 | B |
| 6–7 | Γ |
| 7–9 | Δ |
| 9–11 | A |
| 11–13 | E |
| 13–15 | Z |
| 15–16 | Δ |
| 16–18 | A |
| 18–20 | E |
| 20–22 | Z |
| 22–23 | E |
| 23–26 | Z |

| Process | Completion/turnaround | Waiting/response |
|---|---:|---:|
| A | 18 | 12 |
| B | 6 | 2 |
| Γ | 5 | 4 |
| Δ | 13 | 10 |
| E | 19 | 14 |
| Z | 21 | 14 |

- Mean completion/turnaround time: **13.7**
- Mean waiting/response time: **9.3**
- Allocations counted in the report: A=3, B=2, Γ=1, Δ=2, E=3, Z=3.

## Change relative to FCFS

| Algorithm | Submitted change in mean completion/turnaround time |
|---|---:|
| SJF | −8.9% |
| SRTF | −10.7% |
| RR | +22.3% |

## LRTFP

Submitted sequence:

```text
A, B, A, E, Z, E, B, Z, A, E, Δ, B, Z, A, E, Δ, B, Z, Γ, A, E, Δ
```

Submitted interval representation:

| Interval | Process |
|---|---|
| 0–2 | A |
| 2–3 | B |
| 3–4 | A |
| 4–5 | E |
| 5–9 | Z |
| 9–10 | E |
| 10–11 | B |
| 11–12 | Z |
| 12–13 | A |
| 13–14 | E |
| 14–15 | Δ |
| 15–16 | B |
| 16–17 | Z |
| 17–18 | A |
| 18–19 | E |
| 19–20 | Δ |
| 20–21 | B |
| 21–22 | Z |
| 22–23 | Γ |
| 23–24 | A |
| 24–25 | E |
| 25–26 | Δ |

| Process | Completion/turnaround | Waiting/response |
|---|---:|---:|
| A | 24 | 18 |
| B | 21 | 17 |
| Γ | 21 | 20 |
| Δ | 23 | 20 |
| E | 21 | 16 |
| Z | 17 | 10 |

- Mean completion/turnaround time: **21.2**
- Mean waiting/response time: **16.8**
- Allocations counted in the report: A=5, B=4, Γ=1, Δ=3, E=5, Z=4.

Tie-breaking described in the report:

1. Choose the process with the longest remaining execution time.
2. On equal remaining time, choose the smaller PID.
3. On equal remaining time and PID, use queue/arrival order.
