=================================================================================
+                            Text based search engine                           +
=================================================================================
                       mmm  mmmmm          mmmm m     m
                     m"   " #   "#  m""#m "   "# "m m" 
                     #      #mmmm" #  mm#     m"  "#"  
                     #      #   "m # #  #   m"     #   
                      "mmm" #    " #m """ m#mmmm   #   
                                    "mmm               
                
                    Developed by : Shubham Hibare (CR@2Y)
                    website      : http://hibare.in
                    Linkedin     : https://linkedin.com/in/hibare
                    Github       : https://hibare.github.io
                    License      : MIT License
=================================================================================

It is a text based search engine witten in C language. Unlike Google it is a mini search engine which searches for a given word or a pair of words in a set of text files.

Input: input to the program is the name of the directory which contains all the text files to be searched. The location of this directory should be one level above the directory containing the source files.

Output: output of the program is the name of the files which contain the given word (or given pair of word).

Processing: Program takes input the name of the directory containing the text files. Program then scans the directory and list the name of all the text files found along eith the total number of text files found.

After successfully scanning the directory, the program open's each file, read it contents and store them in a suitable data structure.

The data structure used in this program is the combination of singly linke list and the binary search tree. Each node in the singly list denotes a text file. Each node is associated with a binary search tree which contains all the words present in that file that the node represent.

The process of searching is provided in three ways:
1. simple word search
2. AND logic search, and
3. OR logic search

simple word search takes a single word as input and search for the occurrence of this word in the text files.

AND logic search takes a pair of words as input and search for the occurrence of both the words in the text file.

OR logic search also takes a pair of words as input and search for the occurrence of any one of word in the text file.

How to use it?
This program works on both Windows and Linux. Before starting execution please ensure that you have neccessary C compiler installed on your system. If not please install it.

Now clone the repository, copy all the text files to the directory text, compile search.c file and execute it. Follow on screen options to proceed further.

Disclaimer: Author of this script is not responsible for any damage caused to your system from using this script. Use this script at your own risk.

Note: For any errors and queries contact from here- http://hibare.in.
