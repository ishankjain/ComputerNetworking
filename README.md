# ComputerNetworking
Lab assignments on computer networking




Assignments

01-01-2019: Assignment 1

Experiment with the following Linux Networking Commands specifying different important flags: ifconfig, route, netstat, ping, arp, traceroute, tcpdump, xxd, host, nslookup, dig, nmap etc.
Use vi editor, gcc compiler, makefile and gdb debugger in developing these programs.
Write a program in C/C++ to display the Four Network parameters (IPv4 Address, Netmask, Default Gateway, DNS Server), MAC address by using the following  commands / functionalities: system, ifconfig, STDOUT redirection, systemd-resolve --status, nmcli device show wlo1
Create and handle Processes in Linux operating system. Make use of fork, sleep, wait, exit, getpid, getppid system calls and ps, kill Linux commands. 
Design and implement a simple, interactive shell program that prompts the user for a command, parses the command, and then executes it with a child process by looking at PATH environment variable. 
Implement running of command in background also. Properly handle Ctrl-c, Ctrl-d signals.


08-01-2019: Assignment 2

Wireshark Network Protocol Analyzer is a tool for capturing, displaying, and analyzing
the frames, packets, and messages that are exchanged in a network. Reading material for attempting this exercise is provided at the end of this assignment.

Part 1: Install Wireshark. Run it to capture packets. Start a web session (visit some website after starting wireshark). Analyse the captured packets for various information like: MAC Address, IP Address, Checksum, Port Number and many other related information from headers of various layers. Repeat the above for PING and TRACEROUTE linux commands
also. Learn to apply filters. Save the captured packets in a dump file in pcap format.

Part 2: Open the pcap dump file (a binary file) using C program. Read the PCAP file structure. Retrieve the header information from the binary file and show it on the display.
Part 3: Write a C program to compute checksum. Use the information captured by Wireshark to verify the checksum. Checksum computation algorithm is as follows:

Part 4: Use the libpcap library to capture the packets using a C program. Use various functions of PCAP library to retrieve information of various layer’s header.

Reading Material:
This Lab exercise is based on wireshark. Again you have to study a lot for this and program also. But you should not waste time on Internet for searching. I am providing you very nice links here in the email. There are ready made programs also but you need to understand them very well.
This Lab is divided into multiple parts:
 
Part 1: Installation of Wireshark. Run it to capture packets. Start a web session (visit some website after starting wireshark). Analyse the captured packets for various information like: MAC Address, IP Address, Checksum, Port Number and many other related information from headers of various layers. Learn to apply filters. Save the captured packets in a dump file in pcap format.
http://www.howtoforge.com/network-analysis-with-wireshark-on-ubuntu-9.10

Part 2: Open the pcap dump file (a binary file) using C program. Read the PCAP file structure. Retrieve the header information from the binary file and show it on the display.
 
PCAP file Format
http://wiki.wireshark.org/Development/LibpcapFileFormat
 
Binary File I/O in C
http://www.cprogramming.com/tutorial/cfileio.html
 
Part 3: Write a C program to compute checksum. Use the information captured by Wireshark to verify the checksum. IP header is to be stored in a text file using C program. This text file will be used to compute checksum and verification. Checksum algorithm given in the Peterson and Davie Textbook. We'll study it when the related topics are covered.
 
Part 4: Use the libpcap library to capture the packets using a C program. Use various functions of PCAP library to retrieve information of various layer's header.
 
PCAP Tutorials (Packet Capturing with libpcap library)
 
Any one of the following links you can use to learn the packet capturing using libpcap library
 
http://urli.st/3ur-The-Geek-Stuff/itw-How-to-Perform-Packet-Sniffing-Using-Libpcap-with-C-Example-Code
 
http://www.linuxforu.com/2011/02/capturing-packets-c-program-libpcap/
 
http://www.tcpdump.org/pcap.htm
 
http://yuba.stanford.edu/~casado/pcap/section1.html
http://yuba.stanford.edu/~casado/pcap/section2.html
http://yuba.stanford.edu/~casado/pcap/section3.html
http://yuba.stanford.edu/~casado/pcap/section4.html
 
http://undergraduate.csse.uwa.edu.au/units/CITS3231/reading/libpcap-programming.pdf

Internet Checksum Algorithm





22-01-2019: Assignment 3 - Socket Programming

(a)   	Write a simple conversational program in C using sockets. The program should be possible to start as client or as server. The server should notify about a call from the client's host, by giving its name, and prompt for reply. After that a half-duplex conversation will begin, both ends display received messages and prompt for reply. The conversation ends by a host sending a "close" message.

(b)   	Write a simple Server and Client program using the socket programming on Linux (UNIX) that can simulate the functionality of a real FTP Server and Client.
Client Specifications: Your client should accept as parameters from the command line: 1) the IP Address and 2) the port number of the server. The order of the parameters in the command line should be in the order mentioned above. If, either, there is less number of command line arguments or are not in required order, your program must exit after displaying appropriate message. Client should show a prompt like
your_roll_number_ftp-client > on which any of the following commands may be issued so as to provide usual ftp client’s functionalities:
s_ls                          	to list the files in the current directory on the server side.
s_pwd                      	to list the current directory on the server side.
s_cd <dir_name>   		to change the directory on the server side.
c_ls                          	to list the files in the current directory on the client side.
c_pwd                      	to list the current directory on the client side.
c_cd <dir_name>   		to change the directory on the client side.
put <file_name>     		to send a file from the client to the server.
get <file_name>     		to receive a file from the server to the client.
quit                          		to close the client program.
If any of the command cannot be completed successfully, proper error message must be displayed. The client should receive messages from the server and print all lines to STDOUT until no more lines are received. In case of file transfer command, instead of displaying the contents of the file on the STDOUT, these should be saved in the current directory with the same file name as on the server.

Server Specifications: Your server should accept a single parameter from the command line the port number to listen to. The server should execute the commands received from the server and send their output to the client. For the get command, after receiving the name of the file from the client, if the file cannot be opened in the current directory, then the server should return appropriate message to client so that it may print “File not found” error message. If the file is opened successfully, then the server should send all the characters of the file to the client until the end of the file is reached. After sending the file, the server should close the file and then continue to listen for more client requests, in an iterative fashion.
Server should print out appropriate informative messages as it executes. You should do appropriate error detection for the TCP socket calls. You may test to see your code runs correctly by performing a "diff" on the original file and the one that has been received via
 
(c)   	LAN CHATTING APP - Write a server program that allows chatting among multiple clients. Each Client must have a 3-digit number as user_code and 1 digit number as group_code (specified as command line arguments while executing client program) and these code are informed to all other clients. Any Client recognize the other clients by this user_code only. When a new client joins, server provides it the list of all available other clients (client’s user_code, group_code) and other clients are also updated with the newly joined client. When some client does not participate in chatting for some amount of time (configurable - say 30 sec or 1 min or 2 minutes), it is removed from active client list by the system and all active clients are notified about this event. Server will pass a message from some source client to either some designated destination client or clients having same group_code or all clients active in the system. Every client will send acknowledgement for the received message to the server. Server will inform the source client about status (successful / unsuccessful) of transmission of message.

Reference Material:
Beej's Guide to Network Programming Using Internet Sockets
https://beej.us/guide/bgnet/

Programming in C - UNIX System Calls and Subroutines using C
https://users.cs.cf.ac.uk/Dave.Marshall/C/

UNIX Network Programming - W. Richard Stevens

29-01-2019: Assignment 3 - Socket Programming contd..

(d) Remote Administration - Develop Clients Server program using sockets to execute administration from remote of computers in your LAN for following functionalities
Get list of IP Addresses of all computers 
Get list of all users logged in presently at different machines
Get the information of user logged in at a specific machine
Mark the attendance of students from their log in record available at different machine
Get the user data from remote computers at random intervals to detect the abnormal behaviour of users logging to the computers
Shutdown the remote computer
Any other functionality you wish to implement from your end


05-02-2019: Assignment 4 Discrete Event Simulations

Reading Material: 
http://www.cs.fsu.edu/~baker/realtime/restricted/notes/simulation.html

https://simpy.readthedocs.io/en/latest/

http://pages.cpsc.ucalgary.ca/~carey/CPSC601.08/examples/mm1.c.txt

http://web02.gonzaga.edu/faculty/burchn/R_files/Miscellaneous/queueing_theory_MM1.html


Write programs to simulate (i) Simple ALOHA and (ii) Slotted ALOHA in C/C++.
Write programs to simulate (i) Simple ALOHA and (ii) Slotted ALOHA using SimPy.

Simulate above protocol and answer the following simple questions about ALOHA based random access methods:
1) What is the behavior of Simple ALOHA  & Slotted ALOHA throughout as the load of the network increases i.e. Compute Channel throughput S with different value of the loading G.
2) What is the value of the maximum throughput and prove the obtained value by working on the theoretical network throughput formula. We know that slotted ALOHA has a better throughput performance than ALOHA protocol. Verify by your simulation.


12-02-2019: Assignment 5

Simulate the various data link protocols using multiple processes. There will be three processes - Sender, Receiver, Channel. We’ll use Message Queue mechanism of System V IPC (Inter process communication) for simulation. Various system calls to be used are ftok, msgget, msgctl, msgsnd, msgrcv…….
 
There may be two types of Channels process: Error free and Erroneous. Error free channel will pass all messages received from Sender to Receiver and all ACK from Receiver to Sender. However, Erroneous channel will drop message….. randomly (generate random number between 0 to 1 or 1 to 100 and if random number generated is below 0.3 or 30, drop the message).

Take inputs from user - the Bandwidth of the channel, the Length of frame,and length of channel. Force the user to enter valid range of values. 

Use the actual CPU time for marking various events (sending and receiving of frame). Based on computer’s clock find out the Tframe and Tpropagation. Send the frame (data / ACK) from Channel process to Receiver (Sender) process after delay equal to the Tpropagation.
