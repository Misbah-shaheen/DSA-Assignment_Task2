### DSA-Assignment_Task2
# Very Large Prime Number Calculation

## Overview

This project implements a method to generate and evaluate the primality of a 1024-bit random number using a linked list structure in C++. It demonstrates how to handle very large numbers that exceed standard data type limits by splitting them into smaller chunks.

## Approach

1. **Linked List Structure**: 
   - A linked list is employed to store segments of a 1024-bit number, allowing dynamic allocation and management of memory.
   - Each node in the linked list contains a 64-bit unsigned integer, with a total of 16 nodes required to represent the complete 1024-bit number.

2. **Random Number Generation**: 
   - A random 1024-bit number is generated by concatenating 16 segments of 64 bits each, utilizing the `rand()` function from the C++ standard library.

3. **Primality Testing**: 
   - The Miller-Rabin primality test is implemented to probabilistically determine if the reconstructed number is prime.
   - The algorithm operates on the entire number rather than on individual segments, ensuring accurate results.

4. **Memory Management**: 
   - Careful attention is given to memory allocation and deallocation, with a destructor included in the linked list class to free allocated nodes.

5. **Output**: 
   - The program outputs the generated number, the result of the primality test, and a list of smaller primes for reference.

## Assumptions

- **Memory Availability**: The implementation assumes that there is sufficient memory available to handle the linked list structure for a 1024-bit number.
- **Randomness**: The randomness of the generated number is reliant on the `rand()` function, which may not be suitable for cryptographic purposes.
- **Integer Limits**: The implementation is designed to work with 64-bit integers, which limits the segments' maximum size and requires careful handling to avoid overflow during calculations.
- **Miller-Rabin Accuracy**: The default configuration of the Miller-Rabin test runs 5 iterations, balancing performance and accuracy in the primality assessment.

## Challenges Faced

- **Memory Management**: 
  - Ensuring efficient memory management was a challenge, particularly in avoiding memory leaks. Implementing the destructor required careful tracking of allocated nodes.

- **Random Number Generation**: 
  - Generating a sufficiently random 1024-bit number while adhering to the 64-bit segment constraints necessitated a robust randomization strategy.

- **Primality Testing Implementation**: 
  - Implementing the Miller-Rabin test required thorough testing to ensure correctness, particularly in managing large numbers across multiple linked list nodes.

- **Performance Considerations**: 
  - Balancing performance and accuracy in the primality test proved challenging, especially with the potential for large computational overhead from multiple iterations.

## Setup and Running Instructions

1. Ensure you have a C++ compiler (e.g., g++) installed on your system.
## Contributors

Name             
 Misbah Shaheen  
 Email
[misbahshaheentiwana007@gmail.com](mailto:misbahshaheentiwana007@gmail.com) 


