
- <span style="color:rgb(255, 123, 0)">Application Software</span> performs specific task for the user.
- <span style="color:rgb(0, 176, 80)">System Software</span> operates and controls the computer system and provides a platform to run application software.
#### <span style="color:rgb(255, 123, 0)">Why</span> operating <span style="color:rgb(0, 176, 80)">system ? </span>
- To run an program we need 
- CPU , memory, GPU ,Disk 
 ![[WhyOS.png]]
 - Lets say you want to play game , Elden Ring
 - Because of Facebook taking all the resources , Elden ring will never going to get resources and Elden ring  will not get started 
 - system will go in a hanged state.
![[WhyOS2.png]]
- From the above picture we can say that every program is not going have all the resources for themselves .
- first they have to make a request to operating system and then they can run on system .
- The operating system is going to provide them with necessary resources.
- so, that all programs can run.
- Here Operating system is acting like a <span style="color:rgb(255, 123, 0)">Reso</span><span style="color:rgb(255, 255, 255)">urce</span> <span style="color:rgb(3, 106, 1)">Manager</span>.

<span style="color:rgb(255, 123, 0)">Here Operating system</span> is acting<span style="color:rgb(0, 176, 80)"> l</span><span style="color:rgb(0, 176, 80)">ike a interface.</span>
Example:
![[WhyOS3.png]]
- From above example of bank its clear, 
- the Green Dot is customer of sbi bank and he want to withdraw some money.
- The makes a request to White Circle which is sbi worker , he check for money.
- if it finds money in the bank Money Store.
- it give it to customer.
- Here Sbi worker is working like an interface and <span style="color:rgb(3, 106, 1)">provinding</span> <span style="color:rgb(3, 106, 1)">servive</span> but not letting the customer to visit money store.

#### <span style="color:rgb(255, 123, 0)">Bulky</span> App<span style="color:rgb(0, 176, 80)"><span style="color:rgb(3, 106, 1)">lications</span></span>
- In case if we have no operating system .
- if we want to write code for some application we have to write code for 
- first the code for application
- second for how our application is going to utilize resources .
- we are going to write same code repeatedly and making our program bulky and not easy to maintain. 
- and we do violate the DRY principle.
- With Operating System we don't need write code for resource management and it can be manage by Operating System and we just have to focus on writing application  code.
- Making our application easy to maintain 

#### <span style="color:rgb(255, 123, 0)">Isolation</span> and <span style="color:rgb(3, 106, 1)">Protection</span>
![[WhyOS4.png]]![[WhyOS5.png]]

#### What is an Operating System
- An operating system is a piece of software that manages all the resources of a computer system , both hardware and software , and provides an environment in which the user can execute his/her programs in convenient and efficient manner by hiding underlying complexity of the hardware and acting as a resource manager.
#### Functions of operating system
- Access to the computer hardware.
- interface between the user and the computer hardware.
- Resource management.
- Hides the underlying complexity of the hardware.
- facilitates execution of application programs by providing isolation and protection. 

#### Basic Diagram
![[BasicDiagramComputerSystem.png]]

#### Goals of Operating system(process based goals)

- Maximum CPU utilization.
- Minimize Process Starvation.
- High priority Process execution.
[[TypesOfOperatingSystem]]