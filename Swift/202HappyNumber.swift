
func isHappy(_ n: Int) -> Bool {
    var num = n
    var uniq: Set<Int> = []
    while num != 1 {
        var res = 0
        while num != 0 {
            let rem = num % 10
            num = num / 10
            res += rem * rem
        }
        if uniq.contains(res) { break }
        uniq.insert(res)
        num = res
    }
    return num == 1 ? true : false
}

let res = isHappy(19)
let res2 = isHappy(2)

print(res)
print(res2)