<b>Questions are from Leetcode.com


<b><h1>Files Summary </h1><b>


<b><br>Image_overlap.cpp</br></b>
  
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.

<br>***************************************************************************<br>

<b><br>maximal_square.cpp</br></b>
<br>
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

[1 0 1 0 0]
[1 0 1 1 1]
[1 1 1 1 1]
[1 0 0 1 0]

Output: 4

<br>***************************************************************************<br>

<b><br> Reordered_Power_of_2.cpp</br></b>
<br>
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false

<br>***************************************************************************<br>

<b><br> tilt_tree.cpp</br></b>
<br>
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

<br>***************************************************************************<br>

<b><br> diameter_binary_tree.cpp</br></b>
<br>

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree <b>
    1<b>
   / \<b>
  2   3<b>
 / \<b>     
4   5<b>    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

