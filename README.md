<div id="top">

<!-- HEADER STYLE: CLASSIC -->
<p align="center">
  <img src="EntroPass.png" width="900" height="680">
</p>

<em>Password Strength Checker</em>

<!-- BADGES -->
<img src="https://img.shields.io/github/last-commit/OSInternals/EntroPass?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
<img src="https://img.shields.io/github/languages/top/OSInternals/EntroPass?style=flat&color=0080ff" alt="repo-top-language">
<img src="https://img.shields.io/github/languages/count/OSInternals/EntroPass?style=flat&color=0080ff" alt="repo-language-count">

<em>Built with C</em>

<img src="https://img.shields.io/badge/Markdown-000000.svg?style=flat&logo=Markdown&logoColor=white" alt="Markdown">
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">

</div>
<br>

---

EntroPass is a command-line tool written in C that evaluates password strength based on entropy and estimates the time required to crack the password using brute-force methods across different computational platforms (CPU, GPU, and quantum computing). It analyzes the character sets used in a password and provides a detailed report on its complexity and security.

## Features
- **Entropy Calculation**: Computes password entropy using the formula `E = L * log2(R)`, where `L` is the password length and `R` is the character set size.
- **Character Set Analysis**: Identifies the use of lowercase letters, uppercase letters, digits, and special symbols.
- **Strength Rating**: Categorizes password strength as Very Weak, Weak, Good, Strong, or Excellent based on entropy.
- **Crack Time Estimation**: Estimates brute-force cracking time for traditional CPUs, modern GPUs, and theoretical quantum computers (using Grover's algorithm for quantum estimation).
- **User-Friendly Output**: Provides a detailed analysis of the password, including length, character sets used, entropy, and estimated cracking times.

## Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/OSInternals/EntroPass.git
   cd EntroPass
   ```
2. **Compile the Code**:
   Ensure you have a C compiler (e.g., `gcc`) installed.
   ```bash
   gcc -o entropass entropass.c -lm
   ```
   Note: The `-lm` flag links the math library for `log2` and `pow` functions.

3. **Run the Tool**:
   ```bash
   ./entropass <password>
   ```

## Usage
Run EntroPass by providing a password as a command-line argument:
```bash
./entropass MyP@ssw0rd
```

### Example Output
```plaintext
Password Checking Initialized

--- Password Analysis ---
Password: MyP@ssw0rd
Length: 10 characters
Character Sets Used: Lowercase letters are used.
                     Uppercase letters are used
                     Numerical Digits are used
                     Special Symbols are used
Character Pool Size (R): 94
Entropy (E): 65.74 bits
        Strength Rating: Good

--- Estimated Time to Crack (Brute-Force) ---
Total Possibilities: 57262297369379584
Time to Crack (Traditional CPU): 1816.88 years
Time to Crack (Modern GPU): 18.17 years
Time to Crack (Quantum Capability according to Grover's Algorithm): 0.00 seconds
```

## How It Works
1. **Input Validation**: Checks if a single password is provided as a command-line argument.
2. **Character Set Detection**: Analyzes the password for lowercase, uppercase, digits, and symbols, calculating the total character pool size.
3. **Entropy Calculation**: Uses the formula `E = L * log2(R)` to compute entropy, where:
   - `L` is the password length.
   - `R` is the size of the character set (e.g., 26 for lowercase, 26 for uppercase, 10 for digits, 32 for symbols).
4. **Strength Assessment**: Rates the password based on entropy thresholds:
   - < 40 bits: Very Weak
   - 40–59 bits: Weak
   - 60–79 bits: Good
   - 80–99 bits: Strong
   - ≥ 100 bits: Excellent
5. **Crack Time Estimation**:
   - Calculates total possible combinations (`R^L`).
   - Estimates cracking time for:
    

6. **System**
     - **Traditional CPU**: Assumes 1 billion guesses per second. 
     - **Modern GPU**: Assumes 100 billion guesses per second. 
     - **Quantum Computer**: Uses Grover's algorithm, estimating time based on the square root of possibilities divided by 1 quintillion operations per second. 
     
7. **Time Formatting**: Converts raw seconds into human-readable units (seconds, minutes, hours, days, years, or "effectively infinite" for >10,000 years).

## Dependencies
- **C Standard Library**: For string manipulation, input/output, and math functions.
- **Math Library**: For `log2` and `pow` functions (linked with `-lm` during compilation).

## Building and Running
### Prerequisites
- A C compiler (e.g., `gcc`, `clang`).
- A system with the C standard library and math library installed.

### Build
```bash
gcc -o entropass entropass.c -lm
```

### Run
```bash
./entropass <your_password>
```

## Limitations
- **Character Set Size**: Assumes a fixed symbol set size (32 symbols). This may vary depending on the specific symbols allowed in a system.
- **Quantum Estimation**: Simplified model based on Grover's algorithm; actual quantum cracking capabilities depend on hardware and algorithms not fully modeled here.
- **No Dictionary Attack Consideration**: The tool assumes brute-force attacks and does not account for dictionary or hybrid attacks.
- **Single Password Input**: Only one password can be analyzed per execution.
- **Character Limitation**: 36 Chracters are allowed as password.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

Please ensure your code follows the existing style and includes appropriate documentation.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Uses standard entropy calculation methods for password strength assessment.
- Quantum computing estimates based on theoretical models of Grover's algorithm.
