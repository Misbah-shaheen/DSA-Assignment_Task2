#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

// Node structure for the linked list
struct Node {
    uint64_t data;  // Store part of the large number (64 bits)
    Node* next;     // Pointer to the next node in the linked list

    // Constructor to initialize the node with a value
    Node(uint64_t value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;  // Head pointer of the linked list

    // Constructor to initialize head to nullptr
    LinkedList() {
        head=nullptr;

    }

    // Function to create a new node
    Node* createNode(uint64_t value) {
        return new Node(value);
    }

    // Function to insert a value at the end of the linked list
    void insert(uint64_t value) {
        Node* newNode = createNode(value); // Create a new node

        // If the list is empty, set the new node as head
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head; // Temporary pointer to traverse the list
            while (temp->next) {
                temp = temp->next; // Move to the end of the list
            }
            temp->next = newNode; // Link the new node at the end
        }
    }

    // Function to generate a random 1024-bit number and store it in the linked list
    void generateRandomNumber() {
        for (int i = 0; i < 16; i++) { // Generate 16 chunks of 64 bits
            uint64_t randomValue = (static_cast<uint64_t>(rand()) << 32) | rand(); // Create a 64-bit random number
            insert(randomValue); // Insert the random number into the linked list
        }
    }

    // Function to perform modular exponentiation with large numbers
    uint64_t modularExponentiation(uint64_t base, uint64_t exponent, uint64_t m) {
        uint64_t result = 1;
        base = base % m; // Keep base smaller than the modulus

        while (exponent > 0) {
            // If exponent is odd
            if (exponent & 1) { 
                result = (result * base) % m; // Multiply base to the result
            }
            // Divide the exponent by 2
            exponent >>= 1; 
            base = (base * base) % m; // Square the base
        }
        return result; // Return the result of (base^exponent) % m
    }

    // Function to check if a number is prime using the Miller-Rabin primality test
    bool isPrime(uint64_t n, int k = 5) {
        if (n <= 1) 
            // 0 and 1 are not prime numbers
            return false;

        if (n <= 3) 
            // 2 and 3 are prime numbers
            return true; 

        if (n % 2 == 0) 
            // Exclude even numbers greater than 2
            return false;

        // logically check primality
        uint64_t d = n - 1;
        int r = 0;

        // Find d such that n-1 = d * 2^r
        while (d % 2 == 0) {
            d /= 2; // Halve d until it is odd
            r++;
        }

        // Perform k iterations of the test
        for (int i = 0; i < k; i++) {
            uint64_t a = 2 + rand() % (n - 4); // Random base in the range [2, n-2]
            uint64_t x = modularExponentiation(a, d, n); // Compute a^d mod n

            // If x is 1 or n-1, continue to the next iteration
            if (x == 1 || x == n - 1) continue;

            bool composite = true; // suppose the number is composite

            // Check the other powers of 2
            for (int j = 0; j < r - 1; j++) {
                x = (x * x) % n; // Square x

                if (x == n - 1) { // If x becomes n-1, the number is probably prime
                    composite = false; // It is not composite
                    break;
                }
            }

            // If the number is composite, return false
            if (composite) return false;
        }
        return true; //  n is prime
    }

    // Function to check if the whole number represented by the linked list is prime
    bool isWholeNumberPrime() {
        Node* current = head;
        // Variable to store the reconstructed number
        uint64_t n = 0;     
        uint64_t base = 1;   // Base for the reconstruction

        // Reconstructing the number from the linked list
        while (current) {
            n += current->data * base; // Combine chunks into the final number
            base <<= 64; // Shift base left by 64 bits for the next chunk
            current = current->next; // Move to the next node
        }

        // Check if n is prime
        return isPrime(n);
    }

    // Function to print the generated number by traversing through the linked list
    void printNumber() {
        Node* temp = head;
        cout << "Generated 1024-bit number: ";

        // Traverse the linked list and print each chunk
        while (temp) {
            cout << temp->data << " "; // Print each 64-bit chunk
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }

    // Function to free the memory allocated for the linked list
    void freeList() {
        Node* temp;

        // Free each node in the linked list
        while (head) {
            temp = head;     // Store the current head
            head = head->next; // Move the head to the next node
            delete temp;     // Free the current node
        }
    }

    // Function to print all prime numbers smaller than a given number
    void printSmallerPrimes(uint64_t limit) {
        cout << "Smaller primes less than " << limit << " are: ";

        // Iterate through numbers to check for primes
        for (uint64_t num = 2; num < limit; num++) {
            if (isPrime(num)) {
                cout << num << " "; 
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness
    // Create a linked list object
    LinkedList list; 
    // Generate a random 1024-bit number

    list.generateRandomNumber();
    // Output: Print the generated number
    list.printNumber();

    // Check if the whole number is prime
    if (list.isWholeNumberPrime()) {
        cout << "The entire 1024-bit number is prime." << endl;
    }
    else {
        cout << "The entire 1024-bit number is not prime." << endl;
    }
    //print small prime number
    list.printSmallerPrimes(100);

    // Free the linked list to avoid memory leaks
    list.freeList();

    return 0;
}
