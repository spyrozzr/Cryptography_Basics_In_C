# THIS REPOSITORY IS A WORK IN PROGRESS HARDLY ANY CODE IS IMPLEMENTED YET.

______________________________________________________

# Basics of Cryptography in C

This repository aims to explain the basic concepts of the field of cryptography, with a brief description and implementation in C. In this repository we will discuss, with implemented examples, the concepts of basic ciphers, hashing and encryption.

______________________________________________________

## BASIC CIPHERS:

The most fundamental concept in cryptography is that of a cipher. A cipher is a systematic method used to encode or encrypt information (ex, a string), often to protect its confidentiality and integrity during transmission or storage. The following are some types and categories of ciphers:

- ## Substitution ciphers:

Substitution ciphers are a type of encryption method where each letter in the plaintext is replaced with another letter or symbol according to a fixed rule. These ciphers operate on a per-letter basis and are considered relatively simple forms of encryption. The following methods exist:

  1. ### Monoalphabetic Substitution (Caesar) Cipher:

In a monoalphabetic substitution cipher, each letter in the plaintext is replaced by a single corresponding letter in the ciphertext. This means that the same letter in the plaintext will always be replaced by the same letter in the ciphertext. The simplest example of a monoalphabetic substitution cipher is the Caesar cipher, a 'shift cipher' where each letter is shifted a fixed number of positions down the alphabet. For example, with a shift of 3, "A" becomes "D," "B" becomes "E," and so on. This is implemented by simply editing the value of each character of the given string.
Here is an example of a caesar cipher with a shift of 3:
```
Plaintext:    H  E  L  L  O     W  O  R  L  D
Ciphertext:   K  H  O  O  R     Z  R  U  O  G
```

  2. ### Polyalphabetic Substitution (Vigenère) Cipher:
Polyalphabetic substitution ciphers use multiple substitution alphabets to encode the plaintext. This means that the same letter in the plaintext might be encoded as different letters in the ciphertext, depending on its position in the message. One example of a polyalphabetic cipher is the Vigenère cipher, in which a keyword is repeated to match the length of the plaintext. Each letter in the keyword determines the shift value for the corresponding letter in the plaintext. This makes the cipher more resistant to frequency analysis.
Here is an example of a vigenere cipher with the keyword 'key':
```
Plaintext:    H  E  L  L  O     W  O  R  L  D
Keyword:      K  E  Y  K  E     Y  K  E  K  E
Ciphertext:   K  H  O  P  S     Z  V  U  P  G
```


- ## Transposition Ciphers:

Transposition ciphers are a type of encryption technique in cryptography that involve rearranging the characters of a message to hide its original content. Unlike substitution ciphers, where each character is replaced with another character, transposition ciphers do not change the characters themselves; they only change the order in which the characters appear. There are various methods for implementing transposition ciphers, but the basic idea is to rearrange the characters according to a specific pattern or rule, and then send the rearranged message. Here are some examples:


  1. ### Rail Fence Cipher:
In the Rail Fence cipher, the message is written in a zigzag pattern along a set number of "rails." The encrypted message is then obtained by reading the characters along the rails in a linear fashion.
Here is an example encryptionn of "HELLO WORLD":
```
H . . . O . . . R . . .
. E . L . W . L . D .
. . L . . . O . . . .
```
The encrypted message would be: "HORELWLDDLO".


  2. ### Columnar Transposition Cipher:
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


## HASHING:

Hashing is the process of converting input data (a message, a file, a password, etc.) into a fixed-size value (usually a sequence of characters) called a hash or hash value. Hash functions are designed to be fast to compute and deterministic, meaning the same input will always produce the same hash output. Reverse engineering a hashed key is extremely difficult, and therefore this method is used for storing sensitive information, like passwords. Hashing is widely used for data integrity verification, as even a small change in the input data will result in a significantly different hash value.

As cryptography is ever-evolving to keep up with the technological advancements, so are hashing functions. Some older hashing functions are considered obsolete, like MD5, while newer, more advanced hasing functions are being developed to keep up with the times. Newer hashing functions include SHA-256 and ARGON2, which is written entirely in C.

For example, if we have the input string "Hello, world!", hashing it using SHA-256 might produce the hash:
```
2CF24DBA5FB0A30E26E83B2AC5B9E29E1B161E5C1FA7425E73043362938B9824
```

 ### Salting:

 Salting is a technique used to enhance the security of passwords stored in a database. When a user creates an account or changes their password, a random value called a "salt" is generated. This salt is then combined with the user's password before hashing. The salt value is stored alongside the hash in the database. The purpose of salting is to prevent attackers from using precomputed tables (rainbow tables) to quickly guess the original password from the hash. Since each user has a unique salt, even if two users have the same password, their hashes will be different due to the different salts.

Here's how salting works:
```
User creates a password: mypassword
Generate a random salt: 5f83b2a7
Combine salt and password: 5f83b2a7mypassword
Hash the combined value: 2E14912E4B09B71967D72DB5677E073E01BFF8DA1B3E106D96D7A1CBBF6E4704
```
Now, even if another user has the same password, their salt will be different, resulting in a different hash in the database. Using salting significantly increases the security of password storage, making it much more difficult for attackers to perform brute-force or dictionary attacks.


## ENCRYPTION:

Encryption is the process of converting plain, readable data (plaintext) into a form that appears random and unintelligible (ciphertext). The purpose of encryption is to ensure the confidentiality and security of sensitive information during transmission or storage. To read the encrypted data, one needs the appropriate decryption key or algorithm. There are two main types of encryption; symmetric and asymmetric.

1. ### Symmetric Encryption:
 
In symmetric encryption, the same key is used for both encryption and decryption. This means that both the sender and the recipient must possess the same secret key. The process involves the following steps:
```
  Key Generation: A single secret key is generated or chosen.
  Encryption: The plaintext is combined with the secret key using an encryption algorithm, resulting in ciphertext. The same key is used for both encryption and decryption.
  Decryption: The recipient uses the same secret key and the decryption algorithm to convert the ciphertext back to plaintext.
```
Advantages of symmetric encryption include its efficiency and speed. However, the challenge lies in securely distributing and managing the secret keys between parties.
Examples of symmetric encryption algorithms include the Data Encryption Standard (DES), the Advanced Encryption Standard (AES), and the 3DES (Triple DES) algorithm.

2. ### Asymmetric Encryption:

Asymmetric encryption, also known as public-key cryptography, uses a pair of mathematically related keys: a public key and a private key. The public key is shared openly, while the private key is kept secret. The process involves the following steps:
```
    Key Pair Generation: Two keys are generated: a public key and a private key. These keys are related in a way that data encrypted with one key can only be decrypted with the other key in the pair.
    Encryption: The sender uses the recipient's public key to encrypt the plaintext, resulting in ciphertext.
    Decryption: The recipient uses their private key to decrypt the ciphertext back to plaintext.
```
One of the key advantages of asymmetric encryption is its ability to establish secure communication channels without sharing secret keys. However, asymmetric encryption is usually slower than symmetric encryption due to the complexity of the mathematical operations involved.
Examples of asymmetric encryption algorithms include RSA (Rivest-Shamir-Adleman) and ECC (Elliptic Curve Cryptography).


In practice, symmetric encryption is often used for bulk data encryption due to its speed, while asymmetric encryption is used for tasks like secure key exchange, digital signatures, and establishing secure communication channels.

Encryptions algorithms differ from hashing algorithms in their purpose, method and results. While hashing algoithms create a fixed size hash value (digest) that essentially acts as a fingerprint of the hashed data, encryption algorithms work to convert plain, readable text into ciphertext that can only be transcribed using a key, as described above. Additionally, while encryption can be reversed with a key, hashing is intentionally very difficult, or even impossible, to reverse.

______________________________________________________

## License:

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



