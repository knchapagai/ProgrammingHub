<script>
 
// Javascript program to find the
// maximum number of items
// that can be bought from
// the given cost array
 
// Function to find the
// maximum number of items
// that can be bought from
// the given cost array
function number(a, n, p, k)
{
    // Sort the given array
    a.sort();
 
    // Variables to store the prefix
    // sum, answer and the counter
    // variables
    var pre = Array(n).fill(0), val, i,
        j, ans = 0;
 
    // Initializing the first element
    // of the prefix array
    pre[0] = a[0];
 
    // If we can buy at least one item
    if (pre[0] <= p)
        ans = 1;
 
    // Iterating through the first
    // K items and finding the
    // prefix sum
    for (i = 1; i < k - 1; i++) {
        pre[i] = pre[i - 1] + a[i];
 
        // Check the number of items
        // that can be bought
        if (pre[i] <= p)
            ans = i + 1;
    }
 
    pre[k - 1] = a[k - 1];
 
    // Finding the prefix sum for
    // the remaining elements
    for (i = k - 1; i < n; i++) {
        if (i >= k) {
            pre[i] += pre[i - k] + a[i];
        }
 
        // Check the number of iteams
        // that can be bought
        if (pre[i] <= p)
            ans = i + 1;
    }
 
    return ans;
}
 
// Driver code
var n = 5;
var arr = [2, 4, 3, 5, 7];
var p = 11;
var k = 2;
document.write( number(arr, n, p, k));
 
</script>