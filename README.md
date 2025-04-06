# DATA-COMPRESSION-TOOL

*COMPANY*: CODTECHIT SOLUTIONS

*NAME*: YASHVI BHALA

*INTERNID*: YASHVI38684

*DOMAIN*: C-LANGUAGE

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

##REPORT ON RLE FILE COMPRESSION PROGRAM IN C
1. Title of the Program
Run-Length Encoding (RLE) Based File Compression and Decompression in C

2. Objective
The objective of this project is to implement a basic Run-Length Encoding (RLE) algorithm in C for compressing and decompressing text files. The program allows the user to select between compression and decompression modes and work with user-specified files.

3. Tools & Technologies Used
Programming Language: C

Compiler: GCC (GNU Compiler Collection)

IDE: Visual Studio Code (VS Code)

Extensions: C/C++ by Microsoft, Code Runner

Standard C Libraries:

<stdio.h> – for file input/output

<stdlib.h> – for error handling and memory functions

<string.h> – for string comparison

4. Description of the Program
The rle_compression.c program is designed to perform file compression and decompression using Run-Length Encoding, a simple lossless data compression technique. This method is effective for files with many repeated characters.

Key Functionalities:
Mode Selection:

Prompts the user to choose between compress or decompress operations.

File Input/Output Handling:

Takes input and output filenames from the user.

Performs necessary file opening and closing operations safely.

Compression Logic:

Reads each character from the input file.

If a character repeats, it counts the frequency and stores the result in the format:
character + count (e.g., a5 means aaaaa)

Outputs the compressed data to the specified file.

Decompression Logic:

Reads the compressed file character by character.

For each character, reads its associated count and reproduces the original sequence.

Writes the decompressed content to the output file.

Error Handling:

Includes checks for invalid file access.

Handles edge cases such as empty files or improperly formatted input.

5. Working Mechanism
Compression Flow:

User inputs mode as compress.

Program reads characters from the input file.

Detects consecutive repetitions and counts them.

Writes the result in RLE format to the output file.

Decompression Flow:

User inputs mode as decompress.

Program reads characters and associated counts from the compressed file.

Reconstructs the original data and writes it to the output file.

6. Use Cases and Applications
Data Compression: Useful for reducing file size for repeated-character text files like logs, DNA sequences, etc.

Introductory Projects in Compression Algorithms: Great for students learning about encoding/decoding logic.

File Archiving: Can be used as a lightweight archiver for simple datasets.

Embedded Systems: Suitable for constrained environments where lightweight compression is required.

7. Advantages
Simple Implementation: Easy to understand and modify for learning purposes.

Lossless Compression: No data is lost during compression or decompression.

Lightweight: Works well for small files and repetitive data.

Cross-Platform Compatibility: Can be compiled and executed on any system supporting C.

8. Limitations
Inefficient for Non-Repetitive Data: May increase size if input lacks repetition.

Single-Character Limitation: Assumes each run is a single character followed by its count.

Basic Format Handling: Not suited for binary or structured files.

9. Conclusion
This project successfully demonstrates the implementation of Run-Length Encoding for compressing and decompressing text files using C. Through this, we gain insights into how basic compression algorithms work and how file I/O operations are handled in C. This foundational logic can be extended into more complex compression techniques like Huffman encoding or LZ77.

The program was developed in Visual Studio Code and compiled using the GCC compiler, emphasizing clarity, modular design, and safe file handling.

#OUTPUT: 

![Image](https://github.com/user-attachments/assets/5b8817fc-80f4-4c07-b7c8-1c2cb1a0d291)
