func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
    let arr = nums.sorted()
    var diff = Int.max
    var sum = 0

    for i in 0 ... arr.count-3 {
        var p1 = i+1
        var p2 = arr.count-1
        while p2 > p1 {
            let cSum = arr[i] + arr[p1] + arr[p2]
            if cSum == target { return cSum } else {
                let nDiff = abs(target - cSum)
                if nDiff < diff {
                    diff = nDiff
                    sum = cSum
                }
                if cSum > target { p2-=1 } else { p1+=1 }
            }
        }
        
    }
    return sum
}


let res = threeSumClosest([-1,2,1,-4], 1)
print(res)

