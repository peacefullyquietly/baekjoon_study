def binary_tiles(n):
    tiles = [0 for i in range(N+2)]
    tiles[1] = 1
    tiles[2] = 2
    for i in range(3, n+1):
        tiles[i] = (tiles[i-2] + tiles[i-1]) % 15746
    return tiles[N]


N = int(input())
print(binary_tiles(N))
