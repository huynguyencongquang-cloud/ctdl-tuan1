def dem(a: list[int]) -> tuple[int, int, int]:
    chan = 0
    le = 0
    am = 0
    for x in a:
        if x < 0:
            am += 1
        if x % 2 == 0:
            chan += 1
        else:
            le += 1
    return chan, le, am

if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        chan, le, am = dem(a)
        print(f"{chan} {le} {am}")