'''
Program to print your message in special fonts
'''
alphabets = {
    "A": "  ######  \n  #    #  \n  ######  \n  #    #  \n  #    #  \n",
    "B": "  ######  \n  #    #  \n  #####   \n  #    #  \n  ######  \n",
    "C": "  ######  \n  #       \n  #       \n  #       \n  ######  \n",
    "D": "  #####   \n  #    #  \n  #    #  \n  #    #  \n  #####   \n",
    "E": "  ######  \n  #       \n  #####   \n  #       \n  ######  \n",
    "F": "  ######  \n  #       \n  #####   \n  #       \n  #       \n",
    "G": "  ######  \n  #       \n  # ####  \n  #    #  \n  #####   \n",
    "H": "  #    #  \n  #    #  \n  ######  \n  #    #  \n  #    #  \n",
    "I": "  ######  \n    ##    \n    ##    \n    ##    \n  ######  \n",
    "J": "  ######  \n    ##    \n    ##    \n  # ##    \n  ####    \n",
    "K": "  #   #   \n  #  #    \n  ##      \n  #  #    \n  #   #   \n",
    "L": "  #       \n  #       \n  #       \n  #       \n  ######  \n",
    "M": "  #    #  \n  ##  ##  \n  # ## #  \n  #    #  \n  #    #  \n",
    "N": "  #    #  \n  ##   #  \n  # #  #  \n  #  # #  \n  #   ##  \n",
    "O": "  ######  \n  #    #  \n  #    #  \n  #    #  \n  ######  \n",
    "P": "  ######  \n  #    #  \n  ######  \n  #       \n  #       \n",
    "Q": "  ######  \n  #    #  \n  # #  #  \n  #  # #  \n  ######  \n",
    "R": "  ######  \n  #    #  \n  # ##    \n  #   #   \n  #    #  \n",
    "S": "  ######  \n  #       \n  ######  \n       #  \n  ######  \n",
    "T": "  ######  \n    ##    \n    ##    \n    ##    \n    ##    \n",
    "U": "  #    #  \n  #    #  \n  #    #  \n  #    #  \n  ######  \n",
    "V": "  #    #  \n  #    #  \n  #    #  \n   #  #   \n    ##    \n",
    "W": "  #    #  \n  #    #  \n  # ## #  \n  ##  ##  \n  #    #  \n",
    "X": "  #    #  \n   #  #   \n    ##    \n   #  #   \n  #    #  \n",
    "Y": "  #    #  \n   #  #   \n    ##    \n    ##    \n    ##    \n",
    "Z": "  ######  \n      #   \n     #    \n    #     \n  ######  \n",
}


def print_message(message):
    print()
    for word in message:
        # print(word)
        hash = {}
        for c in word:
            hash[c] = alphabets[c].split("\n")
        # print(len(hash["M"]))
        i = 0
        while i < 6:
            for k in word:
                print(hash[k][i], end="  ")
            print()
            i += 1


if __name__ == "__main__":
    message = input("Enter your message: ").upper().split()
    print_message(message)
