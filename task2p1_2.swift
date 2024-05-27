/**
 * task1p1.swift
 * Hannah Soria
 * 5/2/2024
 * demonstration of swift allocating but not need to deallocate memory
 */

class Student{
    let major: String
    init(major: String){
        self.major = major
        print("\(major) is being initialized")
    }
    deinit{
        print("\(major) is being deinitialized")
    }
}
var student: Student? = Student(major: "Computer Science")
student = nil // deinit will be triggered when the reference count becomes zero