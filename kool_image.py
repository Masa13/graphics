def kool_image():
    f = open("kool_image.ppm", "w")
    f.write("P3 250 250 255 ")
    red = 0
    green = 0
    blue = 0
    while (blue < 250):
        green = 0
        while (green < 250):
            f.write( "%d %d %d " % ( red, green, blue ) )
            green += 1
        blue += 1
    f.close()

if __name__=='__main__':
    kool_image()
