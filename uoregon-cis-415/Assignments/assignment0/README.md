###CIS 415 - Operating Systems, Spring 2016
####Assignment 0 - Piazza, VM, and Bitbucket

We will be using Piazza for discussions and announcements. You can post questions and comments to the Piazza site anonymously, but I strongly encourage you to start or join open discussioss. Note that if you pose a question by email to Prof Sventek or the GTF, you will be asked to post it on Piazza, and we will answer it there. Take advantage of the ability to post anonymously if that makes you more comfortable. Enroll in the Piazza site

We will be using a virtual machine image in the programming assignemts that we will run under Virtual Box. A 64-bit Linux image is located inside the following compressed folder:

    /cs/groupprojects/cis415/arch-lts_1.tgz

If your system cannot handle a 64-bit image, a 32-bit Linux image is located inside the following compressed folder:

    /cs/groupprojects/cis415/arch-lts-32_1.tgz

After uncompressing the .tar file, you'll find the following virtual machine image file:

    arch-lts_1.vmdk
OR

    arch-lts-32_1.vmdk

If you plan to use your own personal computer for projects, you can download the .tgz file to your machine or a portable external hard drive, such as a USB stick. Note, these images are about 1.7GB and may be too big for your personal CIS directory.

We will be using VirtualBox for running the virtual machine image. VirtualBox is available on computers in both Klamath Hall, Room 26, and Deschutes Hall, Room 100. To use VirtualBox, do the following:
* Launch VirtualBox on a machine in Room 100 (or use your own machine)
* Open a terminal session and type in the command 'vboxmanage modifyhd < image_file_path > --type immutable'
* Create a 'New' virtual machine, name it 'cis415', and select 'Linux' and 'Arch Linux 64 Bit'
* Accept the default memory size (typically 512MB)
* When prompted in the setup, load the virtual machine image above (.vmdk file) into VirtualBox
* The 'cis415' VM is now ready. Click 'Start' and a guest Arch Linux OS session will commence
* Log in (username = cis415, password = cis415)
* You are now ready to use your virtual computer

For detailed instructions on how to install Virtual Box or set up your first VM, refer to Chapter 1 in the VirtualBox manual.

In this course we will be using Bitbucket and git version control for all coding assignments and projects. To configure your Bitbucket git repository for this course, do the following:

* Create a Bitbucket account (if you don't already have one)
* Create a new git repository named uoregon-cis415 by following these instructions. Make sure the repository is selected as 'private'
* Inside your VM, open the terminal and clone your uoregon-cis415 git repository, e.g. by using commands similiar to:
'git clone https://username@bitbucket.org/username/uoregon-cis415.git' (for https access) or
'git clone ssh://git@bitbucket.org/username/uoregon-cis415.git' (for SSH remote access; see these detailed instructions)
* To test your git repository configuration, create a new 'assignment0' directory inside your cloned repository, place a new file inside of 'assignment0', and then push 'assignment0' to your repository:
```
    cd /path/to/your/repository
    mkdir assignment0
    touch assignment0/testfile
    git add assignment0
    git commit -m "Directory for Assignment 0" assignment0
    git push
```
* Refer to this introductory tutorial for basic git commands and usage

**Requirements:**
* The assignment is to be done individually, but feel free to seek out help from your fellow classmates.
