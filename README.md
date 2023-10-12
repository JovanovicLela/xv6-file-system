# xv6-file-system
> Modification of xv6 operating system

The goal was to modify xv6 system to support the following file system functionalities: 

* **creating, reading, writing, editing and deleting large files using double indirect pointers in the inode structure**
* **encryption of the content of certain files on the disk**

In addition to these file system functionalities, there is also an implementation of the following system calls and user programs:
* System calls:
  * **int setkey(int key);**
  * **int setecho(int echo);**  
  * **int encr(int fd);**
  * **int decr(int fd);**
* User programs:
  * **setkey**
  * **encr**
  * **decr**
  * **blockwriter**   








