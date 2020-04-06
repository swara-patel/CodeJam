def createMatrix(rowCount, colCount, dataList):
    mat = []
    for i in range(rowCount):
        rowList = []
        for j in range(colCount):
            rowList.append(dataList[rowCount * i + j])
        mat.append(rowList)
    return mat
t=int(input())
if t>0 and t<100:
    d=0
    m=[]
    for testcase in range(0,t):
        r=int(input())
        if r>0 and r<100:
            def values(d):
                if(d<r):
                    b=input("Enter values row")
                    k=b.split(" ")
                    for i in range(0,len(k)):
                        if int(k[i])<1 or int(k[i])>r or len(k)>r:
                            print("The number is larger than expected")
                            values(d)
                        else:
                            m.append(k[i])
                            d=d+1
                            values(d)
            values(d)
            #print(m)
            arr = createMatrix(r,r,m)
            #print(arr)
            su=0
            cntr=0
            cntc=0
            for i in range (0,r):
                su+=arr[i][i]
            print(su)
            #rows
            for i in range (0,r):
                for j in range(0,r):
                    for k in range(j+1,r):
                        if arr[i][j]==arr[i][k]:
                            cntr=cntr+1
            #columns
            for i in range (0,r):
                for j in range (0,r):
                    for k in range(i+1,r):
                        if arr[i][j]==arr[k][j]:
                            cntc=cntc+1
        else:
            print("huge matrix")
    for i in range(0,t):
        print("case#",t,": ",su,cntr,cntc)
else:
    print("Large number of cases")        