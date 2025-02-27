# ❤️ Cupidash - 42 Campus Dash 💻  

This repository contains the solution for **Cupidash**, one of the Dashes at **42** campus.  

## ❓ What is Cupidash?  

Cupidash is a small ⚡ challenge that requires drawing a heart-like shape using **C**. The program receives a single numeric argument, which determines the number of lines up to the widest part of the shape (inclusive). Any additional arguments are ignored or handled as errors.  

## 🛠️ How does it work?  

1. **Input Handling**: The program expects a single numerical argument and deduces the number of lines up to the widest section. If incorrect input is given, it handles errors appropriately.  

2. **Special Case (n = 1)**: The smallest valid input has a special handling case.  

3. **First Half Construction**:  
   - The first half of the shape is built using a structured approach.  
   - It calculates the required number of lines up to the midpoint and iterates over them.  
   - Each line consists of three sections:  
     - **Left Spaces**: Equal to the remaining lines until the midpoint.  
     - **Left `*` Section**: Starts at 2 stars and increases by 2 each iteration.  
     - **Central Space**: Defined as `1 + 2 * (n - 2)`, decreasing by 2 per line.  
     - **Right `*` Section**: Mirrors the left side.  

4. **Second Half Construction**:  
   - Writes a row of `*` characters, with a width of `n * 4 - 1`.  
   - Iterates, reducing `n` by 2 per step.  
   - Increases left spaces by 1 on each iteration until `n <= 0`.
