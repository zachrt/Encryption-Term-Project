/*
=============================================================
  TEST PLAN - Encryption Term Project
  CSC 375 - Data Structures ( Zach and Talon )
=============================================================

HOW TO USE THIS:
  1. Compile your project with CMake first (make sure it builds)
  2. Every test uses this pattern in the terminal:
       echo "your input here" | ./Encryption-Term-Project

  3. Check if the output matches what it says "Expected:"
  4. Write PASS or FAIL next to each one

  NOTE: run all commands from inside your build/ folder
        or replace ./Encryption-Term-Project with the full path

=============================================================

TEST 1 - Node stores a single character
  Run: echo "a" | ./Encryption-Term-Project
  Expected:
    'a' --> 1
  Result: PASS

TEST 2 - Node stores frequency greater than 1
  Run: echo "aaa" | ./Encryption-Term-Project
  Expected:
    'a' --> 3
  Result: PASS

TEST 3 - Node works with a space character
  Run: echo " " | ./Encryption-Term-Project
  Expected:
    ' ' --> 1
  Result: PASS

TEST 4 - Node works with a number character
  Run: echo "7" | ./Encryption-Term-Project
  Expected:
    '7' --> 1
  Result: PASS

TEST 5 - Two nodes store independently
  Run: echo "ab" | ./Encryption-Term-Project
  Expected (order may vary):
    'a' --> 1
    'b' --> 1
  Result: PASS

TEST 6 - Single character string
  Run: echo "a" | ./Encryption-Term-Project
  Expected:
    'a' --> 1
  Result: PASS

TEST 7 - All same characters
  Run: echo "aaaa" | ./Encryption-Term-Project
  Expected:
    'a' --> 4
  Result: PASS

TEST 8 - Two different characters equal frequency
  Run: echo "ab" | ./Encryption-Term-Project
  Expected (order may vary):
    'a' --> 1
    'b' --> 1
  Result: PASS

TEST 9 - Repeated pattern
  Run: echo "ababab" | ./Encryption-Term-Project
  Expected (order may vary):
    'a' --> 3
    'b' --> 3
  Result: PASS

TEST 10 - Numbers in the string
  Run: echo "1122333" | ./Encryption-Term-Project
  Expected (order may vary):
    '3' --> 3
    '2' --> 2
    '1' --> 2
  Result: PASS

TEST 11 - Mixed uppercase and lowercase are different
  Run: echo "aAbB" | ./Encryption-Term-Project
  Expected (order may vary, all freqs are 1):
    'a' --> 1
    'A' --> 1
    'b' --> 1
    'B' --> 1
  Result: PASS

TEST 12 - String with a space in the middle
  Run: echo "hi there" | ./Encryption-Term-Project
  Expected (order may vary):
    'h' --> 2
    'e' --> 2
    'i' --> 1
    ' ' --> 1
    't' --> 1
    'r' --> 1
  Result: PASS

TEST 13 - Only spaces
  Run: echo "   " | ./Encryption-Term-Project
  Expected:
    ' ' --> 3
  Result: PASS

TEST 14 - Highest frequency comes out first
  Run: echo "aaabbc" | ./Encryption-Term-Project
  Expected: first line is
    'a' --> 3
  Result: PASS

TEST 15 - Two items with same frequency (tie)
  Run: echo "aabb" | ./Encryption-Term-Project
  Expected (either order is fine):
    'a' --> 2
    'b' --> 2
  Result: PASS

TEST 16 - Only one unique character in queue
  Run: echo "zzzz" | ./Encryption-Term-Project
  Expected:
    'z' --> 4
  Result: PASS

TEST 17 - Three items all different frequencies
  Run: echo "aaabbc" | ./Encryption-Term-Project
  Expected in this exact order:
    'a' --> 3
    'b' --> 2
    'c' --> 1
  Result: PASS

TEST 18 - Big gap between frequencies
  Run: echo "aaaaaaaab" | ./Encryption-Term-Project
  Expected:
    'a' --> 8
    'b' --> 1
  Result: PASS

TEST 19 - Three way tie
  Run: echo "abcabc" | ./Encryption-Term-Project
  Expected (any order, all freqs must be 2):
    'a' --> 2
    'b' --> 2
    'c' --> 2
  Result: PASS

TEST 20 - Queue fully empties (right number of lines printed)
  Run: echo "abc" | ./Encryption-Term-Project
  Expected: exactly 3 character lines printed
    'a' --> 1
    'b' --> 1
    'c' --> 1
  Result: PASS

TEST 21 - Empty input
  Run: echo "" | ./Encryption-Term-Project
  Expected:
    You didn't enter anything!
  Result: PASS

TEST 22 - Single character
  Run: echo "x" | ./Encryption-Term-Project
  Expected:
    'x' --> 1
  Result: PASS

TEST 23 - Classic test word
  Run: echo "hello" | ./Encryption-Term-Project
  Expected:
    'l' --> 2
    'h' --> 1
    'e' --> 1
    'o' --> 1
  Result: PASS

TEST 24 - Famous test case
  Run: echo "mississippi" | ./Encryption-Term-Project
  Expected:
    'i' --> 4
    's' --> 4
    'p' --> 2
    'm' --> 1
  Result: PASS

TEST 25 - Two word sentence
  Run: echo "hello world" | ./Encryption-Term-Project
  Expected:
    'l' --> 3
    'o' --> 2
    (all remaining chars --> 1)
  Result: PASS

TEST 26 - Same letter different case
  Run: echo "AaAaAa" | ./Encryption-Term-Project
  Expected (order may vary):
    'A' --> 3
    'a' --> 3
  Result: PASS

TEST 27 - Special characters mixed in ( use single quotes if using zsh )
  Run: echo "a!a!a!" | ./Encryption-Term-Project
  Expected (order may vary):
    'a' --> 3
    '!' --> 3
  Result: PASS

TEST 28 - Repeated pattern long string
  Run: echo "abcabcabcabc" | ./Encryption-Term-Project
  Expected (order may vary):
    'a' --> 4
    'b' --> 4
    'c' --> 4
  Result: PASS

TEST 29 - All digits no repeats
  Run: echo "1234567890" | ./Encryption-Term-Project
  Expected:
    10 lines, each digit showing --> 1
  Result: PASS

TEST 30 - One character dominates
  Run: echo "aaaaaaaaaaabc" | ./Encryption-Term-Project
  Expected: first line must be
    'a' --> 11
  Result: PASS

=============================================================
  RESULTS SUMMARY
=============================================================

  Total tests:   30
    Passed:      30
    Failed:       0

  Tests that failed:
    (none)

=============================================================
*/