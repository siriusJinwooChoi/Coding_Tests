#-*- coding: utf-8 -*-

def first_problem():
    tlist = raw_input().split(',')

    for j in range(len(tlist)-1):
        for k in range(1, len(tlist)):
            if int(tlist[k-1]) > int(tlist[k]):
                tlist[k-1], tlist[k] = tlist[k], tlist[k-1]
    print tlist

def second_problem():
    srclist = raw_input().split(',')
    resultlist = []

    print len(srclist)
    
    """
    for k in range(len(srclist)):
        #srclist[k] = int(srclist[k])
        if type(srclist[k]) == str:
            srclist2 = int(srclist)
    """
    """
    resultlist = []
    srclist = [1, 2, [3, 4], 5, [6, 7]]
    srclist2 = [1, 2, [3, 4, [5, 6, 7], 8], [9, 10], 11]
    srclist3 = [[1,2,3], [5,7,4,6,[8], [9], [10, 11]], [13, 12]]
    """
    
    def listloop(srclist):
        for i in range(len(srclist)):            
            if type(srclist[i]) == list:
                listloop(srclist[i])
            else:
                resultlist.append(srclist[i])

    #List_Test(1)
    listloop(srclist)
                
    #List_Test(2)
    #listloop(srclist2)

    #List_Test(3)
    #listloop(srclist3)
    
    print resultlist

def third_problem():
    result = ""
    srcnum = int(raw_input())
    cnt = 1

    def gaemiloop(result, srcnum, cnt):
        if srcnum > 0 and srcnum < 10:
            imsinum = srcnum % 10
            result = str(cnt) + str(imsinum) + str(result)
            
        elif srcnum >= 10:
            imsinum, cmpnum = srcnum % 10, (srcnum / 10) % 10
            srcnum /= 10
            if cmpnum == imsinum:
                cnt = cnt + 1
                result = gaemiloop(result, srcnum, cnt)
            else:
                result = str(cnt) + str(imsinum) + str(result)
                cnt = 1
                result = gaemiloop(result, srcnum, cnt)
        return result
    
    result = gaemiloop(result, srcnum, cnt)
    print result
    
if __name__ == '__main__':
    #first_problem()
    second_problem()
    #third_problem()
