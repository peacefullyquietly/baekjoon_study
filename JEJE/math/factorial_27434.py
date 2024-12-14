import sys
sys.set_int_max_str_digits(1000000)
sys.stdout.write(str(__import__("functools").reduce(lambda x, y: x * y, [i+1 for i in range((lambda n: 1 if n == 0 else n)(int(input())))])))