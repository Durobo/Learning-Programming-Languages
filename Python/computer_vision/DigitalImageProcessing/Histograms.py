import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread('DigitalImageProcessing/Lenna.png')
cv.imshow('Lenna', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

# Grayscale Histogram
gray_hist = cv.calcHist([gray], [0], None, [256], [0, 256])

plt.figure()
plt.title('Grayscale Histogram')
plt.xlabel('Bins')
plt.ylabel('# of pixels')
plt.plot(gray_hist)
plt.xlim([0, 256])
plt.show()

cv.waitKey()