# Linux_Programming
Nới bạn Việt lấy gốc cơ bản Linux


            /******************** OVERVIEW LINUX PROGRAMING ********************\


I. Bốn thành phần quan trọng trên một hệ thống nhúng:
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

V. Hệ điều hành Linux: 
    +, OS là một phần mềm mà quản lý trực tiếp toàn bộ phần cứng của hệ thống, các tài nguyên như CPU, memory, các ổ cứng,...
        --> OS nằm giữa software và hardware, tạo liên kết giữa tất cả các phần mềm và các tài nguyên vật lý(memory, ổ cứng) để làm việc.
    +, Các thành phần của 1 hệ điều hành gồm:(Linux components)
        +, Bootloader
        +, OS Kernel
        +, Background service
        +, Graphics server
        +, Desktop environment
        +, Applications
    
    5.1 Các bước booting process:
        +, Bước 1: The BIOS Integrity Check (POST)- Kiểm tra tính toàn vẹn của BIOS:
            +, Khi hệ thống Linux được bật nguồn, BIOS (Basic Input Output System) khởi động và thực hiện Power On Self Test(Tự kiểm tra khi bật nguồn (POST)). Đây là một kiểm tra tính toàn vẹn.
            +, POST thăm dò khả năng hoạt động phần cứng của các thành phần như ổ cứng HDD hoặc SSD, Bàn phím, RAM, cổng USB và bất kỳ phần cứng nào khác. Nếu một số thiết bị phần cứng không được phát hiện hoặc nếu có trục trặc ở bất kỳ thiết bị nào, chẳng hạn như ổ cứng HDD hoặc SSD bị hỏng, thì một thông báo lỗi sẽ hiển thị trên màn hình và yêu cầu ta xử lý.
            +, Trong một số trường hợp, tiếng bíp sẽ phát ra, đặc biệt là trong trường hợp thiếu module RAM. Tuy nhiên, nếu phần cứng cần thiết ​​đủ và hoạt động như mong đợi, quá trình khởi động sẽ chuyển sang giai đoạn tiếp theo.

        +, Bước 2: The Bootloader (GRUB2)
            +, Khi quá trình POST hoàn tất, BIOS sẽ thăm dò MBR (Master Boot Record) để tìm thông tin về bộ nạp khởi động và phân vùng ổ cứng.
            +, MBR là mã code 512 byte nằm trên sector đầu tiên của ổ cứng, thường là /dev/sda hoặc /dev/hda tùy thuộc vào kiến ​​trúc ổ cứng của bạn. Tuy nhiên, lưu ý rằng đôi khi MBR có thể nằm trên USB Live hoặc DVD cài đặt Linux.
            +, Grup2 cho phép ta chọn Linux Kernel version ta muốn sử dụng 
        
        +, Bước 3: Khởi động Kernel:
        +, Bước 4: Bắt đầu systemd, với phiên bản cũ hơn là systemV
    
    5.2 OS Kernel:
        +, Kernel là một chương trình máy tính là trái tim và cốt lõi của Hệ điều hành
        +, Bất cứ khi nào hệ thống khởi động, Kernel là chương trình đầu tiên được tải sau bộ nạp khởi động vì Kernel phải xử lý phần còn lại của hệ thống cho Hệ điều hành. Kernel vẫn còn trong bộ nhớ cho đến khi Hệ điều hành tắt.
        +, Kernel chịu trách nhiệm về các tác vụ cấp thấp như quản lý đĩa, quản lý bộ nhớ, quản lý tác vụ,… Nó cung cấp giao diện giữa người dùng và các thành phần phần cứng của hệ thống. Khi một tiến trình thực hiện một yêu cầu tới Kernel, thì nó được gọi là System Call.
        +, Các chức năng của kernel:    
            +, Access Computer resource: Kernel có thể truy cập các tài nguyên máy tính khác nhau như CPU, thiết bị I/O và các tài nguyên khác. Nó đóng vai trò là cầu nối giữa người dùng và các tài nguyên của hệ thống.
            +, Resource Management: Kernel có nhiệm vụ chia sẻ tài nguyên giữa các tiến trình khác nhau theo cách mà mọi tiến trình đều có quyền truy cập thống nhất vào các tài nguyên
            +, Memory Management: Mọi process cần một số không gian bộ nhớ. Vì vậy, bộ nhớ phải được cấp phát và phân bổ để thực thi nó. Tất cả những quản lý bộ nhớ này được thực hiện bởi một Kernel.
            +, Device Management: Các thiết bị ngoại vi được kết nối trong hệ thống được sử dụng bởi các quy trình. Vì vậy, việc cấp phát các thiết bị này được quản lý bởi Kernel.
        
    5.3 Background services: 
        +, Được gọi là “daemon” trong Linux, những application nhỏ này hoạt động như những người phục vụ trong backgtound, đảm bảo rằng các chức năng chính như lập lịch, in ấn và đa phương tiện hoạt động chính xác. Chúng tải sau khi bạn khởi động hoặc khi bạn đã đăng nhập vào máy tính của mình.

    
        
