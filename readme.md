File encryption using Blowfish algorithm.


Blowfish is Feistel block cipher that can be used as a replacement for the DES algorithm. It takes a variable length key, ranging from 32 bits to 
448 bits; default 128 bits and works on 64-bit block at a time. Blowfish is unpatented, license-free, and is available free for all users.It is a
successor to Twofish.

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

To run the project:
>$ make
>$ ./testFileGenerator <Size of file in MB>
>$ ./blowfish <filename with relative filepath> <mode(1: Sequential 2: Parallel)>
>$ Please enter Encryption Key(Minimum 4 characters and maximum 56.
>$ <Your input>
>$ Please enter number of threads for OpenMP  (In case of parallel)
>$ <Your input>
File size = ______ bytes, Block Count = _______
Please enter Encryption Key(Minimum 4 characters and maximum 56)
<Your input>
Key = _________, length = _____
Keys Initialized.
Hash of Original File : _______________
Starting Sequential Encryption ...
...
...
...
Encryption Completed.
Encryption time: ___________ milliseconds
Hash of Encrypted File : _______________
Starting Sequential Decryption ...
...
...
...
Decryption Completed.
Decryption time: ____________ milliseconds
Hash of Decrypted File : _________________
Hashes match! Encrytion and decryption were successful!





