Sorting algorithms used for each bucket included functions createNode, bubbleSort and swap.

In the main class, the program asks for user input inside an infinite loop. In case the input is equal to EOF, the program breaks out of the loop and proceeds to sort each bucket inside the list and print them ordered. A switch case compares the first character of the input and inserts them in the end of the bucket list’s assigned bucket. 

The function createNode creates a new node and inserts it in the end of the bucket’s linked list. It takes a node, a string and an integer as its parameters. The node will be allocated memory, the string is the node’s string and the index is the index inside the bucket list the node will be added to. If the list of that index is empty, the list’s head becomes the new node. Otherwise the list’s final element will point to that node.

bubbleSort is simply a bubble sorting function that uses strcmp to compare two strings’ the current node’s and the next one’s. if strcmp is greater than 0, it swaps the two nodes’ data by accessing function swap.

swap is a function that takes two nodes and swaps their string data.

The program prints the data by sorting each linked list inside the list of buckets, then print each word inside of that linked list in case it exists.

The bubble sorting and swap functions were partially implemented by me. Everything else that was not previously suggested in the assignment’s specs was entirely implemented by me including the createNode function, the switch case and the output parts.