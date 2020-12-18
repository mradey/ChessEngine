for i in range(8):
    print("{", end="")
    for j in range(8):
        print('"' + chr(ord('H') - j) + str(i+1) + '"', end=", ")
    print("}")