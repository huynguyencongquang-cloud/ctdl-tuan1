import sys

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = [int(x) for x in input_data[1:n+1]]
    print(f"{sum(arr)} {max(arr)}")

if __name__ == "__main__":
    main()