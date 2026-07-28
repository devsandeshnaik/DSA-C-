

 func numSubarrayProductLessThanK(_ nums: [Int], _ k: Int) -> Int {
    var count = 0;
    var start = 0;
    var product = 1;
    for end in 0 ... nums.count - 1 {
        product = product * nums[end]
        if product < k { count += end-start + 1 }
        while(product >= k) {
            product = product/nums[start]
            start += 1;
            if product < k { count += end-start + 1 }
        }
    }

    return count
}