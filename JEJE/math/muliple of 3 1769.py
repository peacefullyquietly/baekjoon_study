# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
if __name__ == "__main__":
    cnt = 0
    n = int(input())

    while n >= 10:
        tmp = 0
        while n >= 10:
            tmp += n % 10
            n //= 10
        tmp += n
        
        n = tmp
        cnt += 1;
    
    print(cnt)
    (print("YES") if n % 3 == 0 else print("NO"))