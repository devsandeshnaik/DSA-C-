// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

func lengthOfLongestSubstring(_ s: String) -> Int {
    let chars = Array(s)      
    var length = 0
    var low = 0
    var map: [Character: Int] = [:]

    for high in 0 ..< s.count {
        let char = chars[high]
        while(map[char] != nil) {
            map[chars[low]] = nil
            low+=1
        }
        map[char] = 1
        length = max(length, high-low+1)
    }
    
    return length
}


let len = lengthOfLongestSubstring("sandesh")
print("Lenght \(len)")
