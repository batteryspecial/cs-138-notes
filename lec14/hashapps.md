# The Cost of Computing a Hash

The hash table is good because it offers constant time access to the table and its elements. Ideally, that is the case if the hash function is good and the load is reasonable.

However, a really good hash function usually gives you good spread of hashed values, including antilocality key values (key values close together map to very different hashes). We need to process the keys in our hash, to ensure if any bit value of the key changes, the has changes.

If our key is an integer, we can consider this to be constant time. However if our string is a character string we might have to traverse the string, which makes it O(m) (max/median of characters). Regardless, we consider this to be constant time.

If our key is something more complex, like an image or a tensor, the complexity may vary significantly. Thus, if our keys are very large, then computing a hash may not be "constant time" as promised. We need to use tricks to make the process more efficient.

## Lossy Comparisons

Suppose we want to compare many large files. We can try converting each file to something smaller, then compare the small representations with each other. The conversion is lossy in that you lose data, which is fine because we still have the origins.

This means you can process your photo collection to look for duplicates while looking at (processing fully) each photo only once, when you take its hash. Each photo is hashed to a fixed-size number, and you can just compare the numbers, instead of comparing all of the bits of the image.

The risk, is of course collisions. The goal is collapse a space with large variation into a space with low variation where you can easily check items. The cost, is that you need to check more frequenty for collisions.

# Error Detection

Hashing is often used for error detection. Suppose we downloaded a file over a noisy line. Compute the hash at the start and at the destination. If the hashes don't match, we know something is wrong.

MD5 hash values are 128-bit hash values (typically written as 32 hex characters). It is in wide use, but not for security anymore.

# Code Plagarism

Copying code is common in large industrial software systems. However, checking each piece of code against each other character by character is not the best idea.

Take the hash of each section (or each line, or each token). When two functions have the same hash value, do a detailed comparison. It's much easier to compare numbers.

## Plagarism 

1. Normalize the source code. Transform special identifiers in tags (eg. <ID>), and constants into <ID>, etc. Changing variable names won't save you.
2. Compute the hash value for each line of code, a function would be a set of hashes now, not a sequence.
3. Compare the functions by checking if the sets have overlaps of hash values, so adding excess code won't help you. Sets can be implemented using hash tables, so this is quite efficient.
4. When there is significant overlap of hash values, do a detailed analysis of the suspected procedures using a more expensive comparison method.

# Spell Checking and Password Validation

Hash a dictionary and there you have an instant spell checker. 

In old versions of UNIX, hashes of your passwords were stored in a globally readable `.txt` in a folder like `/etc/passwd`. You can type your password, and the system will hash it and compare the hash to the stored hash.

This is good because your actual password is never stored, in principle, you need a __cryptographic hash function__, where you can't reverse engineer the original password from the hash.

## Cryptographic Hash Functions

A cryptographic hash function has these properties [Wikipedia]
1. It's easy (cheap) to compute the hash value for any given "message" (i.e., the source data)
2. It's infeasible to generate a message that has a given hash value (i.e., can't reverse engineer the original message from the hash value)
3. It's infeasible to modify a message without changing the hash (i.e., a tiny change in the message leads to very different hash value)
4. It's infeasible to find two different messages with the same hash (i.e., collisions are almost impossible)

MD5, SHA0, and SHA1 are examples of past cryptographic hash functions that are considered to be breakable, although they still work as hash functions. There are other cryptographic hash functions (e.g., SHA2) that appear to be unbreakable for now.
