# User Guide

## How to Run
1. First make sure you have git installed on your computer.  
2. Next, go to this link https://github.com/uwf-fang-cop3530/project-4-squaredphoenix which should 
open GitHub. 
3.  Find the button that says code and click on it. Make sure you are on the local tab and have HTTPS 
selected.  
4. Copy the web URL it gives you.  
5. Next open a Linux terminal like Ubuntu, git bash, or the one you have working with VS code. Those 
are just a few to name.  
6. Next on the Linux terminal navigate to the directory you want to save my program in.  
7. Once you are there, type in the command git clone “the copied URL”. Replace “copy URL” with the 
URL you copied earlier. That will copy all the files from the GitHub repository.
8.Once that is done you should have these main files and a few others.
    8.1. lsc.cpp
    8.2. sim.cpp
    8.3. makefile
    8.4. test.mk
    8.5. seqs.txt
9. You can make changes to the seqs.txt if you like.
10. Type in the command “make”. This will compile all the files into one executable file. 
11. Once that is done you will have to executables (sim/lcs).
12. Type in the command “./sim seqs.txt” to run the sim program. This will display the output of the code to the terminal base on what is on the segs.txt file.
13. Type in the command “./lcs (gene sequences) (gene sequences)”. Replece the gene sequences with some gene sequences. This will display the output of the code to the terminal base on the gene sequences you gave it.