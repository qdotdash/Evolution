# Evolution
A cpp program demonstrating evolution by natural selection. 
In these programs, I consider words or a complex sentence to be analogous to a complex organism. Genes are the letters making the word.
We are all interested in knowing how it all began. 
***Input in caps***
# basic_evolution.cpp
We input a target word and try to create it from random word generation. Sometimes practically impossible, 
sometimes achievable by luck, sometimes we get a close neighbour of the word after some several thousand generations. From this, it can
be inferred that a single gene can be formed out of luck like a letter 'I' or 'P' but forming a 'complex organism' like RABBIT is very 
hard. 
# evolution.cpp
In this program we add a small factor called survival of the fittest. Here too, we add a target word or sentence. But instead of random 
generation, we do the following:
1. Create a random string of the same word size 
2. Now keeping the letters of the target word as survival genes we mutate and select the fittest every 10 generations.
3. Do this mutation and selection until the target word or sentence is reached.
As you might be able to see, with natural selection according to survival, you can create any complex life form. All it takes is a
hell lot of time and the error in copying genes. 
Cheers!! :D
