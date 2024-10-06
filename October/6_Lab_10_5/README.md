## Questions for Lab 6 - 05/10/2024


### 1. Bloom filter implementation:- 

Implemet a Bloom filter based on the information below. Conduct an experiment to empirically measure its false positive rate.

The Universe consists of strings formed from the alphabet { A..Z}. Write a function to
generate random strings into the Universe. Chose value of k = 3, 5, 7; m = 10, 50, 100, 200etc.

You can use any three/five/seven hash functions of your choice.


### 2. Determine False Positivity Rate:- 

The process for calculating the false positive rate is described below:

1. first, add n unique elements to the bloom filter.
2. next, perform lookups for n unique elements that are not in the set.
3. the false positive rate is the ratio of lookups which yield true for n

Insert n = 10, 000 strings and populate the bloom filter. 
Keep track of the strings inserted, next search for 10,000 strings 
which are not inserted.


### 3. Observations and Comments:- 

1. Analyse the false positivity rate based on the values of m, n, k. 

2. Repeat the experiment with different values of m, n, k. Document your findings and list two practical Bloom filter application.


### 4. Reading assignment:- 

Please read the original paper by B. H. Bloom. 
https://dl.acm.org/doi/pdf/10.1145/362686.362692
