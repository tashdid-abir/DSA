def reverse_string(s: str, index: int) -> None:
    if index < 0:
        return
    else:
        print(s[index], end='')
        reverse_string(s, index-1)
        
def string_input() -> None:
    s = input("Enter the string: ")
    reverse_string(s, len(s)-1)

if __name__ == '__main__':
    string_input()
