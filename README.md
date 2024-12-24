
---

### **How to Use the Contact Manager Program**

The **Contact Manager Program** allows users to add, store, and manage contact information securely. It saves data in an encrypted file and includes features like phone number validation, zodiac sign calculation, and age calculation.

---

### **Prerequisites:**

Before running the program, ensure you have the following installed on your system:

1. **g++ (GNU Compiler for C++):**
   - This is required to compile the C++ code.
   - **Installation:**
     - **Linux:** Run `sudo apt install g++`
     - **Mac:** Use `brew install gcc` (if you have Homebrew installed)
     - **Windows:** Install MinGW or a similar C++ compiler.

2. **OpenSSL:**
   - This is used for file encryption and decryption.
   - **Installation:**
     - **Linux:** Run `sudo apt install openssl`
     - **Mac:** OpenSSL comes pre-installed on most macOS systems. If not, install with `brew install openssl`
     - **Windows:** Download and install OpenSSL from [OpenSSL for Windows](https://slproweb.com/products/Win32OpenSSL.html)

---

### **Steps to Download, Compile, and Run the Program:**

#### **Step 1: Download the Source Code**
- Download the `contact_manager.cpp` file (either from GitHub or another location where it is hosted).

#### **Step 2: Compile the Program**

To compile the code, open your terminal and navigate to the folder where the `contact_manager.cpp` file is located. Then, run the following command:

```bash
g++ contact_manager.cpp -o contact_manager
```

This will create an executable file called `contact_manager` (on Linux/Mac) or `contact_manager.exe` (on Windows).

#### **Step 3: Run the Program**

Once the program is compiled, run the following command in the terminal:

```bash
./contact_manager
```

If you're on **Windows**, you can run:

```bash
contact_manager.exe
```

The program will start, and you'll be prompted to input contact information.
 
---

### **Program Features and Explanation:**
 
1. **Add Contact Information:**
   - You will be asked to input:
     - Name
     - Nickname
     - Phone number (with country code)
     - Date of birth (day, month, year)
     - Additional comments
   - The program will validate the phone number to ensure it meets the correct format.

2. **Zodiac Sign and Age Calculation:**
   - Based on the contact's birthdate, the program will calculate their zodiac sign and age.
  
3. **File Encryption:**
   - The contact information is saved in an encrypted text file (`xontacts.txt`).
   - **Password Protection:** The file is encrypted with AES-256 encryption. You will need a password to encrypt or decrypt the file.
     - If the file already exists, you will be prompted to enter the password to decrypt it.
     - If the file does not exist, you will create a new password to encrypt the file.

4. **Save Data:**
   - The contact data is saved to the `xontacts.txt` file. If the contact already exists, it will not be added again.

5. **File Decryption:**
   - When opening the file in the future, you will need the password to decrypt it. The program will ask for the password when you run it.
   -
   in order to see your file :
   - Openssl enc -d -aes-256-cbc -pbkdf2 -in xontacts.txt -pass pass: Yourcode
 
---

### **Important Notes:**
 
- **Encrypted File:** The contact information is stored in an encrypted format to protect privacy.
- **Nickname Validation:** The program checks if a nickname already exists in a file (`nicknames.txt`). If it does, it prevents adding the same nickname again.
- **Country Information:** The program can map phone numbers to their respective countries based on the country code.

---

### **Example:**
 
1. **Running the program:**
   - After starting the program, you'll be prompted to enter your password if the contact file already exists. If it doesn't exist, you'll be asked to create a new password.

2. **Input contact details:**
   - Name: John Doe
   - Nickname: Johnny
   - Phone Number: +1 1234567890
   - Birthdate: 15/6/1990
   - Comment: Close friend

3. **Output:**
   - The program calculates the zodiac sign, age, and saves the contact information to the encrypted file `xontacts.txt`.

---

### **Conclusion:**

By following these steps, you will be able to manage contacts securely with encryption, validating phone numbers, and calculating the zodiac sign and age. The program ensures that sensitive data is protected by encrypting the contact information file.

Let me know if you need further clarification or assistance!i handles different country codes and provides the country name based on the phone number's prefix.
- The program ensures that nicknames are unique and prevents duplicates in the saved file.
- The file is encrypted and replaced with the encrypted version after each contact is saved.

Thg++ contact_manager.cpp -o contact_manageris program is ideal for securely managing contact information and encrypting the data for privacy
