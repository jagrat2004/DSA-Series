#include<iostream>                   // For input/output stream
#include<queue>                      // For queue STL
#include<stack>                      // (Not used here, but included for completeness)
#include<map>                        // (Not used, kept if needed for future)
#include<unordered_map>              // For storing character frequencies
using namespace std;

// Define a class named 'solution'
class solution {
    public:
    // Function to return a string of first non-repeating characters at each point in the input string
    string firstNonRepeating(string A) {
        unordered_map<char, int> count; // Hash map to store frequency of each character
        queue<int> q;                   // Queue to store characters in order of their appearance
        string ans = "";                // Result string to store the first non-repeating character at each step

        // Loop through each character in the input string
        for (int i = 0; i < A.length(); i++) {
            char ch = A[i];            // Current character
            count[ch]++;               // Increment its frequency in the map

            q.push(ch);                // Push the character into the queue

            // Check the front of the queue to find the first non-repeating character
            while (!q.empty()) {
                if (count[q.front()] > 1) { // If frequency > 1, it is repeating
                    q.pop();               // Remove it from the queue
                } else {
                    ans.push_back(q.front()); // Found a non-repeating character, add to result
                    break;                    // Break out of the loop
                }
            }

            // If queue is empty, there is no non-repeating character
            if (q.empty()) {
                ans.push_back('#');      // Add '#' to the result
            }
        }

        return ans;                      // Return the final result string
    }
};

int main() {
    solution obj;                        // Create an object of the solution class
    string A = "aabc";                   // Input string
    string result = obj.firstNonRepeating(A); // Call the function to compute result
    cout << "First non-repeating characters: " << result << endl; // Print the result
    return 0;                            // Exit the program
}
