File encryption using Blowfish algorithm.


Blowfish is Feistel block cipher that can be used as a replacement for the DES algorithm. It takes a variable length key, 
ranging from 32 bits to 448 bits; default 128 bits and works on 64-bit block at a time. Blowfish is unpatented, license-free,
 and is available free for all users.It is a successor to Twofish.

Algorithm: 
The input is a 64-bit data element, x.
a. Divide x into two 32-bit halves: xL, xR.
b. ForEach{i=1 to 16}{
	xL = xL XOR Pi;
	xR = F(xL) XOR xR;
	Swap xL and xR;
   }
c. Swap xL and xR again.(To undo the last swap).
    xR = xR XOR P17;
    xL = xL XOR P18;
    x=xL+xR;

Since Blowfish is a Feistel network, it can be inverted simply by XORing P17 and P18 to the cipher text block, then using the P-entries in reverse order. 
Decryption works just the opposite way where i reduces from 17 to 1. It will execute 16+2 rounds for each 64-block of data. The 32-bit input is split 
into four eight-bit quarters by function block and then these quarters are used as input to the S boxes. The S box is a 4-row, 256-column table with 
each element in the table being one byte. There are four 32-bit S-boxes with 256 entries each. The outputs are added modulo 232 and XORed to produce
 the final 32-bit output. 

To run the project, execute the following commands:
>$ make

To generate a test-file, execute 
>$ ./testFileGenerator <Size of file in MB>

To run Blowfish:

>$ ./blowfish <filename with relative filepath(./<filename>)> <mode(1: Sequential 2: Parallel)>

Now enter the key:

>$ Please enter Encryption Key(Minimum 4 characters and maximum 56.
>$ <Your input>

The hashes of original and decrypted files match which is different from the encrypted file.

In case of parallel execution:

>$ Please enter number of threads for OpenMP 
>$ <Your input>

We will get the file size, block count, length of key, hash of original file, hash of encrypted file, 
hash of decrypted file, encryption time, decryption time(in milliseconds.) and sample contents of original,
encrypted and decrypted files(Till the first newline character). The algorithm works on buffer of file, so 
no encrypted file is generated.






