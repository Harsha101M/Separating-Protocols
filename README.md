# Separating-Protocols
A C++ tool for analyzing and filtering network traffic based on application layer protocols, packet size, and IP addresses. Processes Wireshark captures to provide insights into protocol-specific communication patterns.

## Features
- Filter traffic by application layer protocols (HTTP, SMTP, FTP, DNS, etc.)
- Filter by source and destination IP addresses
- Filter packets by size range
- Process raw Wireshark captures
- Interactive command-line interface

## Requirements
- C++ compiler with STL support
- Wireshark (for capturing traffic)
- Input file in text format with columns:
  - Number
  - Time
  - Source IP
  - Destination IP
  - Protocol
  - Length

## Usage
1. Capture traffic using Wireshark and save as text
2. Compile the program:
```bash
g++ Separate_Protocols.cpp -o traffic_analyzer
```

3. Run the analyzer:
```bash
./traffic_analyzer
```

4. Choose from available options:
- Filter by application layer protocol
- Filter by IP addresses
- Filter by packet size
- Reset filters

## Example
```
---CHOOSE YOUR OPTION---
0. Exit
1. Filter based on Application Layer Protocol
2. Filter based on IP addresses
3. Filter according to packet size
4. Reset Filters
```
