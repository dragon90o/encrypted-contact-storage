# encrypted-contact-storage
# Contact Management Program

## Overview:
This program allows users to manage contact information securely. It supports adding new contacts, saving their details to a file, and encrypting the contact file to protect sensitive data.

## Features:
- **Contact Creation**: The program lets users add a contact by entering details such as name, alias (nickname), phone number, birthday, country code, and comments.
- **Zodiac Sign**: Based on the contact's birthday, the program determines the user's zodiac sign.
- **Age Calculation**: The program calculates the age of the contact based on the birthdate.
- **Country Detection**: The program detects the country of the contact based on the phone number's country code.
- **File Management**: Contact details are saved in a file (`xontacts.txt`). If the file doesn't exist, it is created.
- **Nickname Management**: Users can check if a nickname already exists in the file. If it doesn't, it is added.
- **File Encryption**: The contact file is encrypted using AES-256-CBC encryption to ensure security. The user must enter a password for encryption and decryption.

## How It Works:
1. **Create or Open Encrypted File**: If the file `xontacts.txt` exists, the program will ask for a password to decrypt it. If the file doesn't exist, a new file will be created and encrypted with a password.
2. **Add Contact**: The user can add a contact by providing the following details:
   - Name
   - Alias (nickname)
   - Phone number with a country code
   - Birthday (day, month, year)
   - Comment
3. **Data Validation**: The program checks if the phone number is valid. It ensures that the number has between 5 and 11 digits and contains only digits.
4. **Save Contact**: The contact details are saved to the file, ensuring no duplicates for names or nicknames.
5. **Encrypt File**: After saving the contact, the file is encrypted using the AES-256-CBC encryption method, and the original file is replaced with the encrypted version.

## How to Use:
1. Compile and run the program.
2. If the file `xontacts.txt` exists, provide a password to decrypt it.
3. If the file doesn't exist, enter a new password to create and encrypt the file.
4. Follow the prompts to enter the contact details.
5. The contact's information is displayed and saved to the file securely.
6. The file is encrypted again after saving the contact.

## Notes:
- The program handles different country codes and provides the country name based on the phone number's prefix.
- The program ensures that nicknames are unique and prevents duplicates in the saved file.
- The file is encrypted and replaced with the encrypted version after each contact is saved.

This program is ideal for securely managing contact information and encrypting the data for privacy.
