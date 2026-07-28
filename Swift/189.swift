

 func rotate(_ nums: inout [Int], _ k: Int) {

    let k = k%nums.count
    nums.reverse()
    nums[0 ..< k].reverse()
    nums[k ..< nums.count].reverse()
}


var arr = [1,2,3,4,5,6,7]
rotate(&arr, 3)
print(arr)
