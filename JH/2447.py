# 별찍기 - 10
import sys


def draw_stars(n):
    if n == 1:
        return ['*']

    Stars = draw_stars(n//3)
    L = []

    for star in Stars:
        L.append(star*3)
    for star in Stars:
        L.append(star+' '*(n//3)+star)
    for star in Stars:
        L.append(star*3)

    return L


N = int(sys.stdin.readline().rstrip())
print('\n'.join(draw_stars(N)))
