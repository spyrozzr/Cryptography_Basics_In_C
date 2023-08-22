# THIS REPOSITORY IS A WORK IN PROGRESS.

______________________________________________________

# Basics of Cryptography in C

This repository aims to explain the basic concepts of the field of cryptography, with a brief description and implementation in C.

______________________________________________________

### Table of Contents:


______________________________________________________

The most fundamental concept in cryptography is that of a cipher. A cipher is a systematic method used to encode or encrypt information (ex, a string), often to protect its confidentiality and integrity during transmission or storage. The following are some types and categories of ciphers:

## Substitution ciphers:

Substitution ciphers are a type of encryption method where each letter in the plaintext is replaced with another letter or symbol according to a fixed rule. These ciphers operate on a per-letter basis and are considered relatively simple forms of encryption. The following methods exist:

- ### Monoalphabetic Substitution (Caesar) Cipher:

In a monoalphabetic substitution cipher, each letter in the plaintext is replaced by a single corresponding letter in the ciphertext. This means that the same letter in the plaintext will always be replaced by the same letter in the ciphertext. The simplest example of a monoalphabetic substitution cipher is the Caesar cipher, a 'shift cipher' where each letter is shifted a fixed number of positions down the alphabet. For example, with a shift of 3, "A" becomes "D," "B" becomes "E," and so on. This is implemented by simply editing the value of each character of the given string.
Here is an example of a caesar cipher with a shift of 3:
```
Plaintext:    H  E  L  L  O     W  O  R  L  D
Ciphertext:   K  H  O  O  R     Z  R  U  O  G
```

- ### Polyalphabetic Substitution (Vigenère) Cipher:
Polyalphabetic substitution ciphers use multiple substitution alphabets to encode the plaintext. This means that the same letter in the plaintext might be encoded as different letters in the ciphertext, depending on its position in the message. One example of a polyalphabetic cipher is the Vigenère cipher, in which a keyword is repeated to match the length of the plaintext. Each letter in the keyword determines the shift value for the corresponding letter in the plaintext. This makes the cipher more resistant to frequency analysis.
Here is an example of a vigenere cipher with the keyword 'key':
```
Plaintext:    H  E  L  L  O     W  O  R  L  D
Keyword:      K  E  Y  K  E     Y  K  E  K  E
Ciphertext:   K  H  O  P  S     Z  V  U  P  G
```


## Transposition Ciphers:

Transposition ciphers are a type of encryption technique in cryptography that involve rearranging the characters of a message to hide its original content. Unlike substitution ciphers, where each character is replaced with another character, transposition ciphers do not change the characters themselves; they only change the order in which the characters appear. There are various methods for implementing transposition ciphers, but the basic idea is to rearrange the characters according to a specific pattern or rule, and then send the rearranged message. Here are some examples:


- ### Rail Fence Cipher:
In the Rail Fence cipher, the message is written in a zigzag pattern along a set number of "rails." The encrypted message is then obtained by reading the characters along the rails in a linear fashion.
Here is an example encryptionn of "HELLO WORLD":
```
H . . . O . . . R . . .
. E . L . W . L . D .
. . L . . . O . . . .
```
The encrypted message would be: "HORELWLDDLO".


- ### Columnar Transposition Cipher:
In the Columnar Transposition cipher, the message is written in a grid with a certain number of columns. The columns are then read in a specific order determined by a key (a keyword or a numerical sequence). The encrypted message is formed by reading the characters column by column according to the order specified by the key.
Let's encrypt the message "CRYPTOGRAPHY" using the keyword "KEY":
```
K E Y
------
C R Y
P T O
G R A
P H Y
```
Reading the columns in the order of the keyword "KEY" gives us the encrypted message: "PRGYCOPTARPH".
 





