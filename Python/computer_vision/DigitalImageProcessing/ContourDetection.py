import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('DigitalImageProcessing/Lenna.png')
cv.imshow('Lenna', img)
blank = np.zeros(img.shape[:2], dtype = 'uint8')
plt.imshow(img)
plt.show()

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

canny = cv.Canny(gray, 125, 175)
cv.imshow('Canny', canny)

ret, thresh = cv.threshold(gray, 125, 255, cv.THRESH_BINARY)
cv.imshow('Thresh', thresh)

coutours, hierarchies = cv.findContours(thresh, cv.RETR_LIST, cv.CHAIN_APPROX_NONE)
print(f'{len(coutours)} coutours(s) found!')
cv.drawContours(blank, coutours, -1, (255, 255, 255), 1)
cv.imshow("Coutours Blank", blank)
 
cv.waitKey()