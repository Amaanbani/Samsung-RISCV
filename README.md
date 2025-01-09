# Samsung-RISCV
The program focuses on the RISC-V architecture and utilizes open-source tools to educate individuals about VLSI chip design and RISC-V. The program is led by Kunal Ghosh Sir.

##  Essential Information

 **Name:**  Amaan Bani    
 **College:** Dayananda Sagar College Of Engineering   
 **Email ID:**  amaanbani@gmail.com  
 **GitHub Profile:** [Amaanbani](https://github.com/Amaanbani?tab=repositories)   
 **LinkedIN Profile:** [amaan-bani](https://www.linkedin.com/in/amaan-bani-324565331/)


----------------------------------------------------------------------------------------------------------------


<details>
<summary><b>Task 1 :</b> This Task involves reviewing C-based and RISC-V-based lab videos and performing the compilation of C code using both GCC and the RISC-V compiler</summary>

### C Language based LAB
We need to follow the specified steps to compile any **.c** file on our machine:  
1. Open the bash terminal and navigate to the directory where you want to create your file. Then run the following command:

	```
	leafpad sum1ton.c
	```  
2. This will open the editor, allowing you to write in the file you created. Enter the C code to calculate and print the sum of n numbers. After completing your code, press ```Ctrl + S``` to save your file, and then press ```Ctrl + W``` to close the editor.   
3. To the C code on your terminal, run the following command:

	```
	gcc sum1ton.c
	./a.out
	```
![C Code compiled on gcc Compiler](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%201/C%20Code%20compiled%20on%20gcc%20compiler.png)

### RISC-V based LAB
We need to compile the code again, but this time using the RISC-V GCC compiler. Follow the steps provided:  
1. Open the terminal and run the given command:  

	```
	cat sum1ton.c
	```
![cat Command](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%201/cat%20Command.png)

2. Use the **cat** command to display the entire C code in the terminal. Next, run the following command to compile the code using the RISC-V -O1 GCC compiler:  

	```
	riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
	```
3. The following command is used to display the file details of ```sum1ton.c``` in reverse chronological order, showing the most recently modified files last, 	 along with information such as file permissions, ownership, size, and the timestamp of the last modification:

	```
	ls -ltr sum1ton.c
 	```

4. To execute the C code on your terminal, use the following command:    

	```
	riscv64-unknown-elf-objdump -d sum1ton.o
	```
![Objdump using -O1 format](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%201/objDump%20using%20-O1%20format.png)


5. The Assembly Language code generated from the C code will be displayed in the terminal. Type ```/main``` to locate the main section of our code.


6. Similarly to the second step, run the following command to compile the code using the RISC-V -Ofast GCC compiler. The subsequent steps will display the 	 
generated assembly code, and you can type ```/main``` to locate the main section of our code:

	```
	riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
	```
 ![Objdump using -Ofast format](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%201/objDump%20using%20-Ofast%20format.png)
 

### *Descriptions of the keyword used in command above *  
* **-mabi=lp64:** Specifies the ABI (Application Binary Interface) as ```lp64```, which supports 64-bit integers, long, and pointer sizes. This ABI is intended for 64-bit RISC-V architecture.  
* **-march=rv64i:** Defines the target architecture as ```rv64i```, which represents the 64-bit RISC-V base integer instruction set, ensuring compatibility with the 64-bit architecture.  
* **riscv-objdump:** A disassembler tool for RISC-V binaries that provides insights into the code structure, assisting in debugging.  
* **-Ofast:** The option -Ofast in the command ```riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c``` is a compiler optimization flag used with the GNU Compiler Collection (GCC). This flag is used to instruct the compiler to optimize the generated code for maximum speed. The use of ```-Ofast``` is typically chosen for applications where execution speed is critical and where deviations from standard behavior are acceptable. However, it's important to test thoroughly, as this level of optimization can introduce subtle bugs, especially in complex calculations or when strict compliance with external standards is required.  
* **-O1:** A basic optimization level that balances improved execution speed and reduced code size with minimal impact on compilation time. It is suitable for applications requiring moderate optimization without extensive resource usage.  

#### *Other common options are as follows:*  
> 1. **-O0:** No optimization, the default level if no -O option is specified.  
> 2. **-O2:** More aggressive optimizations that might increase compilation time but typically provide faster and sometimes smaller code.  
> 3. **-O3:** Maximizes optimization more aggressively than -O2.  
> 4. **-Os:** Optimizes code for size. It enables all -O2 optimizations that do not typically increase code size.

Here, the term **more aggressive optimization** in the context of compilers like GCC refers to a deeper and more complex set of transformations applied to the code in order to improve its performance and possibly reduce its size. The compiler uses more complex techniques that aims to generate faster executing code or code that occupies less memory. However, these optimizations typically increase the compilation time and can sometimes introduce bugs, making it harder to debug.
</details>


----------------------------------------------------------------------------------------------------------------


<details>
<summary><b>Task 2:</b>Performing SPIKE simulation and debugging the C code using Spike's interactive debugging mode.</summary> 

  
### What is SPIKE in RISCV?
> * A RISC-V ISA is a simulator, enabling the testing and analysis of RISC-V programs without the need for actual hardware.  
> * Spike is a free, open-source C++ simulator for the RISC-V ISA that models a RISC-V core and cache system. It can be used to run programs and a Linux kernel, and can be a starting point for running software on a RISC-V target.  
 
  
### What is pk (Proxy Kernel)?  
> * The RISC-V Proxy Kernel, pk , is a lightweight application execution environment that can host statically-linked RISC-V ELF binaries.  
> * A Proxy Kernel in the RISC-V ecosystem simplifies the interaction between complex hardware and the software running on it, making it easier to manage, test, and develop software and hardware projects.  
 

### Testing the Spike Simulator  
The objective is to execute the ```sum1ton.c``` program using both the ```gcc compiler``` and the ```riscv compiler```, ensuring that both compilers produce identical output on the terminal. To compile the code with the **gcc compiler**, use the command below:
  
```
gcc sum1ton.c  
./a.out
```

And to compile the code using **RISCV Compiler**, use the following command: 
 
```
spike pk sum1ton.o
```  
![Spike Simulation](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%202/Spike%20Simulation.png)

#### The following snapshots display the RISCV objdump output generated using the **-O1** and **-Ofast** optimization options.

RISCV Objdump with -O1

![Objdump in -O1](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%202/Objdump%20in%20-O1.png)

RISCV Objdump with -Ofast 

![Objdump in -Ofast](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%202/Objdump%20in%20-Ofast.png)

### Debugging the Assembly Language Program of  ```sum1ton.c```.
  
* Open the **Objdump** of code by using the following command
  
```
$ riscv64-unknown-elf-objdump -d sum_1ton.o | less  
```
![Objdump commands](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%202/Objdump%20commands.png)

* Open the debugger in another terminal by using the following command.

```
$ spike -d pk sum_1ton.o
```

* The debugger will be opened in the terminal. Now, debugging operations can be performed as shown in the following snapshot.

![Debugging](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%202/Debugging.png) 
</details>
