/**
 * task1p1.swift
 * Hannah Soria
 * 5/2/2024
 * demonstration of swift allocating and deallocate memory manually
 */

import Foundation

func main() {
    let ptr = UnsafeMutablePointer<Int>.allocate(capacity: 1) // allocating memory
    ptr.pointee = 30
    print("the value of the pointer is \(ptr.pointee)")
    ptr.deallocate() // deallocating memory
}

main()