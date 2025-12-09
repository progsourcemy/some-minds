Very rough idea about string search.
ABCABCABC => ABCABCABC
ABC             ABC
why  jump three.


Here's some additional information, which should be related to some materials in this directory.

Given a string "string1", if we concatenate two strings "string1" to form "string2", note the search operation follows these two constraints:

1. Search within "string2".

2. The search operation must begin within the range from the second letter of the first string "string1" to the last letter of the first string "string1".

Under these constraints, searching for "string1",if it is found,"string1" is composed entirely of identical letters or identical "letter segments" from beginning to end.
