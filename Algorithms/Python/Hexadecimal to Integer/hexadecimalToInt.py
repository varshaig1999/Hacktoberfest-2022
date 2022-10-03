from os import system, name as system_name
from re import match as re_match

numbers = list(map(str, range(10)))
numbers += ["A", "B", "C", "D", "E", "F"]
list_numbers_hex = list(enumerate(numbers))


def from_hex_to_int(hex_number):
    """
    Convert a hexadecimal number to integer
    """
    output = 0
    i = len(hex_number) - 1
    for number in hex_number:
        output += (
            list(filter(lambda e: e[1] == number, list_numbers_hex))[0][0] * 16**i
        )
        i -= 1
    return output


def aux_validate_hex(txt_hex_number):
    """
    Validade a hex number
    """
    txt_hex_number = txt_hex_number.strip().upper()
    hex_pattern = r"^[\dA-F]+$"
    if re_match(hex_pattern, txt_hex_number):
        return txt_hex_number
    return False


def main():
    system("cls") if system_name == "nt" else system("clear")
    print("-" * 50)
    while not (hex_number := aux_validate_hex(input("Informe a hex number: "))):
        print("HEX NUMBERS ONLY! [0-9ABCDEF]")
    print(f"{hex_number}(hex) to int is: {from_hex_to_int(hex_number)}")
    print("-" * 50)


if __name__ == "__main__":
    main()
