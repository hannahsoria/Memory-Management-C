CS333 - Project #7 - README
Hannah Soria
5/2/24

Directory Layout:
Project5_hmsori25/
|
|__/task1.c
|__/time.h
|__/detect_garbage.c
|__/task2p1.c
|__/task2p1.swift
|__/task2p1_2.swift
|__/task2p2.swift
|__/haiku.swift

time.h doesn't compile and run alone


task1.c
 Compile:
	gcc -o task1 task1.c 
 Run:
	./task1
 Output:
  total time for small with 200 iterations: 0.000734
  total time for small with 1,000 iterations: 0.000821
  total time for small with 2,000 iterations: 0.001629
  total time for medium with 200 iterations: 0.000114
  total time for medium with 1,000 iterations: 0.000920
  total time for medium with 2,000 iterations: 0.008776
  total time for large with 200 iterations: 0.000279
  total time for large with 1,000 iterations: 1.074441
  total time for large with 2,000 iterations: 10.089685

detect_garbage.c
 Compile:
	gcc -o detect_garbage detect_garbage.c
 Run:
	./detect_garbage
 Output:
 
  heap chunk 0x7fc4a8f05f00 is garbage
  heap chunk 0x7fc4a8f05f20 is reachable
  heap chunk 0x7fc4a8f05e90 is garbage
  heap chunk 0x7fc4a8f05e10 is reachable

 task2p1.c
 Compile:
	gcc -o task2p1 task2p1.c
 Run:
	./task2p1
 Output:
  the value of the pointer is 30

task2p1.swift
 Compile:
	swiftc task2p1.swift
 Run:
	./task2p1
 Output:
   the value of the pointer is 30

task2p1_2.swift
 Compile:
	swiftc task2p1_2.swift 
 Run:
	./task2p1_2
 Output:
  Computer Science is being initialized
  Computer Science is being deinitialized

task2p2.swift
 Compile:
	swiftc task2p2.swift
 Run:
	./task2p2
 Output:

  Execution time: 0.774880051612854 seconds
  Execution time: 0.646833062171936 seconds
  Execution time: 0.6448320150375366 seconds
  Execution time: 0.6665699481964111 seconds
  Execution time: 0.6481759548187256 seconds
  Execution time: 0.6403100490570068 seconds
  Execution time: 0.6347060203552246 seconds
  Execution time: 0.6122130155563354 seconds
  Execution time: 0.6126600503921509 seconds
  Execution time: 0.6152210235595703 seconds
  
haiku.swift
 Compile:
	swiftc haiku.swift
 Run:
	./haiku
 Output:
  these strings are declared
  written into memory
  gone without command