for i in range(20, 0, -2):  # Loop from 20 down to 2, decrementing by 2
    for j in range(i // 2 + 1):  # Print spaces
        print(" ", end="")
    for j in range(20 - i + 1):  # Print asterisks
        print("*", end="")
    print()  # Move to the next line
