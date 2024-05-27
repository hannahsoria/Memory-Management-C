/**
 * task1p2.swift
 * Hannah Soria
 * 5/2/2024
 * demonstration of swift automatically deallocating memory
 */
import Foundation

func memory_usage() {
    var array: [Int] = [] // define an array
    for _ in 0..<10000 { // loop 10,000 times
        let newArray = Array(repeating: 0, count: 10000)// Create a new array with 10,000 elements
        
        array.append(contentsOf: newArray) // Append the new array to the existing one, creating a huge array through the iterations
    }
}

func runTime() {
    let startTime = CFAbsoluteTimeGetCurrent() // start time
    memory_usage() // run the memory usage function
    let endTime = CFAbsoluteTimeGetCurrent() // end time
    let runTime = endTime - startTime // find the runtime
    print("Execution time: \(runTime) seconds")
}

for _ in 0..<10 { // iterate 10 times
    rumTime()
}