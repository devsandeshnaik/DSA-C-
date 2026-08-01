

public class ListNode {
      public var val: Int
      public var next: ListNode?
      public init() { self.val = 0; self.next = nil; }
      public init(_ val: Int) { self.val = val; self.next = nil; }
      public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 }

func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    var start = ListNode(0)
    var end = start
    var overflow = 0

    var l1 = l1
    var l2 = l2

    while(l1 != nil || l2 != nil || overflow > 0) {
        let val1 = l1 == nil ? 0 : l1!.val
        let val2 = l2 == nil ? 0 : l2!.val

        let sum = val1+val2+overflow
        overflow = sum/10
        let rem = sum%10

        let nn = ListNode(rem)
        end.next = nn
        end = nn

        l1 = l1 == nil ? nil : l1!.next
        l2 = l2 == nil ? nil : l2!.next
    }

    return start.next
}