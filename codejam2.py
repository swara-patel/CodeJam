T=int(input("Enter the number of trials"))
if T<1 or T>100:
    print("Not Possible")
else:
    for k in range(1,T+1):
        S=input()
        S1=''
        n=0
        if len(S)<101 and len(S)>0:
            for i in range(len(S)):
                if(n==int(S[i])):
                    S1=S1+S[i]
                elif(n>int(S[i])):
                    for j in range(n-int(S[i])):
                        S1=S1+')'
                        n=n-1
                    S1=S1+S[i]
                else:
                    for j in range(int(S[i])-n):
                        S1=S1+'('
                        n=n+1
                    S1=S1+S[i]
                if(i==len(S)-1):
                    for i in range(n):
                        S1=S1+')'
            print('Case #{}:'.format(k)+S1)
        else:
            print("String is very long")