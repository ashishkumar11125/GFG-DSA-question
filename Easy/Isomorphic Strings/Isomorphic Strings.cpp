class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        // Check if the lengths of both strings are not equal.
        if (str1.size() != str2.size()) 
        {
            return false;
        }

        unordered_map<char, char> m; // Map to store the mapping of characters from str1 to str2.
        unordered_set<char> s; // Set to check if a character in str2 is already mapped to a different character in str 1.

        // Iterate through each character in the strings.
        for (int i = 0; i < str1.size(); i++) 
        {
            // If the character from str1 is not mapped to any character in str2,
           // and the character in str2 is not already mapped to a different character in str1.
           if (m.count(str1[i]) == 0 and s.count(str2[i]) == 0) 
           {
               m[str1[i]] = str2[i]; // Map the character from str1 to str2.
               s.insert(str2[i]); // Add the character in str2 to the set.
           } 
           else if (m.count(str1[i]) == 0 and s.count(str2[i]) != 0) 
           {
               return false; // If the character in str2 is already mapped to a different character in str1, return false.
           }
           else if (m[str1[i]] != str2[i]) 
           {
               return false; // If the current mapping is different from the existing mapping, return false.
           }
        }
        return true; // If all characters are successfully mapped, return true.
    }
};