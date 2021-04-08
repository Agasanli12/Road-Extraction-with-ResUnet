import cv2
import os
from os import listdir
from os.path import isfile, join

filtered_path = "computer_filtered"

os.system("mkdir "+filtered_path)

path = "computer_thresholded"

images = [f for f in listdir(path) if isfile(join(path, f))]

for i in range(len(images)):
    image = cv2.imread(path + "/" + images[i])
    filtered = cv2.medianBlur(image, 3)
    cv2.imwrite(filtered_path+"/"+images[i], filtered)


# image = cv2.imread("computer_thresholded/1.png")

# filtered = cv2.medianBlur(image, 3)

# cv2.imshow("original", image)
# cv2.imshow("filtered", filtered)

# cv2.waitKey(0)
