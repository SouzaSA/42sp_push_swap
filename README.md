# PUSH SWAP
---

## Goal

In this project we have to sort, in ascending order, a stack, using a second stack, using a restrict group of instructions.

You begin with two stacks named **a** and **b**. The stack **a** contains a random number of either positive or negative numbers without any duplicates and the stack **b** is empty.

The set of instructions are:

| cmd | operation | description |
|------|----|--------------|
|**sa** | swap a | Swap the first 2 elements at the top of stack a.|
|**sb** | swap b | Swap the first 2 elements at the top of stack b..|
|**ss** | |sa and sb at the same time.|
|**pa** | push a | Take the first element at the top of b and put it at the top of a.|
|**pb** | push b | Take the first element at the top of a and put it at the top of b.|
|**ra** | rotate a | Shift up all elements of stack a by 1. The first element becomes the last one.|
|**rb** | rotate b | Shift up all elements of stack b by 1. The first element becomes the last one.|
|**rr** | rotate both | ra and rb at the same time|
|**rra** | reverse rotate a | Shift down all elements of stack a by 1. The last element becomes the first one.|
|**rrb** | reverse rotate b | Shift down all elements of stack b by 1. The last element becomes the first one.|
|**rrr**  | reverse rotate both | rra and rrb at the same time.|

## Implementation approach.

### Arguments checks.

First, it is necessary to verify that the received arguments are all valid, then it is necessary to verify that each argument contains only digits or signs and that there is only one copy of the number in the argument array.

Initially was changed all "isspace" characters, form-feed ('\f'), newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and vertical tab ('\v'), to a simple space chars, after this the values are splitted using the space as spliter character, and every element are checked if he only contais digits or signals, if its is true the element, that is a string, is converted to an int, where is checked if its is inside the int range of values, ortherwise if there is a non digit element or if the number is out of range the program clean the memory  and exit with error message.

With all numbers converted, they are checked if there is duplicated values, if it exists clean memory and exit with the error message.

If no invalid situation was found the algorithm checks if the stack are sorted, if it was the program exits with no message, otherwise he keep de procedure to sort.

### Reverse sorted stack.

If the stack are reverse sorted and its bigger than four, the stack a are rotate three times to send the bigger values to bottom, after this all other values are pushed to stack b, at this point there is only three elements in stack a.

After this swap first element of all stacks, so stack a are partially sorted, and stack b are inverse sorted exepted first two elements, at this point reverse rotate and push the top element until remain two elements, that only are pushed to stack a, because they are swaped at first movement.

### Size three stack

With size three stack, take the center element, the center element is the median value in the stack, and check its position. If its in the top of stack, check if the base element is greater than the middle element, if true a swap will already order the stack, otherwise a reverse rotate will do the work.

If the center elment is in the middle of stack, the stak is in inverse order, so to be ordered it must be rotate one time and swaped. The last option is the center element is in the bottom of stack, so if the top element is smaller than the middle one, to be sorted the stack must be swaped and rotated, otherwise a single rotate will sort.

### Size four stack

The stack with size four, the smallest value is bring to top and then send to stack b, then the stack a will be sorted by sort three function and then the value is pusshed back to stack a again. For this if the smallest value index is bigger than midde the stack (two because the stack is size four) the smallest value will be bring to the top by rotations, otherwise reverse rotations.

### The pivot.

Maybe the most important element of the code, so lets see wath it's does, it has the responsability of return the median element of an array, ie the element in the middle of an sorted array.

The function that is responsible for obtaining this value is a modified function, where the modification is related to the stopping point, where the size of half of the vector is passed as one of the arguments, with this value the algorithm can be stopped prematurely, but already with the median value, as there is no interest in a complete ordering.

### Stack of size five or six.

To sort this, we obtain a pivot to stack a and a pivot to stack b, both of then by the stack a, but changing the last argument of the function which get the pivot, the pivot for a is get passing half of stack size, and pivot b is using one, because the stack has size five or six, a half of a half of this is one. (the size of stack b  will be a half of the size of the stack a)

After getting the pivot all values less than it are pushed to stack b, then final stack a now has three elements and stack b has three or two elements depending on the original size of stack a. With this size of stacks its easy to order.

### Bigger stacks

To sort larger stacks the approach adopted was a modification of the quick sort algorithm, thus obtaining the pivot of stack a and passing half of the values to stack b recursively while stack a is greater than three.

Each element of this execution stack has a block half the block size of the preceding element, and each of these blocks contains values greater than the block values of the preceding element.

After reaching the recursion stop criterion, we have stack a with two or three elements and the others in stack b, at this point the pivot of the current block is determined and the values greater than the pivot are sent back to the stack a as long as the block size is greater than three. upon reaching this criterion, these values are sorted and returned to stack a.

This process repeats until all elements are sorted.

# Important Links.
1. [A fabulous tester made by Lais Arena](https://github.com/laisarena/push_swap_tester)
1. [A graphic visualizer made by Emmanuel Ruaud](https://github.com/o-reo/push_swap_visualizer)
