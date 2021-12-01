def mapValue(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

def calcLine(startX, startY, endX, endY,affected):
    if (endX > startX):
        width = endX - startX + 1
        anchorX = startX
    else:
        width = startX - endX + 1
        anchorX = endX
    if (endY > startY):
        height = endY - startY + 1
        anchorY = startY
    else:
        height = startY - endY + 1
        anchorY = endY

   
    slopeY = endY - startY
    slopeX = endX - startX
    print(slopeX)
    print(slopeY)
    if(abs(slopeY) <= abs(slopeX)):
        slope = int(slopeY * 100 / slopeX)
        affected[anchorY][anchorX] = 1
        affected[endY][endX] = 1
        print(width)
        print(height)
        for x in range(width):
            print(int(slope * x) % 100)
            if(int(slope * x) % 100 > 70):
                y = (int(slope * x) / 100) + 1
            elif(int(slope * x) % 100 == 0):
                y = (int(slope * x) / 100)
            #elif(int(slope * x) % 100 < 30):
            #    y = (int(slope * x) / 100) - 1
            else:
                y = (int(slope * x) / 100)
            y = int(y)
            affected[y + anchorY][x + anchorX] = 1
    else:
        slope = int(slopeX * 100 / slopeY)      
        affected[anchorY][anchorX] = 1
        affected[endY][endX] = 1
        print(width)
        print(height)
        for y in range(height):
            print(int(slope * y) % 100)
            if(int(slope * y) % 100 > 70):
                x = (int(slope * y) / 100) + 1
            elif(int(slope * y) % 100 == 0):
                x = (int(slope * y) / 100)
            #elif(int(slope * x) % 100 < 30):
            #    y = (int(slope * x) / 100) - 1
            else:
                x = (int(slope * y) / 100)
            x = int(x)
            affected[y + anchorY][x + anchorX] = 1

def display(a):
    for y in a:
        dump = ""
        for x in y:
            dump += str(x)
        print(dump)
        


attotal = []
for y in range(10):
    ar = []
    for i in range(10):
        ar.append(0)
    attotal.append(ar)

display(attotal)
print()
calcLine(7,9,0,0,attotal)
display(attotal)
