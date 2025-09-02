#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Define the size of each character set
#define LOWERCASE_SIZE 26
#define UPPERCASE_SIZE 26
#define DIGIT_SIZE 10
#define SYMBOL_SIZE 32 //  ASCII symbols

// Computational Power
#define CPU_GUESSES_PER_SECOND 1000000000.0 // 1 billion guesses/sec
#define GPU_GUESSES_PER_SECOND 100000000000.0 // 100 billion guesses/sec
#define QUANTUM_OPERATIONS_PER_SECOND 1e12 // 1 quintillion guesses/sec (simplified theoretical estimate)

//Function protype
void print_time(double seconds);

// Main function to run the password strength checker.
int main(int argc, char *argv[]) 
{

    if (argc != 2)
    {
        printf("Usage : ./program [password] \n");
        exit(1);
    }

    int length = 0;
    float entropy = 0.0;
    int charset_size = 0;
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_symbol = 0;
    bool is_secure = true;

    // Input and initial checks
    printf("Password Checking Intialized\n");
    char *password = argv[1];

    length = strlen(password);

    if (length == 0) 
    {
        printf("Password cannot be empty.\n");
        return 0;
    }

    // Character type analysis
    for (int i = 0; i < length; i++) 
    {
        char c = password[i];
        if (islower(c)) 
        {
            has_lowercase = 1;
        } 
        else if (isupper(c)) 
        {
            has_uppercase = 1;
        } 
        else if (isdigit(c)) 
        {
            has_digit = 1;
        } 
        else if (ispunct(c))
        {
            has_symbol = 1;
        }
        else
        {
            return 1;
        }
    }

    // Character size calculation.
    if (has_lowercase) 
    {
        charset_size += LOWERCASE_SIZE;
    }
    if (has_uppercase) 
    {
        charset_size += UPPERCASE_SIZE;
    }
    if (has_digit) 
    {
        charset_size += DIGIT_SIZE;
    }
    if (has_symbol) 
    {
        charset_size += SYMBOL_SIZE;
    }

    // The formula is E = L * log2(R)
    // where E is entropy, L is length, and R is the size of the character set.
    entropy = length * log2(charset_size);

    // Output results
    printf("\n--- Password Analysis ---\n\n");
    printf("Password: %s\n", password);
    printf("Length: %d characters\n", length);
    printf("Character Sets Used: ");

    if (has_lowercase) 
    {
        printf("Lowercase letters are used.\n");
    }
    if (has_uppercase)
    {
        printf("\t\t     Uppercase letters are used\n");
    } 
    if (has_digit)
    {
        printf("\t\t     Numerical Digits are used\n");
    } 
    if (has_symbol) 
    {
        printf("\t\t     Special Symbols are used\n");
    }
    printf("Character Pool Size (R): %d\n", charset_size);
    printf("Entropy (E): %.2f bits\n", entropy);

    // Entropy Strength Assessment
    printf("\tStrength Rating: ");
    if (entropy < 40) 
    {
        printf("Very Weak\n");
    } 
    else if (entropy >= 40 && entropy < 60) 
    {
        printf("Weak\n");
    } 
    else if (entropy >= 60 && entropy < 80) 
    {
        printf("Good\t\n");
    } 
    else if (entropy >= 80 && entropy < 100) 
    {
        printf("Strong\t\n");
    } 
    else 
    {
        printf("Excellent\n");
    }

    // Time to Crack Calculation
    double total_possibilities = pow((double)charset_size, (double)length);

    printf("\n--- Estimated Time to Crack (Brute-Force) ---\n\n");
    printf("Total Possibilities: %.0f\n", total_possibilities);
    
    printf("Time to Crack (Traditional CPU): ");
    print_time(total_possibilities / CPU_GUESSES_PER_SECOND);

    printf("Time to Crack (Modern GPU): ");
    print_time(total_possibilities / GPU_GUESSES_PER_SECOND);

    printf("Time to Crack (Quantom Capability according to Grovers Algorithm): ");
    print_time(sqrt(total_possibilities) / QUANTUM_OPERATIONS_PER_SECOND);
    printf("\n");

    // Password improvement suggestions based on the user given input.
    printf("\n--- Password Improvement Suggestions ---\n\n");
    if (length < 12) 
    {
        printf("Increase password length to at least 12 characters.\n");
        is_secure = false;
    }
    if (!has_lowercase) 
    {
        printf("Add lowercase letters to increase complexity.\n");
        is_secure = false;
    }
    if (!has_uppercase) 
    {
        printf("Add uppercase letters to increase complexity.\n");
        is_secure = false;
    }
    if (!has_digit) 
    {
        printf("Add digits to increase complexity.\n");
        is_secure = false;
    }
    if (!has_symbol) 
    {
        printf("Add special symbols to increase complexity.\n");
        is_secure = false;
    }

    if(is_secure)
    {
        printf("Password is Secure\n")
    }
    
    return 0;
}

// Time duration analysis based on seconds.
void print_time(double seconds) 
{
    if (seconds < 60) 
    {
        printf("%.2f seconds\n", seconds);
    } 
    else if (seconds < 3600) 
    {
        printf("%.2f minutes\n", seconds / 60);
    } 
    else if (seconds < 86400) 
    {
        printf("%.2f hours\n", seconds / 3600);
    } 
    else if (seconds < 31536000) 
    {
        printf("%.2f days\n", seconds / 86400);
    } 
    else if (seconds < 3.1536e+11) 
    { // 10,000 years
        printf("%.2f years\n", seconds / 31536000);
    } 
    else 
    {
        printf("More than 10,000 years (effectively infinite)\n");
    }
}
