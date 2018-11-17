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

<br>***************************************************************************<br>

<b><br> Symmetric_Tree_recursive.cpp</br></b>
<br>

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

<br>***************************************************************************<br>

<b><br> Binary_Tree_Level_Order_Traversal_store_in_multidimensional_array.cpp</br></b>
<br>

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

<br>***************************************************************************<br>

<b><br> min_depth_binary_tree_recursive.cpp </br></b>
<br>

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

<br>***************************************************************************<br>

<b><br>intersection_of_Two_Arrays.cpp</br></b>
<br>
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.


<br>***************************************************************************<br>

<b><br>LRU_Cache.cpp</br></b>
<br>
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
