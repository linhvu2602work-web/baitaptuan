#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;
const int MAX_NODES = 11;
const int INF = 1000000;

// Cấu hình cặp dữ liệu: trọng số, đỉnh đến
typedef pair<int, int> NodePair;
string danhSachTinh[MAX_NODES] =
{
    "Ha Noi",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay"
};
struct Graph
{
    int totalNodes;
    int matrix[MAX_NODES][MAX_NODES];
};

// cau hinh do thi
void taoDoThi(Graph &soDo, int soLuongDinh)
{
    soDo.totalNodes = soLuongDinh;

    for(int i = 0; i < soLuongDinh; i++)
        for(int j = 0; j < soLuongDinh; j++)
            soDo.matrix[i][j] = 0;
}
// Ham noi tuyen duong
void noiTuyenDuong(Graph &soDo, int tinhA, int tinhB, int khoangCach)
{
    soDo.matrix[tinhA][tinhB] = khoangCach;
    soDo.matrix[tinhB][tinhA] = khoangCach;
}
// Ham hien thi
void hienThiBang(int bangSo[MAX_NODES][MAX_NODES], int kichThuoc)
{
    cout << setw(15) << "";

    for(int i = 0; i < kichThuoc; i++)
        cout << setw(12) << danhSachTinh[i];

    cout << endl;

    for(int i = 0; i < kichThuoc; i++)
    {
        cout << setw(15) << danhSachTinh[i];

        for(int j = 0; j < kichThuoc; j++)
            cout << setw(12) << bangSo[i][j];

        cout << endl;
    }
}
// Thuật toán Warshall kiểm tra khả năng thông suốt giữa các tỉnh
void chayWarshall(Graph soDo, int ketQuaLienThong[MAX_NODES][MAX_NODES])
{
    int total = soDo.totalNodes;

    for(int i = 0; i < total; i++)
    {
        for(int j = 0; j < total; j++)
        {
            if(i == j)
                ketQuaLienThong[i][j] = 1;
            else if(soDo.matrix[i][j] != 0)
                ketQuaLienThong[i][j] = 1;
            else
                ketQuaLienThong[i][j] = 0;
        }
    }

    for(int k = 0; k < total; k++)
    {
        for(int i = 0; i < total; i++)
        {
            for(int j = 0; j < total; j++)
            {
                if(ketQuaLienThong[i][j] == 0)
                    ketQuaLienThong[i][j] = ketQuaLienThong[i][k] && ketQuaLienThong[k][j];
            }
        }
    }
}
// Thuật toán Dijkstra tìm đường đi tối ưu bằng hàng đợi ưu tiên
void chayDijkstra(Graph soDo, int diemDau, int tuyenNganNhat[MAX_NODES], int vetDuongDi[MAX_NODES])
{
    int total = soDo.totalNodes;

    // Hàng đợi ưu tiên tự động sắp xếp các chặng ngắn nhất lên đầu
    priority_queue<NodePair, vector<NodePair>, greater<NodePair>> hangDoiUuTien;

    for(int i = 0; i < total; i++)
    {
        tuyenNganNhat[i] = INF;
        vetDuongDi[i] = -1;
    }

    tuyenNganNhat[diemDau] = 0;
    hangDoiUuTien.push({0, diemDau}); 

    while(!hangDoiUuTien.empty())
    {
        int dinhHienTai = hangDoiUuTien.top().second;
        int chiPhiHienTai = hangDoiUuTien.top().first;
        hangDoiUuTien.pop();

        if(chiPhiHienTai > tuyenNganNhat[dinhHienTai])
            continue;

        for(int dinhKe = 0; dinhKe < total; dinhKe++)
        {
            if(soDo.matrix[dinhHienTai][dinhKe] != 0) 
            {
                int chiPhiMoi = tuyenNganNhat[dinhHienTai] + soDo.matrix[dinhHienTai][dinhKe];
                if(chiPhiMoi < tuyenNganNhat[dinhKe])
                {
                    tuyenNganNhat[dinhKe] = chiPhiMoi;
                    vetDuongDi[dinhKe] = dinhHienTai;
                    hangDoiUuTien.push({chiPhiMoi, dinhKe}); 
                }
            }
        }
    }
}
// Hàm đệ quy xuất lộ trình di chuyển ra màn hình
void inLoTrinh(int diemCuoi, int vetDuongDi[])
{
    if(diemCuoi == -1)
        return;

    inLoTrinh(vetDuongDi[diemCuoi], vetDuongDi);

    if(vetDuongDi[diemCuoi] != -1)
        cout << " -> ";

    cout << danhSachTinh[diemCuoi];
}
int main()
{
    Graph banDoVietNam;
    taoDoThi(banDoVietNam, MAX_NODES);
    int dataTuyenDuong[][3] =
    {
        {0,6,1},   // Hà Nội - Hải Dương
        {6,7,1},   // Hải Dương - Hưng Yên
        {7,8,1},   // Hưng Yên - Phủ Lý
        {0,8,1},   // Hà Nội - Phủ Lý
        {0,9,1},   // Hà Nội - Hòa Bình
        {0,10,1},  // Hà Nội - Sơn Tây
        {0,1,1},   // Hà Nội - Thái Nguyên
        {0,2,1},   // Hà Nội - Bắc Ninh
        {2,3,1},   // Bắc Ninh - Bắc Giang
        {3,4,1},   // Bắc Giang - Uông Bí
        {2,4,1},   // Bắc Ninh - Uông Bí
        {4,5,1},   // Uông Bí - Hải Phòng
        {6,5,1}    // Hải Dương - Hải Phòng
    };

    int tongSoTuyen = sizeof(dataTuyenDuong) / sizeof(dataTuyenDuong[0]);

    for(int i = 0; i < tongSoTuyen; i++)
    {
        noiTuyenDuong(banDoVietNam, dataTuyenDuong[i][0], dataTuyenDuong[i][1], dataTuyenDuong[i][2]);
    }

    cout << " MA TRAN KE\n\n";
    hienThiBang(banDoVietNam.matrix, MAX_NODES);

    int maTranWarshall[MAX_NODES][MAX_NODES];
    chayWarshall(banDoVietNam, maTranWarshall);

    cout << "\n\nMA TRAN WARSHALL\n\n";
    hienThiBang(maTranWarshall, MAX_NODES);

    cout << "\n";
    if(maTranWarshall[0][4] == 1)
        cout << "\nTon tai duong di tu Ha Noi den Uong Bi\n";
    else
        cout << "\nKhong ton tai duong di tu Ha Noi den Uong Bi\n";

    int tuyenNganNhat[MAX_NODES];
    int vetDuongDi[MAX_NODES];

    //tìm đường đi tối ưu bắt đầu từ Hà Nội (0)
    chayDijkstra(banDoVietNam, 0, tuyenNganNhat, vetDuongDi);

    cout << "\nDIJKSTRA\n";
    cout << "\nKhoang cach ngan nhat tu Ha Noi den Uong Bi: " << tuyenNganNhat[4];
    
    cout << "\n\nDuong di ngan nhat:\n";
    inLoTrinh(4, vetDuongDi); 
    cout << endl;

    return 0;
}
