import csv
import sys


def main():

    # Check for command-line usage
    if (len(sys.argv) != 3):
        print("Incorrect usage")

    # Read database file into a variable
    file = open(sys.argv[1])
    reader = csv.reader(file)
    header = reader.__next__()
    header.pop(0)

    # Read DNA sequence file into a variable
    DNAfile = open(sys.argv[2])
    DNA_sequence = DNAfile.readline()

    # Find longest match of each STR in DNA sequence
    longestSTR = dict()
    for STR in header:
        longestSTR[STR] = longest_match(DNA_sequence, STR)
        # print(STR)
        # lenSTR = len(STR)
        # index = 0
        # count = 0
        # biggest = 0
        # while(index < len(sequence)):
        #     if STR == sequence[index + lenSTR]:
        #         count += 1
        #         index += lenSTR
        #         if count > biggest:
        #             biggest = count
        #     else:
        #         count = 0
        #         index += 1
        # longestSTR[STR] = biggest

    # Check database for matching profiles
    for person in reader:
        match = is_match(person, longestSTR)
        if (match == True):
            break
    if match == False:
        print("No match")


def is_match(person, longestSTR):
    index = 1
    for STR in longestSTR:
        if (int(person[index]) != longestSTR[STR]):
            return False
        index += 1
    print(person[0])
    return True


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
