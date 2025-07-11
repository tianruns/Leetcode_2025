# Leetcode_2025
## 2025-05-14
### Array
Array: several variables with same type is saved on consecutive memory storage.
### 704 Binary search
Since the array is sorted with no duplicate elements, by comparing with the middle of the interval, we can make sure if the target is in the left part, or right part.

1. Clear defination of interval ranges. Either [left,right] or [left,right)
2. The ending point of the internal search loop.

For [left,right] type of interval defination, it is divided into [left, middle-1] and [middle+1, right]. Since nums[right] is accessible, it is possible that left == right. Loops end when left > right.

For [left,right) type of interval defination, it is divided into [left, middle) and [middle+1, right). Since nums[right] is not accessible, Loops end when left ==s right.

### 27 Remove element
#### Brute force
Loop the array, if the element == target, move the following arrays one index ahead. size of array minus 1.

#### Two pointer(left & right)
1. Left pointer start from 0, right pointer start at end.
2. If left doesn't reach target value, left continue move.
3. If left reaches target value, swap(left,right), right move backwards.
4. End the loop when left > right -> no more swap needed.

Left counts the number of element not equals to target. Right puts everyone target element to the end of array.
s
#### Two pointer (slow & fast)
1. fast and slow start together from 0. Loop on fast pointer.
2. If slow pointer doesn't reach target value, slow continues moving
3. If slow pointer reaches target value, slow pointer stops until fast pointer reaches a non target value. When both condition reaches, swap(slow, fast). slow continues move.

Fast loops the entire array. Slow always stops at target value. Swap(slow, fast) moves all non target element to the front. 

### 977 Square of sorted array
Two important condition:
1. The input array is sorted.
2. The size of input array and output array are same. -> 

Method
1. Left start from 0, right start from the end.
2. Loop the result vector from end to start.
3. If left*left is bigger, put the larger square value in the vector, left++
4. if right*right is bigger, put the larger square value in the vector, right--



## 2025-05-15
### 209 Minimum size subarray sum
Difficult part:
1. Condition to move the interval, especailly the left side
2. Ensure the minimum length of subarray is kept in memory

Main points

1. Continue to move the right interval -> increase the size of sub array
2. When sum reaches the target, move the left interval -> decrease the size of subarray

### 59 Spiral matrix 2
Diffucult part:
1. What loop order should be followed, the order of matrix, or order of increase value
2. How to split the condition/interval

Main points:
1. CLear define the four movements
2. COnsider the layer/loop

### Interval sum
Difficult part:
1. How to handle input and output
2. Introduce the new defination: array of sum interval  


### Buy land
Similar to interval sum. 


## 2025-05-16

### 203 Remove Linked List Element
Point:
1. If the following code needs to be deleted, current node points to node after next node.
2. Otherwise, move current node forward.
3. Dummynode is helpful to deal with empty list or list begin with target value.

### 707 Designed linked list
Point:
1. Virtual head node: _dummyNode is very helpful for special case
2. Void type function should "return ;"
3. new LinkNode(val) return LinkNode*

### 206 Reverse Linked List
Point:
1. The order of change is most important. 
2. First, create temp = curr->next. Then, current node points to previous node. Last, update: move previous and current node one step forward.

## 2025-05-17

### 24 Swap Nodes in Pairs
Point:
Virtual head node: _dummyNode is very helpful to continue the loop.

1->2->3->4 to 2->1->3->4: we need 2 step
1. '2' points to '1'
2. '1' points to '3'

But 2->1->3->4 to 2->1->4->3: we need 3 step at least
1. '1' points to '4'
2. '4' points to '3'
3. '3' stops pointing to '4', points to next node or nullptr.

Adding a virtual node in the begining makes the loop work perfectly

We can not delete object on stack memory directly, but only the object defined on heap memory. And we get a pointer to the object when it is created on heap memory. So we use "delete pointer" to release the memory. 

Also, after release the memory, the behavior of the pointer is unpredictable, we need to initialize it to nullptr for safety and future use.

### 19 Remove Nth node from end of list

First thought:
1. First loop to calculate the size of list
2. Remove the (size - Nth + 1)th node

To do it in one pass, two pointer method is good.

Nth node from end of list means: if one pointer is in the end of list, the node needs to delete is (N - 1) step away from it.

1. Create fast and slow pointer, slow pointer can start from virtual node
2. For fast pointer, continue moving it until reaching end of list
3. For slow pointer, start moving it when there is N step distance.
4. Virtual node can handle List with one node only.

### 160 Intersection of Two Linked List
Difficult point:
How to use only O(1) memory to solve this issue. We know the linked lists are same after the intersection node. 

Way of thinking:
1. If there is a intersection node, two pointer shall point to one same node, intersection node, when they have same length.
2. For cases the lengths are different, we can move the long list firstly to compensate the length difference.

Better method:
1. listA.size() = a + common; ListB.size() = b + common;
2. If a point start from (head of A to end of A) + (head of B to intersection point) d1 = a + common + b
3. If b point start (from head of B to end of B) + (head of B to intersection point)
d2 = b + common + a
4. Since d1 == d2, a and b point shall meet when there is a intersection point

### 142 Linked List Cycle 
Initial thoughts:
1. Use two pointers, fast point moves two steps and slow point moves one step each time.
2. When it is a list with circle, fast and slow point point shall meet each other. Otherwise, fast point shall reach the end of list.
3. Assum fast point takes a steps and slow point takes b steps. Two conditions shall be reached. a = 2 * b; And a = b + n * circle.size, n > 1;
4. As a result, b = n * circle.size. 
5. Assume the circle begin node at c index. (b - c) + c = (n - 1) * circle + circle = (n - 1) * circle + [circle - (b -c)] + (b - c);
6. c = (n - 1) * circle + [circle - (b -c)], which means, when one point starts from the head of list, another point starts from the point where slow and fast point meet, these two points shall meet at the point where circle begins.
7. When both fast and slow are in the circle, fast approach slow one step each time. So fast will meet slow within one circle.

## 2025-05-19
### 242 Valid Anagram
1. Initialize array int a[5] = {0};
2. Hash function: transfer the charactor into index of hash table. Easier to check if the character within the table.

### 349 Intersection of Two Array
Learn knowledge:
1. Initialize set: unordered_set<int> a(b.begin(), b.end());
2. Basic function: insert, emplace, erase, find and count.
3. unordered_set doesn't have duplicated key  

### 202 Happy Number
1. How to calculate the sum of each digit's square
2. Use set to check if the sum are in a loop circle.

### 1 Two Sum
1. Loop the array, if (target - nums[i]) is already in the map, return the result
2. Else, add nums[i] in the map

## 2025-05-20
### 383 Ransom note
1. Same problem as Valid Anagram
2. unordered_map<char, int>.find(i) return a pointer to the tuple <char, int>. char = find->first, int = find->second

### 454 FourSum2
Diffficult part:
1. Transfer problem "number of a + b + c + d = 0" into occurance problem 
2. How to formulate the hash map, how to select KEY and VALUE
3. How to add count number: 

### 15 3 sum
Diffiicult part:
1. Use 3 pointer loop the vector, not sure if some combination will miss
 --> -5, 0, 1, 2, 3. for -5, only 2 and 3 can compensate. -5 will not be used later, we can ignore it.
2. How to move the interval, if sum < 0, move the left boudary forward, otherwise, move the right boundary backward
3. How to avoid duplicate element:

### 18 4 sum
1. The bacis part is 2Sum, find two element whose sum equals to the target. 
2. nums.size() return a size_t data type, which is an unsigned data type
3. the value of target might be overflow, Long long should be used  

## 2025-06-05
### 344 Reverse String
1. double pointer

### 541 Reverse String2
1. Simulate the rule, 2*k in a circle

### 54 Reverse number
1. Increase or replace linear data type (string , vector), it is easier to replace from the end.

## 2025-06-09

### 151 Reverse a word in string
1. Reverse entire string
2. Remove extra spaces two pointer method: fast find non-space char, curr rewrite string via fast and add space after word
3. Reverse single word 

### Kama 55
1. string.substr(startIndex, length), string.erase(startIndex, length)
2. Move substring can be achieved by reverse entire string + reverse substring

### KMP Algorithm
1. Basic idea is: when a mismatch happens, we don't want to compare needle from begin. We want to start somewhere else.
2. When mismatch happenes, If needle has same suffix and prefix (length = x). We have verified the suffix -> we have verify the prefix. We can start from x+1 to verify needle.
3. First, find Longest Prefix Suffix array. lps[i]: the longest common prefix and suffix length until index i.
4. If needle and main string matches, continue move both mainIndex and needleIndex forward. Otherwise, move needleIndex to lsp[last_matched needleIndex]. 

### 25 Find first occurance substring

### 459 Repeated Substring pattern
1. When string has repeated substring, the substring exclusive to longest prefix suffix string is the smallest common string.
2. If entire string % smallest common string == 0. entire string is repeated string.

## 2025-06-10
### 232 Implement Queue using stack
1. Use two stacks, stackIn and stackOut
2. stack.pop() is a void function.
3. Try to avoid duplicate code, but reuse function.

### 225 Implement stack using queue
1. Use two queues: for pop(), push queue1's elements to queue2, use queue2 as storage. Then, move queue2's elements back to queue1.
2. Ues one queue: repush front elements to end, except the last-in element.

### 20 Valid Parenthes
1. Using stack last-in first-out
2. Remove left bracket if matched right bracket appears
3. Error type: (1) extra bracket (2) mismatch
4. When it points '(', '{' and '['. Put related right brackets in the stack.

### 1047 Remove all adjacent duplicate in string
1. Stack keep track of last element
2. We can use output string as stack to save memory

## 2025-06-10
### 150 Evaluate reverse polish nation
1. stoi = string to int, stoll = string to long long
2. Stack is useful when dealing with previous values in the loop

### 239 Sliding window max
1. First thought: use fixed size queue to simulate window. Since both of them are first-in, first-out. O(k * n). Too slow
2. Does queue need to keep every elements within window? No, we only care about the maximum value.
3. When we find a current max value, push it to the front. We shall pop previous max vaules out, since they are not needed anymore. We like the new bigger value.
4. We shall keep the second max value. Because when window sliding over current max value, we need to pop it out and use the second maximum value until we have another new bigger value.

### 347 Top K frequent elements
1. Use unorder_map to record the frequency
2. Use priority queue. Each element has a priority. "Highest Priority" means the element at top to be pushed. Priority is decided by comp(a,b). If comp(a, b) is TRUE, b is ahead of a. Otherwise, a is ahead of b.
3. For max-heap, read all pairs from map. read the first K element.
4. For min-heap, keep the size of priority = K. Smaller value is pushed out. The remaining element is the result.
5. define customed comperator. Struct with operator() function. Is is a datatype.

## 2025-06-17
### 144 Binaray tree preorder traversal(Recursive)
1. Recursive way is good for binary tree because we have parent node in memory
2. Define the return type and parameter, return void and save the node in vector -> parameter = vector and node
3. Define the ending condition of recursive function node == null
4. Actual behavior of each recursive, save parent node + recursive(left child) + recursive(right child)

### 144 Binaray tree preorder traversal(Iteration)
1. Read the top of stack.
2. Push the right node first and left node later. 

### 145 Binary tree postorder traversal(Recursive)
1. Similar to 145, but order differently recursive(left) + recursive(right) + save(node value)

### 145 Ninary tree postorder traversal(Iteration)
1. Read the top of stack
2. Push the left child first and right node later -> (root right left)
3. Reverse the result vector (left, right, root)

### 94 InOder traversal(Recursive)
1. Similar to 144, 145, but order differently, recursive(left child) + save parent node + recursive(right child)

### 94 Inorder Traversal(Iterator)
1. Iterate till the end of left child, save passed treNode in the stack
2. When reach nullptr, take the top of stack and (iterate to the right child or back to 1.)

### 102 Binary tree level order traversal
1. Iterate the tree by each level, problem is unknow length of each level and access problem
2. Loop current queue, whose size equals to the number of element in current level, pop the element to the result
3. Push next level's element to the queue, the size of queue also updates

### 107 Binary tree level order traversal 2
1. Same as 102, reverse the result vector

### 199 Binary tree right side view
1. Level iteration with queue, first read the most right element -> back of queue
2. Update the queue with next level elements

### 637 Averages of levels of binary tree
1. Level iteration with queue. Calculate each levle of average and push it to result vector


# 2025-06-26
## 262. Invert binary tree(Recursive)
1. Top node to bottom node, swap the left and right

## 101 Symmetric tree(Iteration)
1. one depth iteration from left side, the other from right side 
2. Put node into stack in the order of symmatric

## 101 Symmetric tree(Recursive)
1. Return type BOOL.
2. Deccide ending condition. 
3. Single recuisive. When Both left and right nodes are equal, compare the inside child and outside child node again.

# 104 and 111 max and min height
1. set the return type int height(TreeNode* node), height(node) = 1 + max(height(left), height(right))

# 2025-06-30
## 110 Balanced binary tree
1. use int as return type and return -1 when we find tree/subtree unbalanced.

## 257 Binary tree paths(recursive)
1. important to use vector<int> to save walked paths
2. After adding a new path, walk back to last root node and try another leaf node

## 257 Binary tree paths(iterate)
1. use 2 stack to save passed nodes and walked pathes stack<TreeNode*> and stack<string>

## 404 Sum of left leaves
1. Condition of left leaves: we need to decide based on its root node. 
2. sum = left leaves of left nodes + left leaves of right nodes

# 222 Count complete tree node
1. Use queue to loop by each layer

# 2025-07-01
## 513 find bottom left tree value
1. iterate by each layer, the first element of each layer is the leftmost value

## 112 113 Path Sum
1. When doesn't need go through entire tree, recuisive function needs return type BOOL
2. use if (traversal()) return true; 

## 106. Construct Binary Tree from Inorder and Postorder Traversal
1. Postorder: left, right, root. The last element is the root node.
2. Inorder: left, root, right.Root node divide the sequence into left tree and right tree.

# 2025-07-03
## 654 maximum binary tree
1. Same to 106

## 617 merge two binary trees
1. Difficult: Termination condition in recursive 

## 700 Search in binary tree
1. left node < root node < right node

## 98 Validate binary search tree
1. Iterate binary search tree in InOrder(left, root, right) in a sequence. The result is increasing sequence.

# 2025-07-07
## 530 Minimum absolute diff in BST
1. BST is ordered sequence.
2. Use two pointer(previous node and current node) when iterate BST 

## 501 Find mode in BST
1. BST is order sequence. We can loop first time to decide the max count, then loop second to find the mode
2. Or we keep track of count and maxcount at the same time, if count > maxcount, we update maxcount and clear result vector with new node

## 236 Lowest Common Ancestor of a Binary Tree
1. postorder recursion to handle left and right child node first, use the return value of child node -> middle root value
