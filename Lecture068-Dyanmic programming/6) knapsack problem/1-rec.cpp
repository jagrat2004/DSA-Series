
int solve (vector<int>& weight, vector<int>&value, int index, int capacity){
   if(index == 0){
    if(weight[0] <= capacity)
       return value[0];
    else 
      return 0;
   }
   
}

int knapsack(vector<int>weight, vector<int>value, int n, int maxWeight){
    return solve(weight, value, n-1, maxWeight);
}