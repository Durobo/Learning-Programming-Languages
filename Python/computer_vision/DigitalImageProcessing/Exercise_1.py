import cv2
import numpy as np

def create_and_save_image_with_rectangles():
    """
    Tạo một ảnh trắng đen bằng cách vẽ các hình chữ nhật lên đó,
    mỗi hình chữ nhật có một mức xám do người dùng nhập.
    Sau đó, lưu ảnh ra tệp.
    """
    
    print("----------------------------------------------------------------")
    print("Chào mừng bạn đến với công cụ tạo ảnh bằng hình chữ nhật!")
    print("Bạn sẽ nhập tọa độ và mức xám cho các hình chữ nhật.")
    print("Mức xám phải nằm trong khoảng từ 0 đến 255.")
    print("Nhập -1 cho mức xám để dừng chương trình và lưu ảnh.")
    print("----------------------------------------------------------------")

    # Kích thước ảnh mặc định. Bạn có thể thay đổi các giá trị này.
    image_width = 800
    image_height = 600

    # Tạo một ảnh trống màu đen (hoàn toàn đen, mức xám 0) với kích thước đã cho.
    # cv2.IMREAD_GRAYSCALE chỉ định ảnh sẽ là ảnh trắng đen (1 kênh).
    image = np.zeros((image_height, image_width), dtype=np.uint8)

    while True:
        try:
            print("\nNhập thông tin cho hình chữ nhật tiếp theo:")
            # Nhập tọa độ góc trên bên trái (x1, y1)
            x1 = int(input("Nhập tọa độ x của góc trên bên trái (x1): "))
            y1 = int(input("Nhập tọa độ y của góc trên bên trái (y1): "))

            # Nhập tọa độ góc dưới bên phải (x2, y2)
            x2 = int(input("Nhập tọa độ x của góc dưới bên phải (x2): "))
            y2 = int(input("Nhập tọa độ y của góc dưới bên phải (y2): "))

            # Nhập mức xám
            gray_level = int(input("Nhập mức xám (0-255, hoặc -1 để dừng): "))

            if gray_level == -1:
                print("Đã nhập -1 cho mức xám. Dừng tạo hình chữ nhật.")
                break

            # Kiểm tra giá trị mức xám hợp lệ
            if not (0 <= gray_level <= 255):
                print("Lỗi: Mức xám phải nằm trong khoảng từ 0 đến 255. Vui lòng thử lại.")
                continue

            # Kiểm tra tọa độ hợp lệ
            if not (0 <= x1 < image_width and 0 <= y1 < image_height and
                    0 <= x2 < image_width and 0 <= y2 < image_height and
                    x1 < x2 and y1 < y2):
                print(f"Lỗi: Tọa độ không hợp lệ hoặc nằm ngoài kích thước ảnh ({image_width}x{image_height}).")
                print("Đảm bảo x1 < x2 và y1 < y2. Vui lòng thử lại.")
                continue

            # Vẽ hình chữ nhật lên ảnh
            # cv2.rectangle(ảnh, điểm_góc_trên_trái, điểm_góc_dưới_phải, màu, độ_dày_đường_viền)
            # Đối với ảnh trắng đen, màu sắc chính là mức xám.
            # -1 hoặc cv2.FILLED để điền đầy hình chữ nhật.
            cv2.rectangle(image, (x1, y1), (x2, y2), int(gray_level), -1)
            print(f"Đã vẽ hình chữ nhật từ ({x1},{y1}) đến ({x2},{y2}) với mức xám {gray_level}.")

        except ValueError:
            print("Lỗi: Đầu vào không hợp lệ. Vui lòng nhập số nguyên.")
        except Exception as e:
            print(f"Đã xảy ra lỗi: {e}")

    # Tên tệp để lưu ảnh. Bạn có thể thay đổi tên này.
    output_filename = "output_image_with_rectangles.png"

    # Lưu ảnh ra tệp
    cv2.imwrite(output_filename, image)
    print(f"\nẢnh đã được lưu thành công vào: {output_filename}")

    # (Tùy chọn) Hiển thị ảnh sau khi tạo xong
    # cv2.imshow("Ảnh được tạo", image)
    # cv2.waitKey(0) # Chờ cho đến khi người dùng nhấn phím bất kỳ
    # cv2.destroyAllWindows() # Đóng tất cả các cửa sổ OpenCV

# Gọi hàm để bắt đầu chương trình
if __name__ == "__main__":
    create_and_save_image_with_rectangles()