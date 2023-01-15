#include "s21_string.h"

// Ошибки strerror на маке всего 107 ошибок, когда код ошибки > 107 или < 0 то
// выводиться Unknown error: <номер несуществующего кода ошибки>

/*
 Ошибки MAC
Undefined error: 0
Operation not permitted
No such file or directory
No such process
Interrupted system call
Input/output error
Device not configured
Argument list too long
Exec format error
Bad file descriptor
No child processes
Resource deadlock avoided
Cannot allocate memory
Permission denied
Bad address
Block device required
Resource busy
File exists
Cross-device link
Operation not supported by device
Not a directory
Is a directory
Invalid argument
Too many open files in system
Too many open files
Inappropriate ioctl for device
Text file busy
File too large
No space left on device
Illegal seek
Read-only file system
Too many links
Broken pipe
Numerical argument out of domain
Result too large
Resource temporarily unavailable
Operation now in progress
Operation already in progress
Socket operation on non-socket
Destination address required
Message too long
Protocol wrong type for socket
Protocol not available
Protocol not supported
Socket type not supported
Operation not supported
Protocol family not supported
Address family not supported by protocol family
Address already in use
Can't assign requested address
Network is down
Network is unreachable
Network dropped connection on reset
Software caused connection abort
Connection reset by peer
No buffer space available
Socket is already connected
Socket is not connected
Can't send after socket shutdown
Too many references: can't splice
Operation timed out
Connection refused
Too many levels of symbolic links
File name too long
Host is down
No route to host
Directory not empty
Too many processes
Too many users
Disc quota exceeded
Stale NFS file handle
Too many levels of remote in path
RPC struct is bad
RPC version wrong
RPC prog. not avail
Program version wrong
Bad procedure for program
No locks available
Function not implemented
Inappropriate file type or format
Authentication error
Need authenticator
Device power is off
Device error
Value too large to be stored in data type
Bad executable (or shared library)
Bad CPU type in executable
Shared library version mismatch
Malformed Mach-o file
Operation canceled
Identifier removed
No message of desired type
Illegal byte sequence
Attribute not found
Bad message
EMULTIHOP (Reserved)
No message available on STREAM
ENOLINK (Reserved)
No STREAM resources
Not a STREAM
Protocol error
STREAM ioctl timeout
Operation not supported on socket
Policy not found
State not recoverable
Previous owner died
Interface output queue is full
*/

// Ошибки strerror на linux всего 131 ошибка, когда код ошибки > 131 или < 0 то
// выводиться No error information

/*
    Ошибки Alpine Linux
0 --> No error information
1 --> Operation not permitted
2 --> No such file or directory
3 --> No such process
4 --> Interrupted system call
5 --> I/O error
6 --> No such device or address
7 --> Argument list too long
8 --> Exec format error
9 --> Bad file descriptor
10 --> No child process
11 --> Resource temporarily unavailable
12 --> Out of memory
13 --> Permission denied
14 --> Bad address
15 --> Block device required
16 --> Resource busy
17 --> File exists
18 --> Cross-device link
19 --> No such device
20 --> Not a directory
21 --> Is a directory
22 --> Invalid argument
23 --> Too many open files in system
24 --> No file descriptors available
25 --> Not a tty
26 --> Text file busy
27 --> File too large
28 --> No space left on device
29 --> Invalid seek
30 --> Read-only file system
31 --> Too many links
32 --> Broken pipe
33 --> Domain error
34 --> Result not representable
35 --> Resource deadlock would occur
36 --> Filename too long
37 --> No locks available
38 --> Function not implemented
39 --> Directory not empty
40 --> Symbolic link loop
41 --> No error information
42 --> No message of desired type
43 --> Identifier removed
44 --> No error information
45 --> No error information
46 --> No error information
47 --> No error information
48 --> No error information
49 --> No error information
50 --> No error information
51 --> No error information
52 --> No error information
53 --> No error information
54 --> No error information
55 --> No error information
56 --> No error information
57 --> No error information
58 --> No error information
59 --> No error information
60 --> Device not a stream
61 --> No data available
62 --> Device timeout
63 --> Out of streams resources
64 --> No error information
65 --> No error information
66 --> No error information
67 --> Link has been severed
68 --> No error information
69 --> No error information
70 --> No error information
71 --> Protocol error
72 --> Multihop attempted
73 --> No error information
74 --> Bad message
75 --> Value too large for data type
76 --> No error information
77 --> File descriptor in bad state
78 --> No error information
79 --> No error information
80 --> No error information
81 --> No error information
82 --> No error information
83 --> No error information
84 --> Illegal byte sequence
85 --> No error information
86 --> No error information
87 --> No error information
88 --> Not a socket
89 --> Destination address required
90 --> Message too large
91 --> Protocol wrong type for socket
92 --> Protocol not available
93 --> Protocol not supported
94 --> Socket type not supported
95 --> Not supported
96 --> Protocol family not supported
97 --> Address family not supported by protocol
98 --> Address in use
99 --> Address not available
100 --> Network is down
101 --> Network unreachable
102 --> Connection reset by network
103 --> Connection aborted
104 --> Connection reset by peer
105 --> No buffer space available
106 --> Socket is connected
107 --> Socket not connected
108 --> Cannot send after socket shutdown
109 --> No error information
110 --> Operation timed out
111 --> Connection refused
112 --> Host is down
113 --> Host is unreachable
114 --> Operation already in progress
115 --> Operation in progress
116 --> Stale file handle
117 --> No error information
118 --> No error information
119 --> No error information
120 --> No error information
121 --> Remote I/O error
122 --> Quota exceeded
123 --> No medium found
124 --> Wrong medium type
125 --> Operation canceled
126 --> Required key not available
127 --> Key has expired
128 --> Key has been revoked
129 --> Key was rejected by service
130 --> Previous owner died
131 --> State not recoverable
*/