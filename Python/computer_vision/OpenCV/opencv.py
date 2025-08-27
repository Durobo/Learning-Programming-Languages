import random
import numpy as np
import cv2

    # Read image
img = cv2.imread("Python/computer_vision/image/OpenCV_1_2.png", 1) 

    # Resize image
img1 = cv2.resize(img, (1000, 1000))   # Width, Length
img2 = cv2.resize(img, (0, 0), fx = 0.5, fy = 0.5)   # fx -> Width, fy -> Length

    # Rotate image
img3 = cv2.rotate(img, cv2.ROTATE_180)  
img4 = cv2.rotate(img, cv2.ROTATE_90_CLOCKWISE)
img5 = cv2.rotate(img, cv2.ROTATE_90_COUNTERCLOCKWISE)

    # Image structure
print(type(img))
print(img.shape)    # Shape of image

for i in range(500):        # Black image
    for j in range(img1.shape[1]):
        img1[i][j] = [random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)]

selec = img1[0:100, 0:100]  # Insert image
img1[500:600, 500:600] = selec

    # Converting to grayscale
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Blur
blur_img = cv2.GaussianBlur(img, (7, 7), cv2.BORDER_DEFAULT)

    # Edge cascale
canny_img = cv2.Canny(img, 125, 175)

    # Dilating the image
dilated_img = cv2.dilate(canny_img, (3, 3), iterations = 3)

    # Eroding
eroded_img = cv2.erode(dilated_img, (3, 3), iterations = 3)

    # Camera
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    frame = cv2.resize(frame, (900, 900))
    image = np.zeros(frame.shape, np.uint8) # Create black frame
    w = int(frame.shape[1])
    h = int(frame.shape[0])
    small_frame = cv2.resize(frame, (0, 0), fx = 0.5, fy = 0.5)     
    image[:h//2, :w//2] = small_frame
    image[h//2:h, :w//2] = cv2.rotate(small_frame, cv2.ROTATE_180)
    image[:h//2, w//2:w] = cv2.rotate(small_frame, cv2.ROTATE_90_CLOCKWISE)
    image[h//2:h, w//2:w] = cv2.rotate(small_frame, cv2.ROTATE_90_COUNTERCLOCKWISE)

    img6 = cv2.line(image, (0, 0), (h ,w), (0, 0, 0), 2)    # Create line
    img6 = cv2.line(image, (0, w), (h, 0), (0, 0, 0), 2)
    img6 = cv2.rectangle(image, (225, 225), (675, 675), (255, 255, 255), 2)    # Create rectangle
    img6 = cv2.circle(image, (450, 450), 225, (0, 0, 0), 2) # Create circle
    font = cv2.FONT_HERSHEY_SIMPLEX         # PutText 
    img6 = cv2.putText(image, "OpenCV", (345, 470), font, 2, (255, 0, 0), 5)

    cv2.imshow("Camera window", img6)
    if cv2.waitKey(1) == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
        
    # Show image
cv2.imshow('Window', eroded_img)  
k = cv2.waitKey()      # Use the screen

    # Save new image
if k == ord("s"):
    cv2.imwrite("Python/computer_vision/image/new_image.jpg", img)