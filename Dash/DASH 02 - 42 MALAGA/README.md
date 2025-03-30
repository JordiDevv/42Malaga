# 🔠 Dash 02 - 42 Malaga 💻  

This repository contains the solution for the second dash at **42 Málaga**.  

## ❓ What it consists of?  

This is a ⚡ challenge that consists of **four exercises**, progressively increasing in difficulty. The final task is to count the occurrences of each letter in a given sentence using **C**, following the school's coding standards.  

## 🛠️ How does it work?  

### **Exercise Breakdown**  

1. **ft_star** – Print seven asterisks and a line break.
2. **occ_a** – Write a function that counts the instances of 'A' in a string given and returns it.
3. **count_alen** – Write a function that counts the lenght of a given string 'til the first 'a' instance.
4. **count_alpha** – Count the occurrences of each letter in a given string. 

### **Final Challenge: Letter Counting**  

- **Input Handling:** The program verifies that it receives exactly **one argument**, and that it is **not empty**. If these conditions are not met, it prints a newline and exits.  
- **Normalization:** The input string is converted to **lowercase** to ensure that uppercase and lowercase letters are counted as the same character.  
- **Iteration & Counting:** The program iterates through the string:  
  - If a letter is found, it checks whether it has already been processed.  
  - If it is the **first occurrence**, it counts all its instances in the string and prints the count followed by the letter.  
  - If there are more "first letters" to process, it prints ", " as a separator.  
- **Final Output:** The program prints a newline at the end.  

## 📏 Norme  

To ensure structured coding and best practices, the following rules must be followed:  

- **Allowed external functions:** Only `write`, and `printf` are permitted.
- **Functions per script:** A maximum of **five** functions per script.  
- **Lines per function:** Each function can have up to **25** lines.  
- **Variable declaration:** Declaring and assigning a value in the same line is not allowed.
- **Global variables** are not allowed.

These constraints ensure clean, efficient, and well-structured code while fostering creativity. 🚀
