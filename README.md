**Shortest Sub-segment**

Given a paragraph of text, and a list of k words, write a program to find the first shortest sub-segment that contains each of the given k words at least once. The length of a segment is the number of words included; a segment is said to be shorter than another if it contains less words than the other structure. 
* 

- Ignore characters other than [a-z][A-Z] in the text.
- Comparison between the strings should be case-insensitive.

*Input format:*<br>
The first line of the input contains the text. 
The next line contains k, the number of  words given to be searched.
Each of the next k lines contains a word.

*Output format:*<br>
Print first shortest sub-segment that contains given k words , ignore special characters, numbers.<br>
If no sub-segment is found it should return “NO SUBSEGMENT FOUND”

*Sample Input:*<br>
``This is a test. This is a programming test. This is a programming test in any language.
4
this
a
test
programming``

*Sample Output:*<br>
a programming test This
*Explanation:*<br>
In this test case segment "a programming test. This" contains given four words. You have to print without special characters, numbers so output is "a programming test This".  Another segment "This is a programming test." also contains given  four words but have more number of words. 

*Constraints:*<br> 
Total number of characters in a paragraph will not be more than 200,000.
0 < k <= no. of words in paragraph.
0 < Each word length < 15