/*
Given a string sentence, return true if it is circular. Otherwise, return false

A sentence is circular if:

- The last character of a word is equal to the first character of the next word.
- The last character of the last word is equal to the first character of the first word.

@pre:
  - 1 <= sentence.length <= 500
  - sentence consist of only lowercase and uppercase English letters and spaces.
  - The words in sentence are separated by a single space.
  - There are no leading or trailing spaces.

@see https://leetcode.com/problems/circular-sentence
*/
class Solution {
    public boolean isCircularSentence(String sentence) {
        if (sentence.charAt(0) != sentence.charAt(sentence.length() - 1)) {
            return false;
        }

        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.charAt(i) != ' ') {
                continue;
            }
            // there is no next character
            if (i == sentence.length() - 1) {
                continue;
            }

            if (sentence.charAt(i - 1) != sentence.charAt(i + 1)) {
                return false;
            }
        }
        
        return true;
    }
}
