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

TEST 31 - Tree stores a single character
  Run: echo "a" | ./Encryption-Term-Project
  Expected:
    'a' 1
  Result: PASS

TEST 32 - Tree stores two characters as leaves
  Run: echo "ab" | ./Encryption-Term-Project
  Expected:
    '*' 2(
        'a' 1
        'b' 1
    )
  Result: PASS

TEST 33 - Internal nodes can store other internal nodes
  Run: echo "abc" | ./Encryption-Term-Project
  Expected:
    '*' 3(
        'b' 1
        '*' 2(
           'a' 1
           'c' 1
        )
    )
  Result: PASS

TEST 34 - Characters of same frequencies are stored together
  Run: echo "abcc" | ./Encryption-Term-Project
  Expected:
    '*' 4(
        'c' 2
        '*' 2(
           'a' 1
           'b' 1
        )
    )
  Result: PASS

TEST 35 - Internal node's frequency is sum of leaves' frequencies
  Run: echo "ab" | ./Encryption-Term-Project
  Expected: first line must be
    '*' 2(
  Result: PASS

TEST 36 - Root's frequency is sum of all leaves' frequencies
  Run: echo "abc" | ./Encryption-Term-Project
  Expected: first line must be
    '*' 3(
  Result: PASS

TEST 37 - Internal node with higher frequency than leaf is placed later in queue
  Run: echo "aabbccc" | ./Encryption-Term-Project
  Expected:
    '*' 7(
        'c' 3
        '*' 4(
            'a' 2
            'b' 2
        )
    )
  Result: PASS

TEST 38 - Lowest frequency character is now named first (change from earlier versions)
  Run: echo "aaabbc" | ./Encryption-Term-Project
  Expected: first line must be
    'c' --> 1
  Result: PASS

TEST 39 - Tree stores spaces
  Run: echo " " | ./Encryption-Term-Project
  Expected:
    ' ' 1
  Result: PASS

TEST 40 - Tree stores multiple word input
  Run: echo "a a a" | ./Encryption-Term-Project
  Expected:
    '*' 5(
        ' ' 2
        'a' 3
    )
  Result: PASS

TEST 41 - Tree stores strings with numbers
  Run: echo "1" | ./Encryption-Term-Project
  Expected:
    '1' 1
  Result: PASS

TEST 42 - Tree stores special characters
  Run: echo "!!" | ./Encryption-Term-Project
  Expected:
    '!' 2
  Result: PASS

TEST 43 - Tree stores letters and special characters
  Run: echo "a!a!" | ./Encryption-Term-Project
  Expected:
    '*' 4(
        '!' 2
        'a' 2
    )
  Result: PASS

TEST 44 - Characters of nearest low frequency are stored together
  Run: echo "abbccc" | ./Encryption-Term-Project
  Expected:
    '*' 6(
        'c' 3
        '*' 3(
           'a' 1
           'b' 2
        )
    )
  Result: PASS

TEST 45 - All digits no repeats
  Run: echo "1234567890" | ./Encryption-Term-Project
  Expected: 10 leaf nodes
    '[digit]' 1
  Result: PASS

TEST 46 - Queue fully empties
  Run: echo "abcdef" | ./Encryption-Term-Project
  Expected: 6 leaf nodes
    '[character]' 1
  Result: PASS

TEST 47 - Mixed capital and lowercase letters
  Run: echo "AaAa" | ./Encryption-Term-Project
  Expected:
    '*' 4(
        'a' 2
        'A' 2
    )
  Result: PASS

TEST 48 - Mixed letters and numbers
  Run: echo "aa22" | ./Encryption-Term-Project
  Expected:
    '*' 4(
        'a' 2
        '2' 2
    )
  Result: PASS

TEST 49 - Mixed numbers and special characters
  Run: echo "1!1!" | ./Encryption-Term-Project
  Expected:
    '*' 4(
        '!' 2
        '1' 2
    )
  Result: PASS
  
TEST 50 - All character types combined
  Run: echo "aA1!" | ./Encryption-Term-Project
  Expected: 4 leaf nodes
    '[character]' 1
  Result: PASS

TEST 51 - Single character binary code
  Run: echo "a" | ./Encryption-Term-Project
  Expected:
    'a' --> 0
  Result: PASS

TEST 52 - Two characters have different codes
  Run: echo "ab" | ./Encryption-Term-Project
  Expected:
    'a' --> 0
    'b' --> 1
  Result: PASS

TEST 53 - Length of codes increases with number of characters
  Run: echo "ab" | ./Encryption-Term-Project
  Expected:
    'a' --> 0
    'b' --> 10
    'c' --> 11
  Result: PASS

TEST 54 - Three distinct characters with equal frequencies
  Run: echo "abc" | ./Encryption-Term-Project
  Expected:
    'a', 'b', and 'c' all receive unique binary codes.
  Result: PASS

TEST 55 - Case sensitivity is maintained
  Run: echo "aA" | ./Encryption-Term-Project
  Expected:
    'a' and 'A' are treated as completely distinct characters with unique codes.
  Result: PASS

TEST 56 - Space characters are encoded correctly
  Run: echo "a b" | ./Encryption-Term-Project
  Expected:
    ' ' (space) receives a unique binary code along with 'a' and 'b'.
  Result: PASS

TEST 57 - Numeric characters are encoded correctly
  Run: echo "123" | ./Encryption-Term-Project
  Expected:
    '1', '2', and '3' receive unique binary codes.
  Result: PASS

TEST 58 - Special symbols are encoded correctly
  Run: echo "!@#" | ./Encryption-Term-Project
  Expected:
    '!', '@', and '#' receive unique binary codes.
  Result: PASS

TEST 59 - Skewed frequencies assign shorter codes to frequent characters
  Run: echo "abbccc" | ./Encryption-Term-Project
  Expected:
    'c' has the shortest code (1 bit), while 'a' and 'b' have longer codes.
  Result: PASS

TEST 60 - Extreme frequency skewing
  Run: echo "a bbb ccccccc" | ./Encryption-Term-Project
  Expected:
    'c' has the shortest code, followed by 'b', then 'a' and ' '.
  Result: PASS

TEST 61 - Long repeated single character
  Run: echo "zzzzzzzzzz" | ./Encryption-Term-Project
  Expected:
    'z' --> 0 (or 1).
  Result: PASS

TEST 62 - Alternating sequence of two characters
  Run: echo "abababab" | ./Encryption-Term-Project
  Expected:
    'a' and 'b' both receive 1-bit codes (0 and 1).
  Result: PASS

TEST 63 - Palindrome sequence
  Run: echo "racecar" | ./Encryption-Term-Project
  Expected:
    Unique codes are generated correctly for 'r', 'a', 'c', and 'e'.
  Result: PASS

TEST 64 - Full sentence with spaces
  Run: echo "hello world" | ./Encryption-Term-Project
  Expected:
    'l' receives the shortest code (appears 3 times), followed by 'o' (appears 2 times).
  Result: PASS

TEST 65 - All vowels (equal frequencies)
  Run: echo "aeiou" | ./Encryption-Term-Project
  Expected:
    5 unique, evenly distributed codes are generated.
  Result: PASS

TEST 66 - Mixed alphanumeric characters
  Run: echo "h3ll0" | ./Encryption-Term-Project
  Expected:
    Unique codes are generated for 'h', '3', 'l', and '0'.
  Result: PASS

TEST 67 - Balanced pair frequencies
  Run: echo "aabbccdd" | ./Encryption-Term-Project
  Expected:
    All 4 characters receive 2-bit codes due to the perfectly balanced tree.
  Result: PASS

TEST 68 - Single punctuation mark
  Run: echo "." | ./Encryption-Term-Project
  Expected:
    '.' --> 0 (or 1).
  Result: PASS

TEST 69 - Escaped characters (Newline)
  Run: echo -e "a\nb" | ./Encryption-Term-Project
  Expected:
    The newline character ('\n') is captured and assigned a unique binary code.
  Result: PASS

TEST 70 - Large string (Pangram)
  Run: echo "the quick brown fox jumps over the lazy dog" | ./Encryption-Term-Project
  Expected:
    ' ' (space) gets the shortest code (appears 8 times); all alphabet characters get valid unique codes.
  Result: PASS

=============================================================
  RESULTS SUMMARY
=============================================================

  Total tests:   70
    Passed:      70
    Failed:       0

  Tests that failed:
    (none)

=============================================================
*/