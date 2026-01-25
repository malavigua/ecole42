# Push_swap

*This project was created as part of the 42 curriculum by malmany.*

---

## 📌 Description

The goal of this project is to sort a stack of integers in **ascending order** using a limited set of operations, while producing the **smallest possible number of moves**.

The program manipulates two stacks:
- **stack A**: contains the numbers to be sorted
- **stack B**: used as auxiliary storage

Only specific operations are allowed to move and rearrange elements between the stacks.

### 🔁 Allowed Operations

#### Swap
- `sa` : swap the first two elements of **stack A**
- `sb` : swap the first two elements of **stack B**
- `ss` : `sa` and `sb` at the same time

#### Push
- `pa` : push the top element from **stack B** to **stack A**
- `pb` : push the top element from **stack A** to **stack B**

#### Rotate
- `ra` : rotate **stack A** upward (first element becomes last)
- `rb` : rotate **stack B** upward
- `rr` : `ra` and `rb` at the same time

#### Reverse rotate
- `rra` : rotate **stack A** downward (last element becomes first)
- `rrb` : rotate **stack B** downward
- `rrr` : `rra` and `rrb` at the same time

### 🧠 Algorithm — Turk Algorithm

This project uses the **Turk algorithm**, a cost-based strategy optimized to reduce the total number of operations.

#### Special cases

- **Already sorted**  
  → Do nothing.

- **Two elements**  
  → Perform a single `sa` if needed.

- **Three elements**  
  → Use a dedicated algorithm:
  - If the **maximum element is first** → `ra`
  - If the **maximum element is second** → `rra`
  - If the stack is still not sorted → `sa`

#### General case (more than 3 elements)

1. **Initial pushes to stack B**
   - Push the first element from **A** to **B**
   - If stack A is still not sorted and contains more than 3 elements, push a second element
   - Continue pushing elements from **A** to **B** by always selecting the **cheapest element** (i.e. the one with the **lowest calculated cost**) until only **3 elements remain in A**


2. **Cost evaluation**
   For each element in **stack A**:
   - Define a **target node in stack B**
     - The target is the **largest of the smaller elements**
     - If none exists, the target is the **maximum element in B**
   - Calculate the **cost**, which is the **sum of**:
     - The number of operations needed to bring the element to the top of **stack A**
     - The number of operations needed to bring its target to the top of **stack B**

3. **Choosing the cheapest move**
   - The element with the **lowest total cost** is marked as the *cheapest*
   - If both the element and its target are:
     - **Above the median** → use `rr`
     - **Below the median** → use `rrr`
   - Otherwise:
     - Rotate or reverse rotate each stack independently until both nodes are on top

4. **Push to stack B**
   - Execute `pb`
   - Repeat the process until only **3 elements remain in stack A**

#### Final sorting

1. **Sort the remaining 3 elements in stack A**
   - Using the dedicated 3-elements algorithm

2. **Push elements back from B to A**
   - For each element in **B**:
     - Define its target in **A** as the **smallest of the larger elements**
     - Rotate or reverse rotate **A** depending on the target’s position relative to the median
     - Execute `pa`
   - Repeat until **stack B is empty**

3. **Final adjustment**
   - Bring the **minimum element** of stack A to the top
   - Use `ra` or `rra` depending on its position relative to the median

This strategy ensures efficient sorting by always selecting the move with the **lowest possible cost**, making it especially effective for large inputs.

---

## ⚙️ Instructions

### 🔹 Mandatory part

1. Compile the program

   ```bash
      make
   ```
   This command generates the executable `./pushswap`.

2. Run push_swap

   ```bash
      ./pushswap
   ```
   

   If executed without arguments, the program does nothing.
   
   If arguments are provided, the program sorts them and prints the list of operations
   (sa, ra, pb, etc.) needed to sort stack A in ascending order.

3. Arguments format

   Numbers can be passed:

   - `Directly`
   ```bash
      ./pushswap 2 4 5
   ```
   - `As a single string`
   ```bash
     ./pushswap "2 4 5"
   ```
   - `Using a variable`
   ```bash
     ARG="1 4 5"; ./pushswap $ARG
   ```
   - `With random values`
   ```bash
     ARG="$(shuf -n 100 -i 0-99 | tr '\n' ' ')"; ./pushswap $ARG
   ```
4. Error handling

   The program displays `Error` if:

   - An argument is not a number
   - There are duplicate numbers
   - A value is outside the integer range

### ⭐ Bonus part (checker)

1. Compile the bonus program
   ```bash
     make bonus
   ```
2. Run checker
   ```bash
   ./checker 3 2 1
   ```
   Enter operations manually (sa, ra, pb, etc.) or use a pipe with the result of `./pushswap`.

   Press Ctrl + D to send EOF.

   Result:
   - Stack A is sorted and stack B is empty → OK
   - Otherwise → KO

3. Pipe usage

   - ```bash
       ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
     ```
   - ```bash
       ARG="$(shuf -n 100 -i 0-99 | tr '\n' ' ')"; ./push_swap $ARG | ./checker $ARG
     ```

4. Error handling (checker)

   - If the initial arguments contain invalid values or duplicates,
     `Error` is displayed and the program stops
   - If the command entered is not valid (pa, pb, ra, etc.),
     `Error` is displayed and the program stops

### 🛠 Makefile rules

- make        : compiles push_swap
- make bonus  : compiles checker
- make clean  : removes object files (.o)
- make fclean : removes object files and executables
- make re     : executes fclean then recompiles push_swap

---

## 📚 Resources / References

YouTube tutorials: search "42 push_swap Turk algorithm"
