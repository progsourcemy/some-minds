Very rough idea about string search.
ABCABCABC => ABCABCABC
ABC             ABC
why  jump three.


Here's some additional information, which should be related to some materials in this directory.

Given a string "string1", if we concatenate two strings "string1" to form "string2", note the following two constraints:

1. The string must be within "string2".

2. The string must start from the second letter of the first string "string1" and end at the last letter of the first string "string1".

Under these constraints, searching for "string1",if it is found,"string1" is composed entirely of identical letters or identical "letter segments" from beginning to end.
