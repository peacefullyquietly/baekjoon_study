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