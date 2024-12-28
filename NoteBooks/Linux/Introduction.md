###### Sudo(super user do)
- lets us to run commands as higher privileged user
- it allow us to run commands or view the file or other stuff that are not allowed for normal user.
- sudo cat /etc/shadow
command : sudo su - : let to switch to roots
- anything that start with (.) is hidden 

> [!NOTE] Link
>explainshell.com
#### File navigation (terminal)
- cd -> change dir.
- cd ..-> to go back to previous directory .
- ls -> list dir in current directory.
- mkdir -> used to make directory.
- rmdir -> remove directory.
- ls -al -> list all in the current directory.
- echo ' hi' -> print hi on screen.
- echo 'Hi' > test.txt -> will put Hi on test.txt
- cp test.txt Downloads -> copy test.txt to Download folder
- rm test.txt -> will remove test.txt file
- mv test.txt Download-> will move the test.txt to Download.
passwd: to add password 

#### User previlage
drwxr-x-x : d -> directory  x->execute , r->read, w-> write
chmod -> to change permission eg : chmod+(x,w,r) filename
chmod 777 filename -> will give all permission to all users



#### adding user (arch linux)
sudo useradd -m   nameofuser
su username -> to swith to another user
cat /etc/passwd
root:x:0:0 -> zero means that they are the heigest user on the machine.
cat /etc/shadow -> contains the actual password and other things used by sytem.
cat /etc/sudoers ->which are user that are in sudoers file

#### Networking commands
ip a -> show details of netwoking
arp -a -> which ip is mapped to which mac address. or ip n
ip r  -> ip routing or route
ping-> to check if machine is active or not if icmp is active
netstat -> is used to idenitify what open ports and severcie avilable
