cost = [["Paper", 5799],
         ["Printer", 12050],
         ["Planners", 3125],
         ["Binders", 2250],
         ["Calendar", 1095],
         ["Notebooks", 1120],
         ["Ink", 6695]]

check = dict()
for key, value in cost:
    check[key] = value

tot = 0
while True:
    inp = input()
    if inp == "EOI":
        break

    tot += check[inp]

print(f"${tot//100}.{tot%100:02d}")