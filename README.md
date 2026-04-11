# keylogger-cpp-py

A Linux keylogger built in C++ that captures raw keyboard events from /dev/input/ 
and logs them with timestamps. A Python analyzer reads the log and outputs keystroke 
statistics.

## Components
- keylogp1.cpp — captures raw keyboard events using Linux input subsystem
- analyzer.py — reads keylog and displays total keystrokes, most frequent keys, session time

## Requirements
- Linux (tested on Arch)
- g++
- Python 3
- Root access to read /dev/input/

## Usage
# Compile and run keylogger
g++ keylogp1.cpp -o keylogp1
sudo ./keylogp1

# Run analyzer
python analyzer.py

## Disclaimer
Educational project for learning systems programming in C++ and Python.
Not intended for malicious use — the author is not responsible for any misuse of this code.
Note: not all keys are mapped yet.
