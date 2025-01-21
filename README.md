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
<summary><b> Task 1 :</b> This Task involves reviewing C-based and RISC-V-based lab videos and performing the compilation of C code using both GCC and the RISC-V compiler</summary>

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
<summary><b> Task 2 :</b> Performing SPIKE simulation and debugging the C code using Spike's interactive debugging mode </summary> 

  
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

----------------------------------------------------------------------------------------------------------------


<details>
	
<summary><b> Task 3 :</b> RISC-V Instruction Types and Instruction Decoding Visual Guide </summary>

### RISC-V Registers
RISC-V is a widely adopted open-source instruction set architecture that features 32 registers, each 32 bits wide. These registers provide faster data access compared to memory. The RISC-V architecture is considered a 32-bit architecture because it primarily processes 32-bit data. Additionally, a 64-bit variant of RISC-V is available, where registers are 64 bits wide, allowing for 64-bit data operations.

**Design Principle 3: Smaller is Faster**
The philosophy behind RISC-V design includes having a limited number of registers (32) to prevent bottlenecks from register access time, which enables faster computation. The selection of 32 registers is a balanced decision to optimize both speed and storage capacity.

### Register Naming in RISC-V
RISC-V has 32 registers, named `x0` through `x31`. However, these registers are often assigned more descriptive names based on their typical usage:

- **x0 (zero)**: This register always holds the constant value 0.
- **x1 (ra)**: Return Address register, which stores the return address after a function call.
- **x2 (sp)**: Stack Pointer register, pointing to the top of the stack in memory.
- **x3 (gp)**: Global Pointer register.
- **x4 (tp)**: Thread Pointer register.

### Saved, Temporary, and Argument Registers
The remaining registers are divided into saved, temporary, and argument categories:

- **Saved Registers (s0-s11)**: These registers (x8, x9, x18-x27) store variables that need to be preserved across function calls.
- **Temporary Registers (t0-t6)**: These registers are used for intermediate calculations and temporary data storage.
- **Argument Registers (a0-a7)**: These registers (x10-x17) are used to pass arguments to functions and store return values.

![image](https://github.com/user-attachments/assets/af936f03-ded7-4d6a-9e4b-38cf37695620)
### ABI : Application Binary Interface



## Decoding RISC-V Instructions: A Visual Guide

### Understanding I-Type, S-Type, B-Type, U-Type, and J-Type Instructions
 
 ## Introduction Section:
RISC-V (Reduced Instruction Set Computer - V) is a free and open instruction set architecture (ISA) built on the foundational principles of reduced instruction set computing. Unlike proprietary ISAs, RISC-V imposes no licensing fees, enabling unrestricted use for academic, research, and commercial purposes. Its openness and flexibility have made it a preferred choice in education, research, and industry, fostering innovation and broad application across various fields.

### Significance of Instruction Formats
Understanding instruction formats plays a pivotal role in several aspects of computer architecture and design:
1. **Instruction Decoding**: Familiarity with instruction structures ensures accurate decoding, a critical step for the CPU to execute commands properly.
2. **Pipeline Efficiency**: Instruction formats influence CPU pipeline design, enabling smooth execution of the fetch, decode, execute, memory access, and write-back phases.
3. **Compiler Efficiency**: A thorough grasp of instruction formats allows compilers to generate optimized machine code, enhancing performance and efficiency.
4. **Debugging and Verification**: Knowledge of instruction formats aids in pinpointing and resolving hardware and software issues, such as incorrect execution or pipeline hazards.
5. **Extensibility and Customization**: The modular nature of RISC-V supports custom extensions. A solid understanding of its base instruction formats is essential for developing and incorporating tailored instructions to meet specific application or performance requirements .

# BASICS
 ## Instruction Types and Fields
The RISC-V instructions are categorized into types based on their field organization. The types include:
- **R-type**: Register instructions
- **I-type**: Immediate instructions
- **S-type**: Store instructions
- **B-type**: Branch instructions
- **U-type**: Upper immediate instructions
- **J-type**: Jump instructions

## Opcode and Function Fields
- **Opcode**: Specifies the instruction type..
- **func3** and **func7**: Define specific operations within each instruction type.
  - Example: In R-type instructions, func3 and func7 distinguish operations like addition or subtraction.
## Immediate Values and Registers
- **Immediate Values**: Encoded within specific fields of an instruction.
  - Example: I-type instructions include a 12-bit immediate value alongside source and destination registers.
- **Registers**: Identified by fields such as rd (destination register), rs1 (source register 1), and rs2 (source register 2).
### Example - U-Type Instruction
Consider the `lui` (Load Upper Immediate) instruction:
- **Assembly**: `lui x5, 0x12345`
- **Encoding**: The immediate value `0x12345`in the instruction’s immediate field and specifies `x5` as the destination register in the rd field.
- **Machine Execution**: Loads the upper 20 bits of `0x12345` into the upper 20 bits of register `x5` .
   ## Arithmetic Instructions
- **ADD**:  Performs addition of two registers and stores the result in a third.
  - Example: `ADD rd, rs1, rs2` (rd = rs1 + rs2)
- **ADDI**: Adds a register and an immediate value (constant) and stores the result.
  - Example: `ADDI rd, rs1, imm` (rd = rs1 + imm)
## Logical Instructions
- **AND, OR, XOR**: Perform bitwise operations.
  - Example: `AND rd, rs1, rs2` (rd = rs1 & rs2)
## Branch Instructions
- **BEQ**: Branches if two registers are equal.
  - Example: `BEQ rs1, rs2, offset` (if rs1 == rs2, PC = PC + offset)
- **BNE**: Branches if two registers are equal..
  - Example: `BNE rs1, rs2, offset` (if rs1 != rs2, PC = PC + offset)
## Load and Store Instructions
- **LW**: Loads a word from memory.
  - Example: `LW rd, offset(rs1)` (rd = memory[rs1 + offset])
- **SW**: Stores a word to memory.
  - Example: `SW rs1, offset(rs2)` (memory[rs2 + offset] = rs1)
## Special Instructions
- **AUIPC**: Adds an upper immediate value to the program counter (PC).
  - Example: `AUIPC rd, imm` (rd = PC + imm << 12)
## Branch and Jump Instructions
- **Jump (J)**: Executes an unconditional branch to a target address.
- **Branch (B)**: Executes an unconditional branch to a target address..
## RV32I Extensions
RISC-V supports optional extensions to enhance functionality:
- **M**: Supports integer multiplication and division.
- **A**: Provides atomic operation instructions.
- **F, D, Q**: Enables floating-point operations (32-bit, 64-bit, 128-bit).
- **C**: Includes compressed instructions for reduced code size.

### RISC-V R-Type Instructions
R-type instructions are used for operations that involve only registers. These instructions typically perform arithmetic, logical, and shift operations.
#### Format: 
![image](https://github.com/user-attachments/assets/e01d8bbe-710e-4927-8fec-51f162d384ca)
- **opcode**: Specifies the operation (e.g., 0110011 for integer register-register operations).
- **rd**: Destination register.
- **funct3**: Further specifies the operation.
- **rs1**: First source register.
- **rs2**: Second source register.
- **funct7**: Further specifies the operation.
### I-Type Instructions
I-Type instructions cover various operations, including immediate arithmetic, load operations, and certain control flow instructions.
### Extracting Immediate Value
- The immediate value spans bits [31:20].
- To extract this value:
  - Mask the instruction to isolate the relevant bits.
  - Perform a right shift to align the immediate value to the least significant bits (LSBs).
- **Example**: If the instruction value is `0x12345678`, the immediate value is extracted as follows:
  ```cpp
  uint32_t imm_i = (instruction & 0xFFF00000) >> 20;
![image](https://github.com/user-attachments/assets/3d035720-dc62-45d5-9a2c-2a6b263ade74)
**Example: ADDI rd, rs1, imm**
- **opcode**: 0010011 (for immediate arithmetic operations)
- **funct3**: 000 (for ADDI)
- **imm**: Immediate value
- **rs1**: Source register 1
- **rd**: Destination register
### S-Type Instructions
![image](https://github.com/user-attachments/assets/eb224238-c0ef-42ca-82d0-c42ed8293320)
**Example: SW rs2, imm(rs1)**
- **opcode**: 0100011 (for store operations)
- **funct3**: 010 (for SW)
- **imm**: Immediate value (split into imm[11:5] and imm[4:0])
- **rs1**: Base address register
- **rs2**: Source register to be stored
### B-Type Instructions
![image](https://github.com/user-attachments/assets/7f138e24-cb0c-4506-9875-c4b3b14a2670)
**Example: BEQ rs1, rs2, imm**
- **opcode**: 1100011 (for branch operations)
- **funct3**: 000 (for BEQ)
- **imm**: Immediate value (split into imm[12], imm[10:5], imm[4:1], imm[11])
- **rs1**: Source register 1
- **rs2**: Source register 2
### U-Type Instructions
U-Type instructions are used for operations like loading upper immediate (LUI) and adding upper immediate to PC (AUIPC).
### Extracting Immediate Value
- The immediate value in U-type instructions spans bits [31:12].
- To extract this value, you can mask the instruction with `0xFFFFF000`.
- **Example**: If the instruction value is `0x12345000`, applying the mask will yield `0x12345000`.
### Encoding and Usage
- The immediate value extracted directly forms part of the U-type instruction.
  - For **LUI**, this value is loaded into the destination register.
  - For **AUIPC**, this value is added to the current PC.
![image](https://github.com/user-attachments/assets/d6269585-d85a-4675-b13f-4ae4ed1ea05a)
**Example: LUI rd, imm**
- **opcode**: 0110111 (for LUI)
- **imm**: Upper 20 bits of the immediate value
- **rd**: Destination register
### J-Type Instructions
![image](https://github.com/user-attachments/assets/9b35cad7-8fd8-41da-be46-aec4cf712657)
**Example: JAL rd, imm**
- **opcode**: 1101111 (for JAL)
- **imm**: Immediate value (split into imm[20], imm[10:1], imm[11], imm[19:12])
- **rd**: Destination register (stores the return address)

## ObjDump RISC-V Instruction Decoding:
![objDump](https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%203/objDump.png).
### 1.`addi sp, sp, -16`
*addi (Add Immediate):* This instruction adds an immediate value to a register, storing the result in the destination register.

#### Instruction: `addi sp, sp, -16`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -16 (12 bits, two's complement)
- **Source Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** sp (x2, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (-16):** `111111111000` (12 bits, two's complement)
- **rs1 (sp = x2):** `00010`
- **funct3:** `000`
- **rd (sp = x2):** `00010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi sp, sp, -16`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111111000        | 00010        | 000             | 00010       | 0010011         |

#### Binary Representation:
- **Binary:** `111111111000 00010 000 00010 0010011`
- **Hex:** `ff5013`

---

### 2. `sd ra, 8(sp)`
*sd (Store Doubleword):* This instruction stores a 64-bit value from a source register into memory.

#### Instruction: `sd ra, 8(sp)`
- **Opcode:** 0100011 (7 bits)
- **Immediate:** 8 (12 bits, split into two parts: imm[11:5] and imm[4:0])
- **Source Register (rs2):** ra (x1, 5 bits)
- **Base Register (rs1):** sp (x2, 5 bits)
- **Function (funct3):** 011 (3 bits)

#### Breakdown:
- **Immediate (8):** `000000001000` (split into imm[11:5] = `0000000` and imm[4:0] = `01000`)
- **rs2 (ra = x1):** `00001`
- **rs1 (sp = x2):** `00010`
- **funct3:** `011`
- **Opcode:** `0100011`

### Machine Code Breakdown for `sd ra, 8(sp)`
| imm[11:5] (7 bits) | rs2 (5 bits) | rs1 (5 bits) | funct3 (3 bits) | imm[4:0] (5 bits) | Opcode (7 bits) |
|--------------------|--------------|--------------|-----------------|-------------------|-----------------|
| 0000000            | 00001        | 00010        | 011             | 01000             | 0100011         |

#### Binary Representation:
- **Binary:** `0000000 00001 00010 011 01000 0100011`
- **Hex:** `0001023f`

---

### 3. `li a5, 500`
*li (Load Immediate):* This instruction loads a 32-bit immediate value into a register.

#### Instruction: `li a5, 500`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 500 (12 bits, sign-extended)
- **Destination Register (rd):** a5 (x15, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (500):** `000000111110100` (12 bits)
- **rd (a5 = x15):** `01111`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a5, 500`
| Immediate (12 bits) | rd (5 bits) | funct3 (3 bits) | Opcode (7 bits) |
|---------------------|-------------|-----------------|-----------------|
| 000000111110100     | 01111       | 000             | 0010011         |

#### Binary Representation:
- **Binary:** `000000111110100 01111 000 00111 0010011`
- **Hex:** `01f30313`

---

### 4.`addiw a5, a5, -1`
*addiw (Add Immediate Word):* This instruction adds a 32-bit immediate value to a register and stores the result in the destination register.

#### Instruction: `addiw a5, a5, -1`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -1 (12 bits, two's complement)
- **Source Register (rs1):** a5 (x15, 5 bits)
- **Destination Register (rd):** a5 (x15, 5 bits)
- **Function (funct3):** 001 (3 bits)

#### Breakdown:
- **Immediate (-1):** `111111111111` (12 bits, two's complement)
- **rs1 (a5 = x15):** `01111`
- **funct3:** `001`
- **rd (a5 = x15):** `01111`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addiw a5, a5, -1`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111111111        | 01111        | 001             | 01111       | 0010011         |

#### Binary Representation:
- **Binary:** `111111111111 01111 001 01111 0010011`
- **Hex:** `fff30313`

---

### 5. `bnez a5, 10190 <main+0xc>`
*Branch if Not Equal to Zero:* This instruction performs a branch if the value in the source register is not zero.

#### Instruction: `bnez a5, 10190 <main+0xc>`
- **Opcode:** 1100011 (7 bits)
- **Immediate:** 10190 (12 bits, sign-extended)
- **Source Register (rs1):** a5 (x15, 5 bits)
- **Function (funct3):** 001 (3 bits)

#### Breakdown:
- **Immediate (10190):** `00000000000101001110` (split into imm[12|10:5] = `0000000` and imm[4:1|11] = `101001110`)
- **rs1 (a5 = x15):** `01111`
- **funct3:** `001`
- **Opcode:** `1100011`

### Machine Code Breakdown for `bnez a5, 10190 <main+0xc>`
| imm[12|10:5] (7 bits) | rs1 (5 bits) | funct3 (3 bits) | imm[4:1|11] (5 bits) | Opcode (7 bits) |
|-----------------------|--------------|-----------------|-----------------------|-----------------|
| 0000000               | 01111        | 001             | 01001110              | 1100011         |

#### Binary Representation:
- **Binary:** `0000000 01111 001 01001110 1100011`
- **Hex:** `000f13f3`

---

### 6.`lui a2, 0x1f`
*lui (Load Upper Immediate):* This instruction loads a 20-bit immediate value into the upper 20 bits of a register, setting the lower 12 bits to zero.

#### Instruction: `lui a2, 0x1f`
- **Opcode:** 0110111 (7 bits)
- **Immediate:** 0x1f (20 bits, upper 20 bits of the immediate value)
- **Destination Register (rd):** a2 (x6, 5 bits)

#### Breakdown:
- **Immediate (0x1f):** `0000000000011111` (20 bits, shifted left by 12 bits to be placed in the upper 20 bits of the register)
- **rd (a2 = x6):** `00110`
- **Opcode:** `0110111`

#### Binary Representation:
- **Binary:** `00000000000000000000 00110 0110111`
- **Hex:** `00030337`

### Machine Code Breakdown for `lui a2, 0x1f`
| imm[19:12] (8 bits) | imm[11:0] (12 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 0000000001111111     | 00110       | 0110111         |

---

### 7. `addi a2, a2, -1726`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi a2, a2, -1726`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -1726 (12 bits, two's complement)
- **Source Register (rs1):** a2 (x6, 5 bits)
- **Destination Register (rd):** a2 (x6, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (-1726):** `1111111011100010` (12 bits, two's complement)
- **rs1 (a2 = x6):** `00110`
- **funct3:** `000`
- **rd (a2 = x6):** `00110`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi a2, a2, -1726`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111101110        | 00110        | 000             | 00110       | 0010011         |

#### Binary Representation:
- **Binary:** `111111101110 00110 000 00110 0010011`
- **Hex:** `ffd30393`

---

### 8. `li a1, 500`
*li (Load Immediate):* This instruction loads an immediate value into a register.

#### Instruction: `li a1, 500`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 500 (12 bits)
- **Destination Register (rd):** a1 (x11, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (500):** `0000000111110100` (12 bits)
- **rd (a1 = x11):** `01011`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a1, 500`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000011111        | 00000        | 000             | 01011       | 0010011         |

#### Binary Representation:
- **Binary:** `000000011111 00000 000 01011 0010011`
- **Hex:** `01f30393`

---

### 9. `lui a0, 0x21`
*lui (Load Upper Immediate):* This instruction loads a 20-bit immediate value into the upper 20 bits of a register.

#### Instruction: `lui a0, 0x21`
- **Opcode:** 0110111 (7 bits)
- **Immediate:** 0x21 (20 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)

#### Breakdown:
- **Immediate (0x21):** `0000000000100001` (20 bits, shifted to upper 20 bits)
- **rd (a0 = x10):** `01010`
- **Opcode:** `0110111`

### Machine Code Breakdown for `lui a0, 0x21`
| imm[19:12] (8 bits) | imm[11:0] (12 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 000000100001         | 01010       | 0110111         |

#### Binary Representation:
- **Binary:** `00000000000000000000 01010 0110111`
- **Hex:** `00052137`

---

### 10. `addi a0, a0, 400`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi a0, a0, 400`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 400 (12 bits)
- **Source Register (rs1):** a0 (x10, 5 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (400):** `0000000110010000` (12 bits)
- **rs1 (a0 = x10):** `01010`
- **funct3:** `000`
- **rd (a0 = x10):** `01010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi a0, a0, 400`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000011001        | 01010        | 000             | 01010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000011001 01010 000 01010 0010011`
- **Hex:** `00066093`

---

### 11. `jal ra, 10418`
*jal (Jump and Link):* This instruction performs a jump to a target address, saving the return address in the link register (ra).

#### Instruction: `jal ra, 10418`
- **Opcode:** 1101111 (7 bits)
- **Immediate:** 10418 (20 bits, sign-extended)
- **Destination Register (rd):** ra (x1, 5 bits)

#### Breakdown:
- **Immediate (10418):** `00000000001010011100` (20 bits, shifted by 1)
- **rd (ra = x1):** `00001`
- **Opcode:** `1101111`

### Machine Code Breakdown for `jal ra, 10418`
| imm[19:12] (8 bits) | imm[11:1] (11 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 00101001110          | 00001       | 1101111         |

#### Binary Representation:
- **Binary:** `00000000000000000000 00001 1101111`
- **Hex:** `0005286f`

---

### 12. `li a0, 0`
*li (Load Immediate):* This instruction loads an immediate value into a register.

#### Instruction: `li a0, 0`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 0 (12 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (0):** `000000000000`
- **rd (a0 = x10):** `01010`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a0, 0`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000000000        | 00000        | 000             | 01010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000000000 00000 000 01010 0010011`
- **Hex:** `00030393`

---

### 13. `ld ra, 8(sp)`
*ld (Load Doubleword):* This instruction loads a 64-bit value from memory into a register.

#### Instruction: `ld ra, 8(sp)`
- **Opcode:** 0000011 (7 bits)
- **Immediate:** 8 (12 bits)
- **Base Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** ra (x1, 5 bits)
- **Function (funct3):** 011 (3 bits)

#### Breakdown:
- **Immediate (8):** `000000000010`
- **rs1 (sp = x2):** `00010`
- **funct3:** `011`
- **rd (ra = x1):** `00001`
- **Opcode:** `0000011`

### Machine Code Breakdown for `ld ra, 8(sp)`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000000010        | 00010        | 011             | 00001       | 0000011         |

#### Binary Representation:
- **Binary:** `000000000010 00010 011 00001 0000011`
- **Hex:** `00028283`

---

### 14. `addi sp, sp, 16`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi sp, sp, 16`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 16 (12 bits)
- **Source Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** sp (x2, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (16):** `000000010000`
- **rs1 (sp = x2):** `00010`
- **funct3:** `000`
- **rd (sp = x2):** `00010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi sp, sp, 16`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000010000        | 00010        | 000             | 00010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000010000 00010 000 00010 0010011`
- **Hex:** `00050393`

---

### 15. `ret`
*ret (Return from Function):* This instruction returns from a function by jumping to the address stored in `ra`.

#### Instruction: `ret`
- **Opcode:** 1100111 (7 bits)
- **Immediate:** 0 (12 bits, the value of `ra` is used directly)
- **Source Register (rs1):** ra (x1, 5 bits)

#### Breakdown:
- **Immediate (0):** `000000000000`
- **rs1 (ra = x1):** `00001`
- **funct3:** `000`
- **Opcode:** `1100111`

### Machine Code Breakdown for `ret`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-----------------|
| 000000000000        | 00001        | 000             | 1100111         |

#### Binary Representation:
- **Binary:** `000000000000 00001 000 1100111`
- **Hex:** `00008067`

</details>


----------------------------------------------------------------------------------------------------------------

<details><summary><b>Task 4: </b> By using RISC-V Core: Verilog netlist and Testbench, perform an experiment of Functional Simulation using GTKWave and Observe the waveforms.</summary>
<h3>Steps:</h3>
1. Using suitable commands install the iverilog and GTKWave in ubuntu<br>
2. Compile the RISC-V Core: Verilog netlist and Testbench<br>
3. Observe the waveform output in GTKWave window<br>
<h4>Installing iverilog and GTKWave in Ubuntu:</h4>
<pre><code>sudo apt install iverilog gtkwave</code></pre>
<h3>Simulate and run the verilog code</h3>
<pre><code>iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
./iiitb_rv32i
gtkwave iiitb_rv32i.vcd</code></pre>
<h4>Commands:</h4><br>
<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/Commands.png" alt="Commands">
<br><br>
<h4>GTKWave Window:</h4><br>
<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/GTKWave_Window.png" alt="GTKWave Window">
<br><br>
<h4>Hardcoded Instructions:</h4><br>
<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/Instructions.png" alt="Hardcoded ISA">
<br><br>
<h3>Ouput Waveforms:</h3>
<p>The output waveforms showing the instructions performed in a 5-stage pipelined architecture</p>
<b><i>Instruction 1:</i></b><pre> ADD R6, R2, R1</pre>
	<p>This instruction Adds values of registers R2 and R1 and stores the result in register R6, In this case 1 + 2 = 3.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/01_ADD_r6_r1_r2.png" alt="ADD R6, R2, R1">
<br><br><b><i>Instruction 2:</i></b><pre> SUB R7, R1, R2</pre>
	<p>This instruction subtracts value of register R2 from R1 and stores the result in register R7, In this case 1 - 2 = -1.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/02_SUB_r7_r1_r2.png" alt="SUB R7, R1, R2">
<br><br><b><i>Instruction 3:</i></b><pre> AND R8, R1, R3</pre>
	<p>This instruction executes bitwise "AND" between values of registers R1 and R3 and stores the result in register R8, In this case 01 & 11 = 01(1 in decimal).</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/03_AND_r8_r1_r3.png" alt="AND R8, R1, R3">
<br><br><b><i>Instruction 4:</i></b><pre> OR R9, R2, R5</pre>
	<p>This instruction executes bitwise "OR" between values of registers R2 and R5 and stores the result in register R9, In this case 010 | 101 = 111(7 in decimal).</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/04_OR_r9_r2_r5.png" alt="OR R9, R2, R5">
<br><br><b><i>Instruction 5:</i></b><pre> XOR R10, R1, R4</pre>
	<p>This instruction executes bitwise XOR between values of registers R1 and R4 and stores the result in register R10, In this case 001 ^ 100 = 101(5 in decimal).</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/05_XOR_r10_r1_r4.png" alt="XOR R10, R1, R4">
<br><br><b><i>Instruction 6:</i></b><pre> SLT R11, R2, R4</pre>
	<p>This instruction checks the values of registers R2 and R4 if value of R2 is less than value of R4, then register R11 is set to 1, In this case 2<4 so R11 is set to 1.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/06_SLT_r11_r2_r4.png" alt="SLT R11, R2, R4">
<br><br><b><i>Instruction 7:</i></b><pre> ADDI R12, R4, 5</pre>
	<p>This instruction adds the immediate data 5 to the value in register R4 and stores the result in register R12, In this case 4 + 5 = 9.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/07_ADDI_r12_r4_5.png" alt="ADDI R12, R4, 5">
<br><br><b><i>Instruction 8:</i></b><pre> SW R3, R1, 2</pre>
	<p>This instruction stores the register data @R1+2 into the memory, In this case 1 + 2 = 3.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/08_SW_r3_r1_2.png" alt="SW R3, R1, 2">
<br><br><b><i>Instruction 9:</i></b><pre> LW R13, R1, 2</pre>
	<p>This instruction loads the register data @R1+2 into the register R13, In this case 1 + 2 = 3.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/09_LW_r13_r1_2.png" alt="LW R13, R1, 2">
<br><br><b><i>Instruction 10:</i></b><pre> BEQ R0, R0, 15</pre>
	<p>This instruction Branches to 15 instructions ahead of current instruction if values of registers R0 equals R0, so Program Counter will be incremented by 15, In this case PC is 10 so new PC value will be 10+15=25.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/10_BEQ_r0_r0_15.png" alt="BEQ R0, R0, 15">
<br><br><b><i>Instruction 11:</i></b><pre> ADD R14, R2 R2</pre>
	<p> This instruction Adds values of registers R2 and R2 and stores the result in register R14, In this case 2 + 2 = 4.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/11_ADD_r14_r2_r2.png" alt="ADD R14, R2 R2">
<br><br><b><i>Instruction 12:</i></b><pre> BNE R0, R1, 20</pre>
	<p>This instruction Branches to 20 instructions ahead of current instruction if values of registers R0 and R1 don't match , so Program Counter will be incremented by 20, In this case PC is 28 so new PC value will be 28+20=48.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/12_BNE_r0_r1_20.png" alt="BNE R0, R1, 20">
<br><br><b><i>Instruction 13:</i></b><pre> ADDI R12, R4, 5</pre>
	<p>This instruction adds the immediate data 5 to the value in register R4 and stores the result in register R12, In this case 4 + 5 = 9.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/13_ADDI_r12_r4_5.png" alt="ADDI R12, R4, 5">
<br><br><b><i>Instruction 14:</i></b><pre> SLL R15, R1, R2</pre>
	<p>This instruction shifts the value of register R1 to left by 2, (001)&lt;&lt;2=(100)4.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/14_SLL_r15_r1_r2.png" alt="SLL R15, R1, R2">
<br><br><b><i>Instruction 15:</i></b><pre> SRL R16, R4, R2</pre>
	<p>This instruction shifts the value of register R1 to right by 2, (100)&gt;&gt;2=(001)1.</p>
	<img src="https://github.com/Amaanbani/Samsung-RISCV/blob/main/Task%204/15_SRL_r16_r4_r2.png" alt="SRL R16, R4, R2">
<br><br>
</details>

----------------------------------------------------------------------------------------------------------------
