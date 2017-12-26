//
//  Stack.swift
//  Stack
//
//  Created by leeyii on 2017/12/26.
//  Copyright © 2017年 leeyii. All rights reserved.
//

import Foundation

public struct Stack<Element> {
    
    // MARK: - property
    
    private var array: Array<Element> = []
    
    // MARK: - Method
    
    /// push element into Stack
    ///
    /// - Parameter element: pushed element
    public mutating func push(_ element: Element) -> Void {
        array.append(element)
    }
    
    /// remove the element at stack top
    ///
    /// - Returns: stack top element
    public mutating func pop() -> Element? {
        guard array.isEmpty else { return nil}
        
        return array.remove(at: array.count - 1);
    }
    
    public func isEmpty() -> Bool {
        return array.isEmpty
    }
    
    public func count() -> Int {
        return array.count
    }
    
}


extension Stack : Equatable {
    
    public static func ==(lhs: Stack, rhs: Stack) -> Bool {
        
        guard lhs.count() == rhs.count() else { return false}
        
        
        
        return true
    }
}
