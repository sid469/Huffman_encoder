Readme for the evaluation script.

This example contains a lab with two questions (Q1, Q2).

Sample C++ programs, test cases, and expected outputs for both questions are included

Directory Structure:

.
├── Programs
│   ├── CS01B001_LAB2
│   │   ├── CS01B001_LAB2_Q1.cpp
│   │   └── CS01B001_LAB2_Q2.cpp
│   └── CS01B002_LAB2
│       ├── CS01B002_LAB2_Q1.cpp
│       └── CS01B002_LAB2_Q2.cpp
├── testcases
│   ├── Q1
│   │   ├── test1.in
│   │   └── test2.in
│   └── Q2
│       ├── test1.in
│       └── test2.in
├── expected_outputs
│   ├── Q1
│   │   ├── test1.out
│   │   └── test2.out
│   └── Q2
│       ├── test1.out
│       └── test2.out


## Usage Instructions:

— Prepare the Directory Structure:

1) Organize student programs in the Programs directory, with each student's solutions placed in a folder named with their roll number.
2) Store test cases and expected outputs in the testcases and expected_outputs directories, respectively, using a separate subdirectory for each question (Q1, Q2, etc.). The script dynamically sets the number of questions based on the number of subdirectories in the testcases directory.

— Set Time Limit:

1) If you want to apply a time limit to the execution of test cases, set the TIME_LIMIT variable to the desired number of seconds. If no time limit is needed, leave it empty.

— Run the Script:

1) Make the script executable with chmod +x evaluate.sh
2) Execute the script using ./evaluate.sh


The file generates two folders:
1) actual_outputs that contains actual outputs of each student for each question
2) results that contains results for each student and a csv file consolidating results for all students





