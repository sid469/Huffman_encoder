# Huffman_encoder

Huffman Coding has applications in data compression, as it represents more frequent characters in a text using fewer bits.
-------------------------------------------------------------------------------
INTRODUCTION:-
-------------------------------------------------------------------------------
Our goal is to write C++ classes/functions that implement Huffman Coding tasks like generating a frequency table, constructing a Huffman Tree, and providing character encodings as well as decodings. The encoder maps each distinct character in the input to a unique codeword (a sequence of bits) based on its frequency, with more frequent characters getting mapped to shorter codewords. Let C denote the number of distinct characters in the input text. Then the collection of C codewords is called the codebook. We are representing the Huffman tree in Newick format to enable conversions between tree structures and the codebook. Note that a prefix code is an encoding under which no codeword is a prefix of any other codeword in the codebook.
Huffman code is a prefix code

-------------------------------------------------------------------------------
Background: Huffman (Tree Construction) Algorithm, Optimal Prefix Code, and Tie-Breaking Rule
-------------------------------------------------------------------------------
A binary tree with all C characters at its leaves can be used to derive a (prefix code’s) codebook as follows. The codeword of each character ci at a leaf is found by starting from the root, and recording the path to the leaf, using a 0 for indicating a left branch and 1 for a right branch. Please see figure below for illustration. The cost of the code is given by summation of di*fi over all codewords , where di is the depth of the leaf with character ci in the binary tree (i.e., length of the codeword for ci ) and fi is the number of occurrences (frequency) of ci in the input text.

To minimize the lenght of a text which has the character frequency close the taken input we need to find a tree which minimizes the cost of the code(defined above).
