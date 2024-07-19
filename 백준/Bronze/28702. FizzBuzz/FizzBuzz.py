ret = 0
for i in range(3):
    inp = input()

    if inp not in ["Fizz", "Buzz", "FizzBuzz"]:
        ret = int(inp) + (3 - i)

if ret%15 == 0:
    print("FizzBuzz")
elif ret%5 == 0:
    print("Buzz")
elif ret%3 == 0:
    print("Fizz")
else :
    print(ret)