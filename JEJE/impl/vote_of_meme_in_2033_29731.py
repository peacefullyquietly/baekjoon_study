# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
def solve():
    l = ["Never gonna give you up",
         "Never gonna let you down",
         "Never gonna run around and desert you",
         "Never gonna make you cry",
         "Never gonna say goodbye",
         "Never gonna tell a lie and hurt you",
         "Never gonna stop"]
    for _ in range(int(input())):
        if input() not in l:
            return "Yes"
    return "No"

print(solve())