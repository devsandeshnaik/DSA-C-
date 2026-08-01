func isValid(_ s: String) -> Bool {
        let chars = Array(s)
    var stack = [Character]()
    
    for char in chars {
        if char == "(" || char == "[" || char == "{" {
            stack.append(char)
        } else {
            switch char {
                case ")":
                if stack.popLast() != "(" {
                    return false
                }
                case "]":
                if stack.popLast() != "[" {
                    return false
                }
            case "}":
                if stack.popLast() != "{" {
                    return false
                }
            default:
                return false
            }
        }
    }
    return stack.isEmpty ? true : false
    }