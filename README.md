# Huffman_encoder

Huffman Coding has applications in data compression, as it represents more frequent characters in a text using fewer bits.
-------------------------------------------------------------------------------
INTRODUCTION:-
-------------------------------------------------------------------------------
Our goal is to write C++ classes/functions that implement Huffman Coding tasks like generating a frequency table, constructing a Huffman Tree, and providing character encodings as well as decodings. The encoder maps each distinct character in the input to a unique codeword (a sequence of bits) based on its frequency, with more frequent characters getting mapped to shorter codewords. Let C denote the number of distinct characters in the input text. Then the collection of C codewords is called the codebook. We are representing the Huffman tree in Newick format to enable conversions between tree structures and the codebook. Note that a prefix code is an encoding under which no codeword is a prefix of any other codeword in the codebook.
Huffman code is a prefix code

-------------------------------------------------------------------------------
Background: Huffman (Tree Construction) Algorithm and Optimal Prefix Code
-------------------------------------------------------------------------------
A binary tree with all C characters at its leaves can be used to derive a (prefix code’s) codebook as follows. The codeword of each character ci at a leaf is found by starting from the root, and recording the path to the leaf, using a 0 for indicating a left branch and 1 for a right branch. Please see figure below for illustration. The cost of the code is given by summation of di*fi over all codewords , where di is the depth of the leaf with character ci in the binary tree (i.e., length of the codeword for ci ) and fi is the number of occurrences (frequency) of ci in the input text.

To minimize the lenght of a text which has the character frequency close the taken input we need to find a tree which minimizes the cost of the code(defined above).

*Here is a small description of my implementation of the algorithm* :-

The above binary tree based encoding yields a prefix code, and the prefix code with optimal
(minimum) cost can be obtained using the greedy Huffman algorithm as follows. Huffman algorithm maintains a forest of trees. The weight/frequency of a tree is equal to the sum of the frequencies of its leaves. In each of C − 1 iterations, select the two trees, T1 and T2, of smallest weight, breaking ties as mentioned below, and form a new tree with T1 and T2 as left and right subtrees. At the beginning of the algorithm, there are C single-node trees – one for each character, constructed in a lexicographic order (e.g., the single node for ‘a’ is constructed earlier than for ‘t‘). At the end of the algorithm, there is one tree, and this is the Huffman tree corresponding to the optimal prefix code.To break ties when two or more trees in the forest have the same weight, we choose the tree whose root was constructed earlier in the above algorithm. Also, T1 and T2, the trees in the forest with the two smallest weights in the above algorithm are merged such that – the tree with the lower of these two weights is set as the left subtree, and the other tree the right subtree of the merged tree (if both T1 and T2 has the same weight, the ties are again broken by setting the tree whose root was constructed earlier as the left subtree). 

*Here is a small description of expected input and output formats for each command* :-

Command 1: BuildFrequencyTable
-------------------------------
• Description: Construct a frequency table from an input string.
• Input:
      - A single string containing the text/message.
• Output: Each character and its frequency, space-separated, in lexicographical order, with
one row of the frequency table per line.

Sample Input:
------------
BuildFrequencyTable
ohelloo
Quit

Sample Output:
--------------
e 1
h 1
l 2
o 3


Command 2: BuildTreeFromFrequencyTable
---------------------------------------
• Description: Construct a Huffman Tree from a frequency table.\n
• Input:
      – Integer C, the number of rows in the frequency table.
      – Next C lines: Each line contains a character and its frequency, space-separated.
• Output: Print the constructed Huffman Tree in Newick format as a single line.

Sample Input:
-------------
BuildTreeFromFrequencyTable
4
e 1
h 1
l 2
o 3
Quit

Sample Output:
--------------
(o,(l,(e,h)));


Command 3: DeriveHuffmanTree
-----------------------------
• Description: Constructs a binary (Huffman) Tree consistent with a given codebook of a
prefix code.
• Input:
      – Integer C, the number of rows in the codebook of a prefix code.
      – Next C lines: Each line contains a character and its codeword, space-separated.
• Output: Newick-formatted binary (Huffman) tree reconstructed from the codebook.

Sample Input:
-------------
DeriveHuffmanTree
4
e 110
h 111
l 10
o 0
Quit

Sample Output:
--------------
(o,(l,(e,h)));


Command 2b: DecodeMessage
-------------------------
• Description: Decode a given binary message using a Huffman Tree, producing the original message string.
• Input:
      – A single string representing the Newick-formatted Huffman Tree.
      – Next line: A binary string representing the encoded message to be decoded.
• Output: Outputs the decoded message as a string in a single line.

Sample Input:
------------
DecodeMessage
(o,(l,(e,h)));
0111110101000
Quit

Sample Output:
--------------
ohelloo
