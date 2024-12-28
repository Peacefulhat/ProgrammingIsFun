#### What is IP Address ?
- When information is sent via the web, it gets broken down into pieces called data packets. In order to make sure the data gets reassembled in the right place, internet-connected devices have IP address that tell data where to go.
- Every smartphone and desktop computer, for example, has an IP address, but devices like printers and smart speakers also have them because they're connected to the internet and receive data. Data gets routed to a specific IP address by the network, helping it find your device among all the others connected to the internet.
- works on layer 3
- example :
- ![[ipaddress.png]]
- #### Version of IP address
- <span style="color:rgb(255, 0, 0)">I</span><span style="color:rgb(255, 0, 0)">Pv4</span>: in above example picture the inet is showing a decimal number and this number is IPv4 address of a device and its of 32 bits and have 4 groups separated by (.) every 8 bit have can range form 0 to 255.
- 2^32  = 4,294,967,296.
- <span style="color:rgb(255, 0, 0)">IPv6</span>: in the above example picture the inet6 is showing a hexadecimal  number and this number is IPv6 address of a device and its of 128 bits and have 8 groups separated by (:) every group have 16 bits and have range of 0-65,535.
- 2^128: 3.402823669209384E38

IPv6 solves the problem of less IP address . because now a day most of the devices are connected to internet and we run out of the IP address. but still IPv4 is being used .
the thing we use is Some thing called NAT(Network Address Translator).

- <span style="color:rgb(255, 0, 0)">Network Address Translator (NAT):</span> 
- To access the Internet, one public IP address is needed, but we can use a private IP address in our private network. The idea of NAT is to allow multiple devices to access the Internet through a single public address. To achieve this, the translation of a private IP address to a public IP address is required. **Network Address Translation (NAT)** is a process in which one or more local IP address is translated into one or more Global IP address and vice versa in order to provide Internet access to the local hosts. Also, it does the translation of port numbers i.e. masks the port number of the host with another port number, in the packet that will be routed to the destination. It then makes the corresponding entries of IP address and port number in the NAT table. NAT generally operates on a router or firewall

- From the above picture we can see that our IP address starts with 192.x.x.x  its not global IP address, rather is called local IP address or private IP address.
- IP address lie in layer 3 that is router.

#### MAC Address: 
- 
- While routers primarily use IP addresses for routing data between networks, MAC addresses are crucial for communication within the local network. Routers rely on MAC addresses to identify devices on the local network and efficiently forward data packets to their intended destinations.
- A MAC (Media Access Control) address is a unique identifier assigned to network interfaces for communications on a physical network segment. It's a hardware address embedded into the network interface card (NIC) during manufacturing.

Here's an overview of MAC addresses:

1. **Uniqueness**: Each MAC address is globally unique. This uniqueness is ensured by standards organizations and enforced by manufacturers.
    
2. **Format**: MAC addresses are typically represented as six groups of two hexadecimal digits separated by colons, dashes, or no separator at all. For example, `01:23:45:67:89:AB` or `01-23-45-67-89-AB`.
    
3. **Usage**: MAC addresses are used at the data link layer (Layer 2) of the OSI model. They serve as identifiers for devices within the same network segment. When a device wants to communicate with another device on the same network, it uses the MAC address to address the data packets.
    
4. **Addressing**: Unlike IP addresses, which are assigned by network administrators or DHCP servers, MAC addresses are hard coded into the network interface hardware. However, some network protocols, like ARP (Address Resolution Protocol), dynamically map IP addresses to MAC addresses on local networks.
    
5. **Non-routable**: MAC addresses are not routable across different network segments. They are only relevant within the local network segment where communication occurs.
#### DHCP
- Dynamic Host Configuration Protocol, is a network protocol used to automate the process of assigning IP addresses and other network configuration parameters to devices (such as computers, smartphones, and printers) on a network.

- Here's how DHCP works:

1. **IP Address Allocation**: When a device (such as a computer, smartphone, or printer) connects to a network, it needs an IP address to communicate with other devices on the network and access the internet. Instead of requiring manual configuration of IP addresses on each device, DHCP automates this process.
    
2. **DHCP Server**: A DHCP server is a network device or service responsible for managing the assignment of IP addresses and other network configuration parameters. Typically, a router or dedicated DHCP server performs this role.
    
3. **DHCP Discovery**: When a device connects to the network and needs an IP address, it sends out a DHCP discovery broadcast message to the network. This message is addressed to the broadcast IP address (255.255.255.255) and contains a request for DHCP configuration information.
    
4. **DHCP Offer**: When the DHCP server receives the DHCP discovery message, it responds with a DHCP offer message. This message contains an available IP address and other configuration parameters, such as subnet mask, default gateway, and DNS server addresses.
    
5. **DHCP Request**: Upon receiving the DHCP offer, the requesting device sends a DHCP request message to the DHCP server, confirming the IP address assignment and accepting the offered configuration parameters.
    
6. **DHCP Acknowledgment**: Finally, the DHCP server responds with a DHCP acknowledgment message, confirming the IP address assignment and providing the device with the accepted configuration parameters. The device can now use the assigned IP address to communicate on the network.

#### Here's how the process typically works in a cellular network:

1. **Device Connection**: When a mobile device (such as a smartphone) connects to a cellular network, it initiates a connection by sending signals to nearby cellular towers. The device includes its IMEI number as part of the signaling process.
    
2. **Tower Handoff and Authentication**: The signals from the mobile device are received by one or more nearby cellular towers. The cellular tower forwards the signals to the core network infrastructure of the cellular service provider.
    
    - During this process, the network infrastructure authenticates the device using its IMEI number. This helps ensure that only authorized devices can connect to the network.
3. **IP Address Assignment**: Once the device is authenticated and authorized to connect to the network, the network infrastructure assigns an IP address to the device. This assignment is typically done dynamically using DHCP (Dynamic Host Configuration Protocol).
    
    - The DHCP server, which is part of the network infrastructure of the cellular service provider, assigns an available IP address to the device from a pool of addresses.
    - Along with the IP address, the DHCP server may also provide additional network configuration parameters, such as subnet mask, default gateway, and DNS server addresses.
4. **Data Communication**: With the assigned IP address, the mobile device can now communicate over the cellular network. It can send and receive data packets to and from other devices on the network and access services such as internet browsing, email, and messaging.

In summary, while the IMEI number is used for device identification and authentication in cellular networks, the IP address assignment process is typically handled separately by the DHCP server in the network infrastructure of the cellular service provider. The IMEI number is not directly involved in the DHCP process for IP address assignment. 

#### TCP
- TCP operates at the transport layer of the OSI (Open Systems Interconnection) model and the Internet Protocol Suite. The OSI model consists of seven layers, each responsible for specific functions in network communication. Here's where TCP resides in the OSI model:

- **Layer 4: Transport Layer**:
    - The transport layer is responsible for end-to-end communication between devices across a network. It ensures that data is reliably delivered from the source to the destination, handling segmentation, reassembly, flow control, and error detection.
    - TCP operates at the transport layer and provides a reliable, connection-oriented communication service for applications.
    - TCP is one of the primary protocols used at the transport layer, alongside UDP (User Datagram Protocol). While TCP offers reliability and error recovery mechanisms.
     
- How TCP works:

  1. **Connection Establishment**:
    
    - Before data transfer begins, TCP establishes a connection between a client and a server using a three-way handshake:
        1. The client sends a SYN (synchronize) segment to the server, indicating its intention to establish a connection.
        2. The server responds with a SYN-ACK (synchronize-acknowledgment) segment, acknowledging the client's request and indicating its readiness to establish a connection.
        3. The client sends an ACK (acknowledgment) segment back to the server, confirming the connection establishment.
2. **Data Transfer**:
    
    - Once the connection is established, data transfer can occur bidirectionally between the client and server:
        - Data is segmented into smaller units called segments, each with a sequence number for ordered delivery.
        - TCP ensures reliable delivery by incorporating error detection, retransmission of lost segments, and in-order delivery of segments.
        - Flow control mechanisms prevent the sender from overwhelming the receiver with data, ensuring smooth and efficient communication.
3. **Acknowledgment**:
    
    - Upon receiving data segments, the receiver sends acknowledgment messages (ACKs) back to the sender, confirming the receipt of segments.
    - If the sender does not receive an ACK for a particular segment within a specified timeout period, it retransmits the segment to ensure reliable delivery.
4. **Flow Control**:
    
    - TCP implements flow control mechanisms to manage the rate of data transmission between the sender and receiver.
    - The receiver advertises its available buffer space through TCP window size negotiation, allowing the sender to adjust its transmission rate accordingly.
5. **Congestion Control**:
    
    - TCP includes congestion control mechanisms to prevent network congestion and ensure fair bandwidth utilization.
    - Congestion control algorithms adjust the transmission rate based on network conditions, such as packet loss and round-trip time, to optimize network performance.
6. **Connection Termination**:
    
    - When data exchange is complete, TCP terminates the connection using a four-way handshake:
        1. The client sends a FIN (finish) segment to the server, indicating its intention to close the connection.
        2. The server responds with a FIN-ACK segment, acknowledging the client's request to close the connection.
        3. The server then sends its own FIN segment to the client, indicating its readiness to close the connection.
        4. Finally, the client responds with a FIN-ACK segment, confirming the closure of the connection.

By providing reliable, connection-oriented communication, TCP ensures the delivery of data with integrity and order, making it suitable for a wide range of applications and protocols on the internet and local networks.

#### UDP
- UDP (User Datagram Protocol) works by providing a simple, connectionless communication service for sending and receiving datagrams (packets) between devices over a network. Here's an overview of how UDP operates:

1. **Packet Structure**:
    
    - Each UDP packet, or datagram, consists of a header and payload:
        - Header: The UDP header includes source and destination port numbers to identify the sending and receiving processes on the source and destination devices. It also includes a length field specifying the total length of the datagram (header + payload) and an optional checksum field for error detection.
        - Payload: The payload contains the actual data being transmitted, such as application data, commands, or queries.
2. **Connectionless Communication**:
    
    - UDP operates in a connectionless manner, meaning that it does not establish a connection before sending data. Each UDP packet is treated independently, and there is no session setup or teardown process.
    - This connectionless nature makes UDP lightweight and efficient, as there is no overhead associated with connection establishment, sequence numbering, or acknowledgment.
3. **Unreliable Delivery**:
    
    - UDP does not guarantee the delivery of packets or the order of delivery. Packets may arrive at the destination out of order, be duplicated, or be lost without notification.
    - Because UDP lacks reliability mechanisms such as acknowledgment, retransmission, and flow control, it is susceptible to packet loss, network congestion, and other factors that may impact delivery.
4. **Low Overhead**:
    
    - UDP has minimal overhead compared to other transport protocols like TCP because it does not include mechanisms for reliability, connection establishment, or flow control. This makes UDP more lightweight and efficient for certain types of communication.
5. **Usage Scenarios**:
    
    - UDP is commonly used in applications where real-time performance and low overhead are more important than guaranteed delivery and reliability. It is suitable for scenarios where occasional packet loss or out-of-order delivery can be tolerated, such as multimedia streaming, online gaming, VoIP (Voice over Internet Protocol), DNS (Domain Name System) queries, and SNMP (Simple Network Management Protocol) for network monitoring.

In summary, UDP provides a lightweight, connectionless communication service that is suitable for applications where real-time performance and low overhead are critical. While UDP does not provide reliability guarantees like TCP, it offers simplicity and efficiency, making it well-suited for certain types of communication on networks.
- Same a TCP works in layer 4.

#### DNS
- Is mapping a name to IP address
#### Common Ports and Protocols
- TCP
   - FTP: (21)
   - SSH: (22):encrypted 
   - Telnet:(23):not encrypted both ssh and telnet are same
   - SMTP:(25)
   - DNS:(53)
   - HTTP:(80)/HTTPS(44)
   - POP:(110)
   - SMB:(139,445)
   - IMAP:(143)
- UDP
	- DNS:(53)
	- DHCP:(67,68)
	- TFTP:(69)
	- SNMP:(161)
### OSI Model
- Physical layer: Ethernet cable , wifi, etc.
- data link layer: switching , Mac addresses.
- Network layer: IP addresses , routing.
- Transport layer: Tcp/ip.
- Session: session management.
- Presentation layer: wmv, jpeg, mov etc.
- Application layer: HTTP, SMTP.

troubleshot goes from physical to application layer.

#### Subneting
- dividing a bigger network into a smaller network
- 