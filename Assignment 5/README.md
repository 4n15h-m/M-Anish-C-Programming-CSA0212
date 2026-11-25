# C Programming Assignment 5 (CO5)
## Campus Event Log and Monitoring System

This repository contains the C programs shown in the CO5 assignment PDF, arranged as separate source files for GitHub submission.

### Contents

| File | Topic |
|---|---|
| `01_file_create_append_read.c` | Create, write, append and read a text file |
| `02_count_event_records.c` | Count event records |
| `03_search_and_filter_events.c` | Search by event ID and filter LAB records |
| `04_posix_threads.c` | Run event counting and latest-event tasks using POSIX threads |
| `05_mutex_counter.c` | Protect a shared counter using a mutex |
| `06_pipe_ipc.c` | Parent-child communication using an anonymous pipe |
| `07_process_management.c` | `fork()`, `getpid()`, `getppid()` and `wait()` |
| `08_file_descriptor_write.c` | File descriptor operations using `open()`, `write()` and `close()` |
| `09_exec_demo.c` | Demonstrate `fork()` and the `exec` family |
| `10_tcp_server.c` | TCP server on localhost, port 8080 |
| `11_tcp_client.c` | TCP client connecting to localhost, port 8080 |
| `12_time_based_filter.c` | Count events between two HH:MM timestamps |

### Requirements

- Linux operating system
- GCC compiler
- POSIX threads support for the thread and mutex examples

### Compile and run

Open a terminal in the `examples` directory.

```bash
gcc 01_file_create_append_read.c -o file_io
./file_io

gcc 02_count_event_records.c -o count_events
./count_events

gcc 03_search_and_filter_events.c -o search_events
./search_events

gcc 04_posix_threads.c -o threads -pthread
./threads

gcc 05_mutex_counter.c -o mutex_counter -pthread
./mutex_counter

gcc 06_pipe_ipc.c -o ipc
./ipc

gcc 07_process_management.c -o process
./process

gcc 08_file_descriptor_write.c -o fd_write
./fd_write

gcc 09_exec_demo.c -o exec_demo
./exec_demo

gcc 10_tcp_server.c -o server
gcc 11_tcp_client.c -o client
```

For the TCP demonstration, run `./server` in one terminal first, then run `./client` in a second terminal.

```bash
gcc 12_time_based_filter.c -o time_filter
./time_filter
```

### Important notes

1. The file-based programs use `events.txt` in the current working directory. Run `01_file_create_append_read.c` first to create a sample file.
2. The server and client communicate only through `127.0.0.1` on port `8080`.
3. These are individual demonstration programs corresponding to the assignment's tasks. The PDF describes a modular integrated architecture, but does not provide a complete single integrated application source code.
4. The time-filter example assumes zero-padded `HH:MM` timestamps on the same day, as stated in the assignment.
5. The TCP examples demonstrate a basic single-client exchange. A production implementation would need robust message framing and loops for partial sends/receives.
