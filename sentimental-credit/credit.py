from cs50 import get_int


def main():
    while True:
        num = get_int("Number: ")
        if (num > 0):
            break
    card_type(num)


def card_type(num):
    sumTwos = 0
    sumOnes = 0
    i = num // 10

    while (i > 0):
        sumTwos += ((i % 10) * 2)//10 + ((i % 10) * 2) % 10
        i //= 100

    i = num
    while (i > 0):
        sumOnes += i % 10
        i //= 100

    if (sumOnes + sumTwos) % 10 == 0:
        print(card_brand(num))
    else:
        print("INVALID\n")


def card_brand(num):
    digits = len(str(num))

    if digits in [13, 16] and (num // 10 ** 12 == 4 or num // 10 ** 15 == 4):
        return "VISA\n"
    elif digits == 16 and (num // 100000000000000 in [51, 52, 53, 54, 55]):
        return "MASTERCARD\n"
    elif digits == 15 and (num // 10000000000000 in [34, 37]):
        return "AMEX\n"
    return "INVALID\n"


main()
