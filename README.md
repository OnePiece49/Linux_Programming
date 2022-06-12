# Linux_Programming
Nới bạn Việt lấy gốc cơ bản Linux


            /******************** OVERVIEW LINUX PROGRAMING ********************\


I. Bốn thành phần quan trọng trên một hệ thống ngoại vi:
    +, CPU
    +, Hệ thống ngoại vi
    +, Hệ thống bus
    +, CLock

II. Kiến trúc ARM
    --> Được viết tắt bởi:
        +, Application
        +, Realtime
        +, Microcontroller

    +, VD: kiến trúc ARM đời dòng A(Application):
        --> Thiên về lập trình ứng dụng người dùng(game,...)
        --> Tốn năng lượng.
        --> Khả năng xử lí cao.
    
    +, VD: kiến trúc ARM đời dòng R(Application):
        --> Ứng dụng vào các dự án có tính quan trọng về việc thời gian thực
        --> Được chia làm 2 loại:
            +, Hard-realtime: vd set deadline = 5s, thì phải chạy trước 5s
            +, Soft-realtime  vd set deadline = 5s, thì có thể chạy ở thời điểm 5,5s(chấp nhận được).
    +,  VD: kiến trúc ARM đời dòng M(Application): 
        --> Được sử dụng rộng rãi cho các hệ thống smarthome, iot
        --> Tiết kiệm năng lượng.

III. Bộ BSP:
    --> Bao gồm 4 thành phần:
        +, Bootloader:
            --> Bộ nạp khởi động, thành phần chạy đầu tiên trong hệ thộng
            --> Khởi động các thành phần cần thiết cho hệ thống: Ram, Bus, ổ cứng
        +, Linux Kernel:
            --> Sau khi Bootloader load thành công các thành phần hệ thống, thì sẽ thực hiên bước load Linux Kernel.
            --> Chức năng quan trọng nhất của Linux Kernel là:
                +, Quản lý điều khiển phần cứng: các chân ngoại vi như Serial, ISP,...
        +, Roofs:
            --> Đây là không gian chạy các ứng dụng application mình viết
                --> Như là terminal
        +, Toolchain:
            --> Là công cụ giúp mình phát triển ở trên phần application:
                +, Thư viện
                +, Trình biên dịch
                +, gcc, debugers  


IV. Cơ bản Linux - cmd:
    +, uanme -a: in ra version, phiên bản linux đang sử dụng
    +, Sử dụng vim:
        --> Để di chuyển xuống cuối file:
            --> Sử dụng command mode:
                +, Nhấn gg --> Về đầu file
                +, Nhấn shift g --> Về cuối file

        --> Để xóa 1 dòng:
            --> Nhấn dd

        --> Để mở số dòngL
            --> Gõ :set number

        --> Để mở file và nhảy xuống dòng 29 thì gõ:
            --> vim hello.txt +29

    +, Chuyển 1 file vào 1 folder khác:
        mv hello.txt include
        
