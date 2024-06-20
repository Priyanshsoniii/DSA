<h2><a href="https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article">Max distance between same elements</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 20px;">Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.</span></p>
<p><span style="font-size: 20px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 20px;"><strong>Input:</strong></span><span style="font-size: 20px;">
n = 6
arr = {1, 1, 2, 2, 2, 1}</span>
<span style="font-size: 20px;"><strong>Output: </strong>5</span>
<span style="font-size: 20px;"><strong>Explanation:</strong>
arr[] = {1, 1, 2, 2, 2, 1}
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5</span></pre>
<p><span style="font-size: 20px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 20px;"><strong>Input:</strong>
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}</span>
<span style="font-size: 20px;"><strong>Output: </strong>10</span>
<span style="font-size: 20px;"><strong>Explanation:</strong></span>
<span style="font-size: 20px;">arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>Complete <strong>maxDistance() </strong>function which takes both the given array and their size as function arguments and returns the maximum distance between two same elements. </span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity </strong>:&nbsp; O(n)<br><strong>Expected Auxilliary Space </strong>: O(n)</span></p>
<p><span style="font-size: 20px;"><strong>Constraints:<br></strong></span><span style="font-size: 20px;">1 &lt;= n &lt;= 10<sup>6</sup><br>1 &lt;= arr[i] &lt;= 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;