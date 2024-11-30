def print_r(n: int) -> None:
    if n == 0:
        return
    else:
        print_r(n-1)
        print('I love Recursion')

if __name__=='__main__':
    n = input()
    print_r(int(n))
    