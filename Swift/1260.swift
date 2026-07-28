func shiftGrid(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        var res = [[Int]](repeating: [Int](repeating: 0, count: grid[0].count), count: grid.count)
        let size = grid.count * grid[0].count

        let k = k%size
        for i in 0 ..< size {
            let np = (i+k) % size
            let r = np/grid[0].count
            let c = np%grid[0].count
            res[r][c] = grid[i/grid[0].count][i%grid[0].count]
        }
    return res
}

func shiftGridInPlace(_ grid: [[Int]], _ k: Int) -> [[Int]] {
    let row = grid.count
        let column = grid[0].count
        let n = row * column
        let k = k % n
        if k == 0 {
            return grid
        }
        
        func reverse(_ gridx: inout [[Int]], _ start: Int, _ end: Int) {
            var i = start
            var j = end
            while i < j {
                let temp = gridx[i/column][i%column]
                gridx[i/column][i%column] = gridx[j/column][j%column]
                gridx[j/column][j%column] = temp
                i += 1
                j -= 1
            }
        }
        
        reverse(&grid, 0, n - 1)
        reverse(&grid, 0, k - 1)
        reverse(&grid, k, n - 1)
        return grid
}


let arr = [[1,2,3],[4,5,6],[7,8,9]]
let res = shiftGridInPlace(arr, 3)
print(res)