Name:   Abhishek Jhoree
ID:     0986820
CIS *3490 Algorithms

------------------------------------------------------------------
Instructions to compile and run
1. do make
2. do make run
------------------------------------------------------------------
This program implements brute force algorithms for part 1a and presort for 1b.
for part 1b, the numbers are sorted using the quicksort algorithms

Question 2 implements defferent algorithms for  string pattern matching.
part 1 implements brute force, part2 Horspool and part 3 implements Boyer-Moore



-------------------------------------------------------------------------------------------
question 2.4
10 test cases of different lengths provided

Test case   |    Brute Force     |      Horspool      |    Boyer-Moore     |   #
------------------------------------------------------------------------------------
"University"|2860109/106 = 26,982| 398561/29 = 13,743 | 398561/28 = 14,234 |  2345 
 "admission"|2904157/101 = 28,754| 399799/25 = 15,992 | 399799/25 = 15,992 |  1363
 "students" |2948205/89 = 33,125 | 473852/28 = 16,923 | 472703/29 = 16,300 |  4201
 "trainer"  |2992253/86 = 34,794 | 564726/32 = 17,648 | 559557/31 = 18,050 |  0
 "School"   |3036301/70 = 43,376 | 562635/26 = 21,640 | 562635/27 = 20,838 |  172
 "hello"    |3080349/50 = 61,607 | 679755/30 = 22,658 | 679755/28 = 24,277 |  0
 "test"     |3124397/56 = 55,793 | 889922/30 = 29,664 | 889792/27 = 32,955 |  253
 "hey"      |3168445/38 = 83,380 | 1141735/31 = 36,830| 1141735/33 = 34,598|  431
 "yo"       |3212494/28 = 114,732| 1626602/29 = 57,633| 1626602/29 = 57,633|  960
 "I"        |3256543/17 = 191,561| 3256543/40 = 81,414| 3256543/38 = 85,699|  6168
-----------------------------------------------------------------------------------
Avg Ratios: |      67,410        |       31,415       |       32,058       |

Notes:

Amount of shifts:
- The amount of shifts in Boyer-Moore is always less than or equal to horspool (The more reoccuring patterns in the search word, the less shifts for Boyer-Moore)
- Brute force is always the max amount of shifts, as it moves by one each time

Ratios:
- The ratio for brute force is often higher because it is doing many smaller shifts per second, as it is only shifting by one position
- The ratio for horspool and Boyer-Moore are almost identical, they often only differ in execution time by a few miliseconds.

Size of search word:
- As the search word becomes bigger, brute force takes a longer time to execute and its amount of shifts decreases slightly
- As the search word becomes bigger, the run times for horspool and boyer-moore remain at a somewhat consistent valye between 25-40. The amount of shifts decreases in both cases though

Efficiency:
-Brute force is the most effective when the search word is very small (1 character)
-Horspool and Boyer-Moore become more efficient than Brute Force after the search word increases past size 1 and they stay consistant