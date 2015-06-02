# PRIME1 - Prime Generator #

[codechef](http://www.codechef.com/problems/PRIME1)
[spoj](http://www.spoj.com/problems/PRIME1/)

## Solution ##

1. Unique factors of `10^9` are not bigger than `sqrt(10^9) = 31623`
2. Generate primes up to `31623` using Eratosthenes Sieve.
3. For each number `i` in input range do:
  * if `i < 31623` use precomputed array
  * else try to divide `i` by precomputed primes. If `i % prime == 0` the number is not prime. (do this calculation until primes are less than `sqrt(i)`
