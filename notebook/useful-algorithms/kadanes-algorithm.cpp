/**
 * KADANE'S ALGORITHM
 * 
 * The simple idea of Kadane's algorithm is to look for all positive contiguous segments of the array 
 * (sum is used for this). And keep track of maximum sum contiguous segment among all positive segments 
 * (maxi used for this). Each time we get a positive-sum compare it with maxi and update maxi if it is 
 * greater than maxi.
 * 
 * Time complexity: O(n) 
 * 
 **/

int kadane(vector<int> &a){
    int n = a.size();
    int sum = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        maxi = max(maxi, sum);
        if(sum < 0) sum = 0;
    }
    return maxi;
}