abjad = list(set("abcdefghijklmnopqrstuvwxyz"))


class Caesar:

    def __init__(self, plainText: str, key: int) -> None:
        self.plainText = str.lower(plainText)
        self.key = key

    def _get_char(self, char: str, op: str) -> str:
        return abjad[eval(f'{abjad.index(char)} {op} {self.key} % {len(abjad)}')]

    def _do_operation(self, op: 'str') -> int:
        op_char = '+' if op == 'encrypt' else '-'

        chiperText = []
        for char in self.plainText:

            if char in abjad:
                chiperText.append(self._get_char(char, op_char))
            else:
                chiperText.append(char)

        return "".join(chiperText)

    def encrypt(self):
        return self._do_operation('encrypt')

    def decrypt(self):
        return self._do_operation('decrypt')


def main():
    text = "Hello my Friend!"
    key = 2
    encryp_caesar = Caesar(text, key)

    encrypt_text = encryp_caesar.encrypt()

    decrypt_caesar = Caesar(encrypt_text, key)

    decrypt_text = decrypt_caesar.decrypt()

    print("text encrypt = ", encrypt_text)
    print("text decrypt = ", decrypt_text)


if __name__ == "__main__":
    main()
