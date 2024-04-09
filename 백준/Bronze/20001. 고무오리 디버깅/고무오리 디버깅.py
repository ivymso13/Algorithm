st = []
while True:
    inp = input()
    if inp == "고무오리 디버깅 시작":
        continue
    elif inp == "고무오리 디버깅 끝":
        break

    if inp == "문제":
        st.append("문제")
    else:
        if len(st) == 0:
            st.append("문제")
            st.append("문제")
        else:
            st.pop()

if len(st) == 0:
    print("고무오리야 사랑해")
else:
    print("힝구")