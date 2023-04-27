# holbertonschool-shell
It is a pseudo-recreation of a command interpreter “sh” that has been made in C.

# Flowchart
 
![Web-Store-Block-Diagram (1)](https://user-images.githubusercontent.com/30449167/234930599-608d0c73-ac0c-458c-8066-2052de7a79ff.jpg)

# Usage
In order to use the simple_shell, you need to compile all “.c” repositories. Consequently, execute the resulting file.
Simple_shell is able of executing any executable file that can be call with the complete directory, or just with the name of the file as long as the file can be found at any directories of the PATH environment variable.
Ones the shell is running you should be able to use it as a regular shell

### Example
When the file is runing. the prompt `($)` will be shown as this.
```
($)_
```
Let's assume that you are working on a directory with the files `Hello`, `World` and `Hello_world.c`. When typing `ls`, your screen should look like this
```
($)ls
Hello  World  Hello_world.c
($)_
```

### Compilation:
```
$ gcc *.c -o hsh
```

### Output:
```
$ ./hsh
($)_
```
###Authors
* Jesús Andres Piedradhíta Ovalle <[Gaburon](https://github.com/Gaburon)>
* Jorge Fernando Ochoa Morales <[goever1](https://github.com/goever1)>
