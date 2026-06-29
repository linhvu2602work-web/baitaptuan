void giaiThuatKruskal(DoThiGiaoThong &dt) {
    int n = dt.soDinh;
    int tongSoCanh = 0;
    TuyenDuong danhSachCanh[100]; 
    
    int maTranCayKhung[MAX_TINH][MAX_TINH] = {0}; 

    // Trích xuất các cạnh
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (dt.maTranKe[i][j] > 0) {   
                danhSachCanh[tongSoCanh] = {i, j, dt.maTranKe[i][j]}; 
                tongSoCanh++;    
            } 
        }
    }

    // Sắp xếp danh sách các cạnh tăng dần theo trọng sốo
    for (int i = 0; i < tongSoCanh - 1; i++) {   
        for (int j = i + 1; j < tongSoCanh; j++) {
            if (danhSachCanh[i].ts > danhSachCanh[j].ts) {
                swap(danhSachCanh[i], danhSachCanh[j]);  
            }
        }
    }

    
    cout << "THUAT TOAN KRUSKAL - Danh sach canh sau khi sap xep:\n"; 
    for (int i = 0; i < tongSoCanh; i++) {
        cout << TEN_TINH[danhSachCanh[i].u] << "-" << TEN_TINH[danhSachCanh[i].v] << ":" << danhSachCanh[i].ts << ((i < tongSoCanh - 1) ? ", " : "\n\n");
    }
    int tapCha[MAX_TINH];
    for (int i = 0; i < n; i++) {
        tapCha[i] = -1; 
    }

    cout << "Cac buoc phat trien cay khung:\n";
    for (int i = 0; i < tongSoCanh; i++) {
        int gocU = timGocTapHop(tapCha, danhSachCanh[i].u);
        int gocV = timGocTapHop(tapCha, danhSachCanh[i].v);

        // Nếu hai đỉnh không cùng gốc thì không tạo
        if (gocU != gocV) {  
            cout << "-> Them tuyen: " << TEN_TINH[danhSachCanh[i].u] << " - " << TEN_TINH[danhSachCanh[i].v] << " (" << danhSachCanh[i].ts << ")\n"; 
            
            // nhận cạnh này vào ma trận kề cây khung
            maTranCayKhung[danhSachCanh[i].u][danhSachCanh[i].v] = danhSachCanh[i].ts; 
            maTranCayKhung[danhSachCanh[i].v][danhSachCanh[i].u] = danhSachCanh[i].ts;
            
            // Hợp nhấtt 2 tập hợp lại với nhau
            tapCha[gocU] = gocV;            
        } 
    }

    // In ma trận 
    cout << "\nMA TRAN DINH KE CAY KHUNG MIN (PHUONG PHAP KRUSKAL):\n";
    hienThiMaTran(maTranCayKhung, n);
}
int main() {
    int n = MAX_TINH;
    DoThiGiaoThong doThi; 
    khoiTaoDoThi(doThi, n);
    
    //từ slide bài tập
    int cacTuyenGiaoThong[][3] = { 
        {0, 6, 1}, {6, 7, 2}, {8, 7, 3}, {0, 8, 4}, {0, 9, 5},    
        {0, 10, 6},{0, 1, 7}, {0, 2, 8}, {2, 3, 9}, {3, 4, 10}, 
        {2, 4, 11}, {4, 5, 12}, {6, 5, 13}   
    };
    int soLuongTuyen = sizeof(cacTuyenGiaoThong) / sizeof(cacTuyenGiaoThong[0]);
    
    for(int i = 0; i < soLuongTuyen; i++) { 
        themTuyenDuong(doThi, cacTuyenGiaoThong[i][0], cacTuyenGiaoThong[i][1], cacTuyenGiaoThong[i][2]);
    }
    
    cout <<" MA TRAN DO THI BAN DAU" << endl; 

    hienThiMaTran(doThi.maTranKe, n);


    //tính toán và in kết quả ma trận kề cây khung
    giaiThuatPrim(doThi);
    giaiThuatKruskal(doThi);
    
    return 0;
}