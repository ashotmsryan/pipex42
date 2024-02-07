The project designed to deepen understanding of Unix processes, file descriptors, and inter-process communication. The goal of the project is to recreate the functionality of the shell command "< file1 cmd1 | cmd2 > file2" by utilizing the Unix system calls for process creation and manipulation. Through the implementation of this project,I gained valuable insights into the intricacies of command execution, input/output redirection, and the underlying mechanisms of pipelines in a Unix-like environment. Dived into the world of Unix processes with pipex to enhanced my skills in system programming and gained a deeper appreciation for the inner workings of command-line utilities.

To compile the project run the command "make" then use this command line, for example
```
  ./pipex "inputfile" "ls -l" "wc -l" "outputfile"
```
This should work as
```
  < inputfile ls -l | wc -l > outputfile
```
you are free to use your own commands  
