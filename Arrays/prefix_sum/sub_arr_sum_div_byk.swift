func subarraysDivByK(_ nums: [Int], _ k: Int) -> Int {
        var map: [Int: Int] = [:]
        var sum = 0
        var res = 0
        map[0] = 1
        for i in 0 ..< nums.count {
            sum += nums[i]
            var rem = sum%k
            rem = rem < 0 ? rem + k : rem
            if let count = map[rem] {
                res += count
                map[rem]! += 1
            } else {
                map[rem] = 1
            }
        }
    return res
}