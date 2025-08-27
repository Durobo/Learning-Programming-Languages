import cv2 as cv
import numpy as np

img = cv.imread('DigitalImageProcessing/Lenna.png')
cv.imshow('Lenna', img)

blank = np.zeros(img.shape[:2], dtype = 'uint8')
mask = cv.circle(blank, (blank.shape[0] // 2, blank.shape[1] // 2), 100, 255, -1)
masked = cv.bitwise_and(img, img, mask = mask)

cv.imshow('Mased', masked)
cv.waitKey()