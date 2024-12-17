# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
word = []

if "__main__" == __name__ :
    s = input()
    for i in range(1, len(s)):
        for j in range(i+1, len(s)):
            a = s[:i][::-1]
            b = s[i:j][::-1]
            c = s[j:][::-1]
            word.append("".join([a, b, c]))
            
    word.sort()
    print(word[0])
