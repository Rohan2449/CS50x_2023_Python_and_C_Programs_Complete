from cs50 import get_string
text = get_string("Text: ")

words = text.split()

letters = 0
sentences = 0
for word in words:
    for letter in word:
        if (letter.isalpha()):
            letters += 1
    if '.' in word or '?' in word or '!' in word:
        sentences += 1
L = letters / len(words) * 100
S = sentences / len(words) * 100

index = (0.0588 * L - 0.296 * S - 15.8)


if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
