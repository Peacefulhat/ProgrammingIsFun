Data communication are the exchange of data between two nodes via some form of link(transmission medium) such as cable.

#### Data flow

##### Simplex:
- Communication is always unidirectional.
- one device can transmit and the other device will receive.
- Example: keyboard , monitor etc.

##### Half Duplex:
- communication is in both direction but not at the same time.
- if one device is sending, the other can only receive and vice versa.
- Example: walki-talkie.
##### Full Duplex:
- Communication is in both directions simultaneously.
- Device can send and receive at the same time.
- Example: Telephone line.


##### Protocols
- protocol=Rule.
- All communication schemes will have the following things in common:
	- source or sender.
	- destination or receiver
	- channel or media.
- Rules or protocols governs all the methods of communications.
- it is set of rules that governs data communication.
 - Protocol determines:
	 - What is communicated?
	 - How it is communicated?
	 - When it is communicated?


> [!NOTE] If there are no protocols
> imbalance of communication.
> or communication becomes useless.like one device is sending data that other device is not capable of handling it or its not able to under stand what kind of data is being sent.

#### Protocols - Human Communication
- Protocols are necessary for human communication and include:
- An Identified sender and receiver
- common language and grammar
- speed and timing of delivery
- confirmation or acknowledgement requirement.

#### Protocols - Network communication
#### or Element of a Protocol
- Protocol used in networks communications also define:
	- message encoding
	- Message formatting and encapsulation
	- Message timing
	- Message size
	- Message delivery options


##### Message Encoding:
![[Message_Encoding.png]]


> [!NOTE] Why Encoder?
> Because we have wired/wireless medium,message source need to know what kind of medium is available for data propagation ,because of that we have to convert data into appropriate format so that it can be propagated properly between devices.(send between devices)

##### Message formatting and encapsulation:
- Agreed format.
- Encapsulate the information to identify the sender and receiver correctly.
- we add some additional information to the data to identify sender and receiver
##### Message Size:
- Human breaks long messages into smaller parts or sentences.
- like wise, long messages must also be broken into smaller pieces to travel across a network.
- or there might be a case that media is not capable of handling big message. for cases like this we need to break the message into smaller parts.
##### Message Timing:
- flow control (to control the rate of data exchange).
	- some time there might be a case that sender is very fast, and receiver is slow , sender can send data fast , and receiver is not able to keep up with it.
	- if there is no flow control send will keep on sending data and receiver will not be able to receive the data.
	- so the the communication becomes useless in this case.
	- 
- Response timeout
	- some kind of acknowledgement, to ensure that the data reached its final destination, and it does not get lost in the process.
	- protocol must ensure that how much time sender have to wait to receiver the acknowledgement , before sender resend the data.
##### Message Delivery options
- Uni-cast
	- one sender one receiver , sender will send data to one receiver on the network.
- Multicast
	- When sender sends a data to set of receivers on a network but not all.
- Broadcast
	- When a sender sends data to all the nodes in a network.

> [!NOTE] Note
> When sender have higher capabilities of sending data it gets slowed down by the message timing approach to maintain the flow of communication between the sender and receiver
> example: like when server process data slow even though your internet speed is good.

#### Peer to Peer Network
- Every node is called peer 
-  Connect directly to share resources and communicate without needing a central server.
- Each peer can both act as client and server.
- They are in equal in level ,meaning there no one is superior and no one is inferior.
- Problem with this is that no one is working like an administrator to watch over the network,communication.
- suitable for smaller applications.
- Not Scalable.

#### Client server network
- We have a centralized administration.
- Follow master-slave architecture.
- Central sever manages.
- Request-response model.
- Server may be overloaded.

#### Components of Computer Network
- Node
- Media
- Services
##### Nodes
- A node can send ,receive and both send and receive the data.
- End Nodes (End devices)
	- are the nodes that is going to be starting point in the communication or ending point in communication.
	- Example:computer, security cameras, bar code scanner etc.
- Intermediary Nodes
	- are the node that just forward data from one node to another node in a network.
	- place in between End Nodes.
	- Example: switches , Bridges, Routers etc.

##### Media(Link)
- carries the data from one side to other.
- can be wired medium(guided medium), or wireless medium(unguided medium).
- Example:(wired medium)
	- Ethernet straight through cable(data is carried through electrical signals)
	- Ethernet cross over cable.(data is carried through electrical signals)
	- Fiber optic cable.
	- Coaxial cable
	- USB cable.

> [!NOTE] Ethernet straight-through cable
> If we want to connect different devices we have to go for this cable.

>[!Note] Ethernet crossover cable
> If we want to connect devices of same type,like router, switches, computer, etc. we have to go with Ethernet crossover cable.

##### Wireless media
- signals are converted in waves.
- Example:
	- Infrared
	- Radio
	- Microwaves(Example: cellular system)
	- satellite(Example: Long range communication)
#### Services
- e-mail.
- storage services.
- file sharing.
- instant messaging.
- world wide web.


#### Classification of computer network
- LAN(local area network)
	- A small network is said to be a local area network.
	- have restricted to a limited area.
	- A local area network is a computer network that interconnects computers within a limited area such as a residence, school, laboratory, university campus or office building.
- we can set up LAN in two ways:
	- Wired LAN(Example:Ethernet-Hub,switch)
	- Wireless LAN(Example:WI-FI)

MAN(metropolitan are network)
- metropolitan area network (MAN) is a computer that interconnects user with computer resources in a geographic region of the size of a metropolitan area(city.) 
- MAN-Devices.
	- Switches/Hub.
	- Routers/Bridges.	
>[!NOTE] Note
>Routers or Bridges are needed o connect two local area network.

WAN(Wide area network)
- A wide area network is telecommunication network that extends over a larger geographical area for the primary purpose of computer networking.
