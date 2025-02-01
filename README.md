# Miller-Rabin Challenge

Welcome! This is the second Programming Club competition for the 2024-2025 school year. This one is a little different from the [Fibonacci Challenge](https://github.com/FPHS-Programming-Club/FibonacciChallenge). Now a total of $30 is on the line!

Here's the goal. **Your task is to implement the Miller-Rabin primality test in a language of your choice.** Feel free to use any optimizations you deem proper, but you must use this algorithm. **There will be two categories to this competition**: one based on speed and one based on code complexity. **You are allowed to have a separate submission per category**, and they can even be different languages. This competition lasts a month. **The deadline for submissions is February 28th!**

The Miller-Rabin primality test is a probabilistic way to determine if a number is prime. It uses calculations that are somewhat easy for a computer to evaluate, however its implementation can be demanding on the programmer. There are many resources online, including [a Numberphile video](https://www.youtube.com/watch?v=_MscGSN5J6o) and [a Wikipedia page](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test). ("Witness numbers" will be quite useful when implementing).

For the speed-based category, your submission should correctly determine if a given number is prime as fast as possible. That's it. For the code-based category, on the other hand, your submission will be broken down into its individual tokens and ranked based on that. The speed of the program does not matter for this category, but the results must be correct.

I'm not sure how we'll split the money yet. It'll be a total of $15 per category (maybe more if people are willing to contribute). It might all go to the first place winner, or it might be a split, $10 for first and $5 for second. I'll keep you posted!

**The numbers used during testing will not be revealed!** However, they will be the same for every submission. It will be a range between two large 64-bit numbers, somewhere between a billion and a few quintillion. *Nothing above `2^63-1` will be used.*

You will of course be given a template for the language you choose to write your code in. The templates are available by switching the active branch, and you can simply download the code there. You will have a method called `bool IsPrime(long number)` (may differ depending on the language) that you are tasked with implementing.

**Here's the TL;DR**:
- Implement the Miller-Rabin primality test. Don't use a different algorithm.
- One submission per category: one for speed, one for code length. $15 is at stake for each.
- Use whatever language you want. You'll have a single method to implement.
- The testing numbers will not be revealed, but will fit into a 64-bit signed integer.
- The deadline is February 28th.

Happy Coding!
