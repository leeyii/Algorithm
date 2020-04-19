import UIKit

public struct Stack<T> {
    
  /// Datastructure consisting of a generic item.
  fileprivate var array = [T]()

  /// The number of items in the stack.
  public var count: Int {
    return array.count
  }

  /// Verifies if the stack is empty.
  public var isEmpty: Bool {
    return array.isEmpty
  }

  /**
     Pushes an item to the top of the stack.
     
     - Parameter element: The item being pushed.
  */
  public mutating func push(_ element: T) {
    array.append(element)
  }

  /**
     Removes and returns the item at the top of the sack.
     
     - Returns: The item at the top of the stack.
  */
  public mutating func pop() -> T? {
    return array.popLast()
  }

  /// Returns the item at the top of the stack.
  public var top: T? {
    return array.last
  }
}

class StackElem {
    var repeatCount: Int = 1
    var content: String = ""
    
    var result: String {
        return String(repeating: content, count: repeatCount)
    }
}

func stringEncode(_ str: String) -> String {
    
    var repeatCountStr: String = ""
    
    var stack = Stack<StackElem>()
    
    stack.push(StackElem())
    
    for c in str {
        switch c {
        case "a"..."z":
            let top = stack.top!
            top.content.append(c)
            break
        case "0"..."9":
            repeatCountStr.append(c)
            break
        case "[" :
            // 创建一个栈元素 入栈
            let elem = StackElem()
            elem.repeatCount = Int(repeatCountStr)!
            repeatCountStr = ""
            stack.push(elem)
            break
        case "]":
            // 将栈顶元素出栈
            let elem = stack.pop()!
            if let top = stack.top {
                // 栈中还有元素
                top.content.append(elem.result)
            }
            break
        default:
            break
        }
    }
    
    return stack.top?.content ?? ""
}


stringEncode("3[a2[c]]")
