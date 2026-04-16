# Keystroke Logging & Analysis (Educational Project)

## Overview
This project demonstrates how keystroke logging works on Linux systems using both low-level (C++) and high-level (Python) approaches.

The C++ component captures raw keyboard events directly from `/dev/input/`, while the Python script analyzes the generated logs to extract usage patterns such as keystroke frequency and session duration.

The goal of this project is to understand input capture mechanisms and explore their security implications.

---

## Components
- **keylogp1.cpp** — Captures raw keyboard events using the Linux input subsystem  
- **analyzer.py** — Processes logs and outputs:
  - Total keystrokes  
  - Most frequent keys  
  - Session duration  

---

## Key Concepts Demonstrated
- Low-level input handling via Linux device files  
- System-level (C++) vs scripting-level (Python) approaches  
- Basic behavioral analysis of keystroke data  

---

## Security Considerations
Although this project focuses on implementation, similar techniques are used in malicious software. Such behavior can be detected through:

- Monitoring access to `/dev/input/` devices  
- Identifying unusual background processes  
- Detecting high-frequency logging activity  
- Using system monitoring tools  

---

## Requirements
- Linux (tested on Arch)
- g++
- Python 3
- Root access (required to read `/dev/input/`)

---

## Usage

### Compile and run keylogger
```bash
g++ keylogp1.cpp -o keylogp1
sudo ./keylogp1