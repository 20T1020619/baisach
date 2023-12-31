#pragma once
#include "Const.h"

class LopTC{
private:
	int maLopTC;
	string maMH;
	int nienKhoa;
	int hocKy;
	int nhom;
	int svMax;
	int svMin;
	bool huyLop;
	int soSVDK;
	DSDK dsdk;
public:
	
	LopTC();
	
	void setMaLopTC(int maLopTC);
	
	void setMaMH(string maMH);
	
	void setNienKhoa(int khoa);
	
	void setHocKy(int hocKy);
	
	void setNhom(int nhom);
	
	void setSVMax(int svMax);
	
	void setSVMin(int svMin);
	
	void setTrangThai(bool huyLop);
	
	void setDSDK(DSDK DS);
	
	int getMaLopTC();
	
	string getMaMH();
	
	int getNienKhoa();
	
	int getHocKy();
	
	int getNhom();
	
	int getSVMax();
	
	int getSVMin();
	
	bool getTrangThai();
	
	DSDK &getDSDK();
	
	int getSoSVDK();
	
	void setSoSVDK(int soSVDK);
	
	void taoMaLop_LTC(int nLTC);
	
	bool checkTrung_LTC(LopTC ltc);
	
	void huyLopTC();
};

class DSLopTC{
private:
	LopTC *lopTC[MAX_LOPTC] = {NULL};
	int n;	
public:
	
	DSLopTC();
	
	int getN();
	
	bool isNull_LTC();
	
	bool isFull_LTC();
	
	LopTC *&getLopTC(int viTri);

	int them_LTC(LopTC *LTC);
	
	int xoa_LTC(int maLopTC);
	
	int tim_LTC(int maLopTC);
	
	void writeData_LTC(LopTC *LTC, ofstream &fileOut);
	
	void writeDataDS_LTC();
	
	void freeDS_LTC();

	int getMaLopTCMax();
	
	bool checkLopTC(string maMH);
	
	void huyLopDS_LTC();
	
	void huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK);
	
	int checkLopTheoKhoaVaHK_LTC(int khoa, int HK);
	
	void loadDataDS_DK();
	
	void loadDataDS_LTC();
	
	bool checkSVDK_LTC(int maLopTC, string maSV);
	
	bool checkDK_LTC(int viTri, string maSV);
	
	void dangKy_LTC(int viTri, NodeDK *DK);
	
	void dangKyMH_LTC(int maLopTC, NodeDK *DK);
	
	bool checkTrungDS_LTC(LopTC *ltc, int viTri, string maMH);
	
	void writeDataDS_DK();
	
	void xuatDS1Trang_LTC(LopTC *loptc[], MonHoc *arrMH, int soLuongMH,  int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac);
	
	void locDS_LTC(string content, LopTC *loptc[], LopTC *lopTC[], int &nFilter, int n, int &tongSoTrang);
	
	void xuatDSTheoTrang_LTC(TREE DSMH, int &viTriChon, Action &thaoTac, Button *menuButton[]);
	
	void resetChooseButton(Button *chooseButton[], LopTC *loptc[],  int n, string maMH, int viTriDaChon, int batDau, int ketThuc);
	
	void dangKyTheoLop_LTC(TREE DSMH, string maSV, int khoa, int HK, Action &thaoTac);
	
	void formDK_LTC(string &maSV, int &khoa, int &HK, Action &thaoTac);
	
	void formHuy_LTC(int &khoa, int &HK, Action &thaoTac);
	
	void formXuatDS_DK(int &viTriChon, Action &thaoTac);
	
	void formNhap_LTC(LopTC *loptc, TREE DSMH, Action &thaoTac, Button *menuButton[]);
	
	void xuatDiem1SVTheoTrang_LTC(TREE DSMH, string maSV, Action &thaoTac, Button *menuButton[]);
	
	string formXemDiemSV_LTC(DSLopSV DSLSV, Action &thaoTac);
	
	int locCacLopDK_LTC(MonHoc *arrMH, int soLuongMH, string maSV);
	
	void thongKeDiemTB_LSV(DSSV &dssv, TREE &DSMH, float *diemTB, int tongSoDong);
	
	void xuatDiemTB1Trang_LSV(NodeSV *&head, float *diemTB, int batDau, int ketThuc, Table newTable);
	
	void xuatDiemTBTheoTrang_LSV(TREE &DSMH, DSSV &dssv, Action thaoTac, Button *menuButton[]);
	
	void thongKeDiemTK_LSV(DSSV &dssv, MonHoc *arrMH, int soLuongMH, float **diemTK, int tongSoDong);
	
	void xuatMonHocTK1Trang_LSV(MonHoc *arrMH, int soLuongMH, float **diemTK, int batDau, int ketThuc, int batDauMH, int ketThucMH, Table newTable);
	
	void xuatSinhVienTK1Trang_LSV(NodeSV *&head, float **diemTK, int batDau, int ketThuc, int batDauMH, int ketThucMH, Table newTable);
	
	void xuatDiemTKTheoTrang_LSV(TREE &DSMH, DSSV &dssv, Action thaoTac, Button *menuButton[]);
	
	void menu_LTC(TREE &DSMH, DSLopSV DSLSV, Action thaoTac, Button *menuButton[]);
	
};

/*
** ================ LopTC ================
*/

LopTC::LopTC(){
	maLopTC = 0;
	maMH = "";
	nienKhoa = 0;
	hocKy = 0;
	nhom = 0;
	svMax = 0;
	svMin = 0;
	huyLop = false;
	soSVDK = 0;
	dsdk.setHead_DSDK(NULL);
}

void LopTC::setMaLopTC(int maLopTC){
	this->maLopTC = maLopTC;	
}

void LopTC::setMaMH(string maMH){
	this->maMH = maMH;
}

void LopTC::setNienKhoa(int khoa){
	this->nienKhoa = khoa;
}

void LopTC::setHocKy(int hocKy){
	this->hocKy = hocKy;
}

void LopTC::setNhom(int nhom){
	this->nhom = nhom;
}

void LopTC::setSVMax(int svMax){
	this->svMax = svMax;
}

void LopTC::setSVMin(int svMin){
	this->svMin = svMin;
}

void LopTC::setTrangThai(bool huyLop){
	this->huyLop = huyLop;
}
void LopTC::setDSDK(DSDK DS){
	this->dsdk = DS; 
}
	
int LopTC::getMaLopTC(){
	return this->maLopTC;	
}

string LopTC::getMaMH(){
	return this->maMH;
}

int LopTC::getNienKhoa(){
	return this->nienKhoa;
}

int LopTC::getHocKy(){
	return this->hocKy;
}

int LopTC::getNhom(){
	return this->nhom;
}

int LopTC::getSVMax(){
	return this->svMax;
}

int LopTC::getSVMin(){
	return this->svMin;
}

bool LopTC::getTrangThai(){
	return this->huyLop;
}

DSDK &LopTC::getDSDK(){
		return this->dsdk;
	}
	
int LopTC::getSoSVDK(){
		return this->soSVDK;
	}
	
void LopTC::setSoSVDK(int soSVDK){
		this->soSVDK = soSVDK;
	}
	
void LopTC::taoMaLop_LTC(int nLTC)	{
			this->maLopTC = nLTC +1;
		}
	
bool LopTC::checkTrung_LTC(LopTC ltc){
		
		if(this->maMH == ltc.maMH && this->nienKhoa == ltc.nienKhoa && (this->hocKy == ltc.hocKy && this->nhom == ltc.nhom)){
			return true;
		}
			
		return false;
	}
	
void LopTC::huyLopTC(){
		if(soSVDK < svMin && huyLop == false)
		//if(soSVDK != 0 && soSVDK < svMin && huyLop == false)
			this->huyLop = true;
	}


/*
** ================ Danh sach LopTC ================
*/

DSLopTC::DSLopTC(){
	n = 0;
}

int DSLopTC::getN(){
	return this->n;
}

bool DSLopTC::isNull_LTC(){
	return this->n == 0;
}

bool DSLopTC::isFull_LTC(){
	return this->n >= MAX_LOPTC;
}

int DSLopTC::tim_LTC(int maLopTC){
	for(int i=0; i<this->n; i++)
		if(this->lopTC[i]->getMaLopTC() == maLopTC)
			return i;
	return -1;
}

int DSLopTC::them_LTC(LopTC *LTC){
	if(isFull_LTC()) return 0;
	
	this->lopTC[this->n++] = LTC;
	return 1;
}

int DSLopTC::xoa_LTC(int maLopTC){
	
	int viTri = tim_LTC(maLopTC);
	if(viTri>=0){
		// xoa dsdk cua lop tc bi huy
		if(!lopTC[viTri]->getDSDK().isNull_DK()) 
			lopTC[viTri]->getDSDK().freeDS_SV(lopTC[viTri]->getDSDK().getHead_DSDK());
		
		delete this->lopTC[viTri];
		
		for (int i = viTri; i < this->n; i++)
			this->lopTC[i] = this->lopTC[i + 1];

		this->n--;
		
			MessageBox(
				    NULL,
				    "XOA LOP TIN CHI THANH CONG !!!",
				    "THONG BAO",
				    MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		    	);
		return 1;
	}
	
	return -1;
	
}

LopTC *&DSLopTC::getLopTC(int viTri){
		return lopTC[viTri];
		
	}

void DSLopTC::writeDataDS_LTC(){
		ofstream fileOut;
		fileOut.open(PATH_LTC.c_str(), ios::out);
		if (fileOut.is_open()) {
			for (int i = 0; i < this->n; i++) {
				writeData_LTC(this->lopTC[i], fileOut);
			}
			
		}
		fileOut.close();
	}

void DSLopTC::freeDS_LTC(){
		for(int i=0; i<n; i++){
			if(this->lopTC[i] != NULL){
				lopTC[i]->getDSDK().freeDS_SV(lopTC[i]->getDSDK().getHead_DSDK());
				delete lopTC[i];
			}
		}
	}

int DSLopTC::getMaLopTCMax(){
		int max = -1;
		if(n>0){
			max = lopTC[0]->getMaLopTC();
			for(int i=1; i<n; i++){
				if(max < lopTC[i]->getMaLopTC())
					max = lopTC[i]->getMaLopTC();
			}
		}
		return max;
	}

bool DSLopTC::checkLopTC(string maMH){
		
		for(int i=0; i<n; i++)
			if(lopTC[i]->getMaMH() == maMH)
				return true;
		
		return false;
	}

void DSLopTC::huyLopDS_LTC(){
		for(int i=0; i<n; i++)
			this->lopTC[i]->huyLopTC();
	}

void DSLopTC::huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK)
				this->lopTC[i]->huyLopTC();
		}
	}

int DSLopTC::checkLopTheoKhoaVaHK_LTC(int khoa, int HK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK)
				return i;
		}
		
		return  -1;
	}

void DSLopTC::loadDataDS_DK(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp; int maLop; int viTriLop=0; string tempStr; float tempFloat;
		fileIn.open(PATH_DK.c_str(), ios::in);
		if (fileIn.is_open())	{
			
				while (!fileIn.eof())	{
					
					fileIn >> maLop;
					viTriLop = this->tim_LTC( maLop);
					if (viTriLop != -1)	{
						fileIn >> temp;
						SVDangKy sv;
						
						getline(fileIn, tempStr, ',');
						sv.setMaSV(tempStr);
						fileIn >> tempFloat;
						sv.setDiem(tempFloat);
						
						if(this->lopTC[viTriLop]->getDSDK().checkSV_DK(sv.getMaSV())) continue;
						
						NodeDK* DK = new NodeDK(sv);
	
						//cout <<maLop<<" "<<viTriLop<<" " <<DK->data.MASV << " " << DK->data.DIEM<<endl;
						
						this->lopTC[viTriLop]->getDSDK().them_DK(DK);
						this->lopTC[viTriLop]->setSoSVDK(this->lopTC[viTriLop]->getSoSVDK() + 1);
					}else { fileIn >> temp; getline(fileIn, tempStr, ','); fileIn>>tempFloat;
					}
	
	
					if (fileIn.eof()) break;
	
				}
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS SINH VIEN DK ";
			LIST_DATA = "DS SINH VIEN DK";
			loadFileIsSuccess = false;
		}
		
		fileIn.close();
	}

void DSLopTC::loadDataDS_LTC(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp;
		fileIn.open(PATH_LTC.c_str(), ios::in);
		if(fileIn.is_open()){
			int tempInt; string tempStr;
			while (!fileIn.eof())
			{
				
				lopTC[n] = new LopTC;
				fileIn >> tempInt;	lopTC[n]->setMaLopTC(tempInt);
				if(tempInt==0) break;
				fileIn >> temp;
				getline(fileIn, tempStr, ','); lopTC[n]->setMaMH(tempStr);
				fileIn >> tempInt; lopTC[n]->setNienKhoa(tempInt);
				fileIn >> temp;
				fileIn >> tempInt; lopTC[n]->setHocKy(tempInt);
				fileIn >> temp;
				fileIn >> tempInt; lopTC[n]->setNhom(tempInt);
				fileIn >> temp;
				fileIn >> tempInt; lopTC[n]->setSVMax(tempInt);
				fileIn >> temp;
				fileIn >> tempInt; lopTC[n]->setSVMin(tempInt);
				fileIn >> temp;
				fileIn >> tempInt; lopTC[n]->setTrangThai(bool(tempInt));
				
		
				lopTC[n]->getDSDK().setHead_DSDK(NULL);
				
		
				this->n++;
		
				if (fileIn.eof()) break;
			}
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS LOP TC";
			LIST_DATA = "DS LOP TIN CHI";
			loadFileIsSuccess = false;
		}
		fileIn.close();
	}

bool DSLopTC::checkSVDK_LTC(int maLopTC, string maSV){
		int vt = 0;
		for(; vt<n && this->lopTC[vt]->getMaLopTC() != maLopTC; vt++);
		
		if(lopTC[vt]->getMaLopTC() == maLopTC)
			return this->lopTC[vt]->getDSDK().checkSV_DK(maSV);
		
		return false;
	}

bool DSLopTC::checkDK_LTC(int viTri, string maSV){
		
		if(viTri < n ){
			return this->lopTC[viTri]->getDSDK().checkSV_DK(maSV);
		}
		
		return false;
	}

void DSLopTC::dangKy_LTC(int viTri, NodeDK *DK){
		if(viTri < n){
			
			this->lopTC[viTri]->getDSDK().them_DK(DK);
			
			this->lopTC[viTri]->setSoSVDK(this->lopTC[viTri]->getSoSVDK() + 1);
		}
	}

void DSLopTC::writeData_LTC(LopTC *LTC, ofstream &fileOut){
	char temp = ',';
	fileOut << LTC->getMaLopTC();
	fileOut << temp;
	fileOut << LTC->getMaMH();
	fileOut << temp;
	fileOut << LTC->getNienKhoa();
	fileOut << temp;
	fileOut << LTC->getHocKy();
	fileOut << temp;
	fileOut << LTC->getNhom();
	fileOut << temp;
	fileOut << LTC->getSVMax();
	fileOut << temp;
	fileOut << LTC->getSVMin();
	fileOut << temp;
	fileOut << LTC->getTrangThai();
	fileOut<<"\n";
}

void DSLopTC::dangKyMH_LTC(int maLopTC, NodeDK *DK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getMaLopTC() == maLopTC){
				dangKy_LTC(i, DK); return;
			}
		}
	}

bool DSLopTC::checkTrungDS_LTC(LopTC *ltc, int viTri, string maMH){
		if(this->isNull_LTC()) return false;
		
		for(int i=0; i<n; i++){
			if(i != viTri && this->lopTC[i]->getMaMH() == maMH)
				if(this->lopTC[i]->checkTrung_LTC(*(ltc))) return true;
		}
		
		return false;
	}

void DSLopTC::writeDataDS_DK(){
		ofstream fileOut;
		fileOut.open(PATH_DK.c_str(), ios::out);
		if (fileOut.is_open())	{
				for (int i = 0; i < n; i++)	{
					for(NodeDK *k = this->lopTC[i]->getDSDK().getHead_DSDK(); k!= NULL; k=k->getNext_DK())	{
							k->writeData_DK(k->getData_DK(), this->lopTC[i]->getMaLopTC(), fileOut);
							if(k->getNext_DK() != NULL || i + 1 != n ) fileOut << "\n";
						}
						
				}
			
		}
		fileOut.close();
	}

void DSLopTC::xuatDS1Trang_LTC(LopTC *loptc[], MonHoc *arrMH, int soLuongMH,  int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac){
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		 
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;	string trangThai="TRUE"; int viTriMH=0;
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		
		for(int i = batDau; i < soDong; i++){ 
			
			setbkcolor(cllightwhite); setcolor(clblack); 
			yBtn += rowTableHeight;
			
			// in ra chuoi rong cac dong con thua
			if(i >= ketThuc){
				//setbkcolor(clyellow);
				y +=  rowTableHeight;
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); 	x += newTable.getCols(0)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth() -4- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(3)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() -2 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(4)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(5)->getWidth() -2 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(5)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(6)->getWidth()-3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(6)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(7)->getWidth() -3- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(7)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(8)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(8)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(9)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(9)->getWidth();
			if(thaoTac != DIEM_SV){
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(10)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(10)->getWidth();
				
				View view("",x,yBtn, x+newTable.getCols(11)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
				view.draw();
			}
				x =  tableLeft;
				continue;
			}
		
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			// xuat du lieu moi
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(1)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getMaLopTC()).c_str())/2, 
						y, 
						convertIntToString(loptc[i]->getMaLopTC()).c_str()
					);
					
				x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth() -4- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(2)->getWidth()/2  - textwidth(loptc[i]->getMaMH().c_str())/2, 
						y, 
						loptc[i]->getMaMH().c_str()
					);				
				x += newTable.getCols(2)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			// lay ten mon hoc	
			for(int j=0; j<soLuongMH; j++){
				if(arrMH[j].getMaMH() == loptc[i]->getMaMH()){
					viTriMH=j; break; //j = soLuongMH;
				}
			}
				
			// xuat du lieu moi
				outtextxy(
						x + 10,
						y, 
						arrMH[viTriMH].getTenMH().c_str()
					);				
				x += newTable.getCols(3)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getNienKhoa()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getNienKhoa()).c_str()
					);
				x += newTable.getCols(4)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(5)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(5)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getHocKy()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getHocKy()).c_str()
					);
				x += newTable.getCols(5)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(6)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(6)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getNhom()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getNhom()).c_str()
					);
				x += newTable.getCols(6)->getWidth();
			
		if(thaoTac != DIEM_SV){	
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(7)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(7)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMax()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMax()).c_str()
					);
				x += newTable.getCols(7)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(8)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(8)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMax() - loptc[i]->getSoSVDK()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMax() - loptc[i]->getSoSVDK()).c_str()
					);
				x += newTable.getCols(8)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(9)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(9)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMin()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMin()).c_str()
					);
				x += newTable.getCols(9)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(10)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
			
				trangThai = loptc[i]->getTrangThai() ? "TRUE" : "FALSE";	
			
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(10)->getWidth()/2  - textwidth(trangThai.c_str())/2,
						y, 
						trangThai.c_str()
					);
				x += newTable.getCols(10)->getWidth();
			
			if(thaoTac != DIEM && thaoTac != DK_LTC && thaoTac != DIEM_SV){
				// ve button sua 
				if(editButton[i] == NULL)
					editButton[i] = new Button(
												"Sua",
												strSTT, 
												x+3, 
												yBtn+3, 
												x+checkBoxButtonWidth,
												yBtn-3+checkBoxButtonHeight, 
												claqua, 
												cllightblue, 
												clblack
											);
					editButton[i]->draw();
					x += checkBoxButtonWidth + buttonActionSpace;
				
				// ve button xoa 
				if(deleteButton[i] == NULL)	
					deleteButton[i] = new Button(
												"Xoa",
												strSTT, 
												x+3, 
												yBtn+3, 
												x+checkBoxButtonWidth,
												yBtn-3+checkBoxButtonHeight, 
												cllightred, 
												clred, 
												cllightwhite 
											);
					deleteButton[i]->draw();
			}else if(thaoTac == DIEM){
				if(editButton[i] == NULL)
					editButton[i] = new Button(
										 "Xem Diem",
										 strSTT, 
										 x+15, 
										 yBtn+3, 
										 x+15+checkBoxButtonWidth+30,
										 yBtn-3+checkBoxButtonHeight, 
										 claqua, 
										 cllightblue, 
										 clblack
									);
				editButton[i]->draw();
			}else if(thaoTac == DK_LTC){
				if(editButton[i] == NULL)
					editButton[i] = new Button(
											"Dang ky",
											strSTT, 
											x+15, 
											yBtn+3, 
											x+45+checkBoxButtonWidth,
											yBtn-3+checkBoxButtonHeight, 
											claqua, 
											cllightblue, 
											clblack
										);
				editButton[i]->draw();
			}
		}else{
				// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(7)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(7)->getWidth()/2  - textwidth(convertIntToString(arrMH[viTriMH].getSTCLT()).c_str())/2,
						y, 
						convertIntToString(arrMH[viTriMH].getSTCLT()).c_str()
					);
				x += newTable.getCols(7)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(8)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(8)->getWidth()/2  - textwidth(convertIntToString(arrMH[viTriMH].getSTCTH()).c_str())/2,
						y, 
						convertIntToString(arrMH[viTriMH].getSTCTH()).c_str()
					);
				x += newTable.getCols(8)->getWidth();
				
			if(thaoTac == DIEM_SV){
				if(editButton[i] != NULL)
					editButton[i]->draw();
			}
		}
				
			x = tableLeft;
		}
	}


void DSLopTC::locDS_LTC(string content, LopTC *loptc[], LopTC *lopTC[], int &nFilter, int n, int &tongSoTrang){
		// reset so lop tin chi loc ra duoc
		nFilter = 0; string strMaLopTC;
		if(!content.empty()){
			for(int i=0; i<n; i++){
				strMaLopTC = convertIntToString(lopTC[i]->getMaLopTC());
				if(strMaLopTC.find(content) != string::npos){
					loptc[nFilter++] = lopTC[i];
				}
			}
		}else {
			for(int i=0; i<n; i++){
				loptc[nFilter++] = lopTC[i];
			}
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
	}
	

void DSLopTC::xuatDSTheoTrang_LTC(TREE DSMH, int &viTriChon, Action &thaoTac, Button *menuButton[]){
		int tongSoDong = n;
		int nFilter = n; int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0; 
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH); 
		
		LopTC *loptc[n] = {NULL};
		for(int i=0; i<n; i++) {
		 	loptc[i] = this->lopTC[i];
		}
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *editButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		
		
		Table newTable = table_LTC();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ma lop tc:" ,"N", 5, NUMBER, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
		newInput.requestFocus();
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnThem("THEM LTC","them", 300, 80, 320 + buttonWidth, 120);
		Button btnXuat("XEM DSSV","xuat", 410, 80, 410 + buttonWidth, 120);
		Button btnHuyLTC("HUY LTC", "huy", 500, 80, 500 + buttonWidth, 120);
		Button btnDangKy("DANG KY LTC","dang_ky", 590, 80, 610 + buttonWidth, 120);
		Button btnDiemSV("DIEM 1 SV", "diem_sv", 332, 80, 340 + buttonWidth, 120);
		Button btnDiemTB("Diem TB", "diem_tb", 440, 80, 440 + buttonWidth, 120);
		Button btnDiemTK("Diem TK", "diem_tk", 540, 80, 540 + buttonWidth, 120);
		
		if(thaoTac == DIEM){
			btnDiemSV.draw();
			btnDiemTB.draw();
			btnDiemTK.draw();
		}
			
		
		if(thaoTac == XUAT || thaoTac == THEM || thaoTac == SUA)	{
			btnThem.draw();
			btnXuat.draw();
			btnHuyLTC.draw();
			btnDangKy.draw();
		}
		
		if(thaoTac == THEM || thaoTac == SUA) {
			newTable.freeTable();
			freeArrButton(editButton, nFilter);
			freeArrButton(deleteButton, nFilter);
			return;
		}
		
		int x,y;
		bool exitLoop = false;
		
		while(!exitLoop){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	clearmouseclick(WM_LBUTTONDOWN);
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
				
				indexMenu = isClickMenuButton(menuButton, x,y);
				if(indexMenu != -1){
					if(indexMenu == nMenuButton - 1){
            			exitProgram = isExit();
            			if(exitProgram)
            				exitLoop = true;
            			else indexMenu = -1;
            			continue;	
					}            			
					else {
						
						exitLoop = true; continue;
					}
					
				}
            	
            	if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
					if(thaoTac != DIEM) {
						if(editButton[i] != NULL && deleteButton[i] != NULL){
							// btn sua
							if(editButton[i]->isClicked(x,y)){
								int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								thaoTac = SUA;
								newTable.freeTable();
								delete[] arrMH;
								freeArrButton(editButton, nFilter);
								freeArrButton(deleteButton, nFilter);
								return; 
							}
							// btn xoa
						if(deleteButton[i]->isClicked(x,y)){
							// tim vi tri thuc(real) cua lop tc can xoa khi sau da filter trong mang lopTC
							int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								if(lopTC[viTriChon]->getSoSVDK() == 0 || lopTC[viTriChon]->getTrangThai()){
									int isConfirmed = MessageBox(
													        NULL,
													        "BAN CO CHAC CHAN MUON XOA LOP TIN CHI NAY",
													        "THONG BAO",
													        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												    		);
												    		
									switch(isConfirmed){
										case IDCANCEL:{
												viTriChon=0;
												break;
											}
										
										case IDOK: default:{
												
												thaoTac = XOA;
												newTable.freeTable();
												delete[] arrMH;
												freeArrButton(editButton, nFilter);
												freeArrButton(deleteButton, nFilter);
												return; 	
											}
									}
								} else {
									MessageBox(
										       NULL,
										       "LOP DA CO SINH VIEN, KHONG THE XOA !!!",
										       "THONG BAO",
										       MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								    		);
								}
							}
						}
					}else{ // xem diem
						if(editButton[i] != NULL){
							if(editButton[i]->isClicked(x,y)){
								// tim vi tri thuc(real) cua lop tc can xoa khi sau da filter trong mang lopTC
								int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								
								if(lopTC[viTriChon]->getSoSVDK() != 0){
									thaoTac = DIEM;
									newTable.freeTable();
									delete[] arrMH;
									freeArrButton(editButton, nFilter);
									freeArrButton(deleteButton, nFilter);
									return;
								}else{
									MessageBox(
										    NULL,
										    "LOP CHUA CO SINH VIEN DANG KY !!!",
											"THONG BAO",
										    MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									    );
								}
							}
						}
					}
				
				}
        		
        		if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				if(btnHuyLTC.isClicked(x,y) && thaoTac != DIEM){
					thaoTac = HUY_LTC; 
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return; 
					
				}
				
				if(btnXuat.isClicked(x,y) && thaoTac != DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = XUAT_DS; 
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return;
					
				}
				
				if(btnThem.isClicked(x,y) && thaoTac != DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = THEM;
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return;
				}
				
				if(btnDangKy.isClicked(x,y) && thaoTac != DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = DK_LTC;
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return;
				}
				
				if(btnDiemSV.isClicked(x,y) && thaoTac == DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					thaoTac = DIEM_SV;
					exitLoop = true;
					continue;
					
				}else if(btnDiemTB.isClicked(x,y) && thaoTac == DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					thaoTac = DIEM_TB;
					exitLoop = true;
					continue;
				}else if(btnDiemTK.isClicked(x,y) && thaoTac == DIEM){
					newInput.setBorderColor(clblack);
					newInput.draw();
					thaoTac = DIEM_TK;
					exitLoop = true;
					continue;
				}
				
			}
			
			// Filter by input
			if(kbhit()){
				freeArrButton(editButton, nFilter);
				freeArrButton(deleteButton, nFilter);
				char ch = getch();
				newInput.appendText(ch);
				//newInput.xuLyNhapMa_LSV(ch);
				newInput.draw();
				locDS_LTC(newInput.getContent(), loptc, lopTC, nFilter, tongSoDong, tongSoTrang);
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		}
	
		delete[] arrMH;
		newTable.freeTable();
		freeArrButton(editButton, nFilter);
		freeArrButton(deleteButton, nFilter);
	}

void DSLopTC::resetChooseButton(Button *chooseButton[], LopTC *loptc[],  int n, string maMH, int viTriDaChon, int batDau, int ketThuc){
		for(int i=0; i<n; i++){
			if(loptc[i]->getMaMH() == maMH && i != viTriDaChon && chooseButton[i]->getId() != "da_du"){
				if(chooseButton[i]->getId() != "khong_duocchon"){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("khong_duocchon");
					chooseButton[i]->setOffEnable();
					if(batDau <= i && i < ketThuc)
						chooseButton[i]->draw();
				}else {
					chooseButton[i]->setBGColor(claqua);
					chooseButton[i]->setId("");
					chooseButton[i]->setEnable();
					if(batDau <= i && i < ketThuc)
						chooseButton[i]->draw();
				}
				
			}else if(i == viTriDaChon && chooseButton[i]->getId() != "da_du"){
				if(chooseButton[i]->getId() != "dangky" && chooseButton[i]->getId() != "da_dangky"){
					chooseButton[i]->setBGColor(cllightgreen);
					chooseButton[i]->setId("dangky");
					chooseButton[i]->draw();
				}else if(chooseButton[i]->getId() != "da_dangky"){
					chooseButton[i]->setBGColor(claqua);
					chooseButton[i]->setId("");
					chooseButton[i]->draw();
				}
			}
		}
	}

void DSLopTC::dangKyTheoLop_LTC(TREE DSMH, string maSV, int khoa, int HK, Action &thaoTac){
		
		int tongSoDong = 0;
		
		// dem xem co bao nhieu ltc thoa man khoa, hk duoc nhap vao
		for(int i=0; i<n; i++){
			if(lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK) 
				tongSoDong++;
		}
		
		if(tongSoDong  == 0){
			
			MessageBox(
					NULL,
					"KHONG TIM THAY LOP TIN CHI !!!",
					"THONG BAO",
					 MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				);
			
			thaoTac = THOAT;
			return;
		}
		
		int nFilter = 0; int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0;
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);
		
		nFilter = tongSoDong;
		LopTC *loptc[nFilter] = {NULL};
		nFilter = 0;
		for(int i=0; i<n; i++){
			if(lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK) 
				loptc[nFilter++] = lopTC[i];
 		}
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *chooseButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_LTC();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnSave("Luu","luu",380, 80, 380 + buttonWidth, 120);
		btnSave.draw();
		btnSave.requestFocus();
		
		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		int xBtn=tableLeft; int yBtn = tableTop+rowTableHeight;
		for(int i=0; i<newTable.getNumOfCols()-1; i++) xBtn += newTable.getCols(i)->getWidth();
		
		for(int i=ketThuc; i<nFilter; i++){
			if(chooseButton[i] == NULL){
				if(ketThuc % MAX_DONG_1_TRANG) yBtn = tableTop+rowTableHeight;
				chooseButton[i] = new Button(
										"Dang ky",
										convertIntToString(i+1), 
										xBtn+15, 
										yBtn+3, 
										xBtn+15+checkBoxButtonWidth+30,
										yBtn-3+checkBoxButtonHeight, 
										claqua, 
										cllightblue, 
										clblack
									);
				yBtn += rowTableHeight;
				
			}
		}
		
		// kiem tra nhung lop tc da dang ki truoc do trong nien khoa, hoc ki da nhap
		for(int i=batDau; i<nFilter; i++){
			if(chooseButton[i] != NULL){
				if(this->checkSVDK_LTC(loptc[i]->getMaLopTC(),maSV)){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("da_dangky");
					chooseButton[i]->setText("Da DK");
					chooseButton[i]->setOffEnable();
					chooseButton[i]->draw();
					resetChooseButton(chooseButton, loptc, nFilter, loptc[i]->getMaMH(), i, batDau, ketThuc);
				}
				
				if((loptc[i]->getSVMax() - loptc[i]->getSoSVDK()) == 0){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("da_du");
					chooseButton[i]->setText("Da du sv");
					chooseButton[i]->setOffEnable();
					
				}
			}
		}
		
		// da_dangky, dangky, ko_duocchon
		int x,y; char ch;
		
		while(true){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	clearmouseclick(WM_LBUTTONDOWN);
            	
            	for(int i=batDau; i<ketThuc; i++){
            		if(chooseButton[i]->isClicked(x,y) && chooseButton[i]->getEnable()){
            			resetChooseButton(chooseButton, loptc, nFilter, loptc[i]->getMaMH(), i, batDau, ketThuc);
					}
				}
				
				if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            	
            		
            		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
					
					
					
				}
				else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					
					
					xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
					
				}else if(btnBack.isClicked(x,y)){
					
					int isConfirmed = MessageBox(NULL,
												"CAC THAY DOI CUA BAN SE KHONG DUOC LUU",
												"THONG BAO",
												MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												);
												    		
					switch(isConfirmed){
						case IDCANCEL:{
								break;
						}
										
						case IDOK: default:{	
								thaoTac = THOAT;
			            		newTable.freeTable();
								delete[] arrMH;
								freeArrButton(chooseButton, nFilter);
								return; 	
						}
					}
				
				}else if(btnSave.isClicked(x,y)){
					
					for(int i=0; i<tongSoDong; i++){
						if(chooseButton[i]->getId() == "dangky"){
							SVDangKy sv(maSV);
							NodeDK * dk = new NodeDK(sv);
							
							if(dk != NULL) this->dangKyMH_LTC(loptc[i]->getMaLopTC(), dk);
						}
					}
					
					delete[] arrMH;
					freeArrButton(chooseButton, tongSoDong);
					newTable.freeTable();
					return;
				}
				
			}
			
		} // end while
	}

void DSLopTC::formDK_LTC(string &maSV, int &khoa, int &HK, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "Dang ky TC");
		
		int nInput = 3;
		Input *input[nInput] = {NULL};
		
		int left = 650;
		int top = 220;
		
		input[0] = new Input("", "Ma sinh vien ", "0", MAX_MASV, STUDENT_ID, left, top, left+300, top+INPUT_HEIGHT);
		input[1] = new Input("", "Nien khoa ", "1", 4, NUMBER, left, top+INPUT_HEIGHT+20, left+300, top + INPUT_HEIGHT*2 +20);
		input[2] = new Input("", "Hoc ky ", "2", 1, NUMBER, left, top+INPUT_HEIGHT*2+20*2, left+300, top + INPUT_HEIGHT*3 +20*2);
		
		Button btnTT("Tiep tuc","TT",left, top+180, left+buttonWidth, top+INPUT_HEIGHT+190, claqua, cllightblue, clblack);
		btnTT.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+180, 850+buttonWidth, top+INPUT_HEIGHT+190, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		int x,y; char ch;
		int oldIndexInput=-1;
		int indexInput=0;
		
		bool isFullInfo = true;
		input[0]->setContent(maSV);
		
		if(khoa != 0)
			input[1]->setContent(convertIntToString(khoa));
		if(HK != 0)
			input[2]->setContent(convertIntToString(HK));
		
		input[indexInput]->requestFocus();
		
		for(int i=0; i<nInput; i++){
			input[i]->draw();
		}
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				for(int i=0; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
				
				if(btnTT.isClicked(x,y)){
					isFullInfo = true;
					
					for(int i=0; i<nInput; i++){
						if(input[i]->getContent().empty()){
							isFullInfo = false; 
							input[i]->requestFocus();
							input[indexInput]->draw();
							indexInput = i;
							input[indexInput]->draw();
							break;
						}
					}
					
					if(isFullInfo){
						
						maSV = input[0]->getContent();
						khoa = atoi(input[1]->getContent().c_str());
						HK = atoi(input[2]->getContent().c_str());
						
						for(int i=0; i<nInput; i++){
							delete input[i];
						}
						return;
						
					}else{
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					}
					
					
				}else if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					for(int i=0; i<nInput; i++){
						if(input[i] != NULL) delete input[i];
					}
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == TAB){
					oldIndexInput = indexInput;
					if(++indexInput == nInput) indexInput = 0;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
				}else if(ch == ENTER){
					isFullInfo = true;
					
					for(int i=0; i<nInput; i++){
						if(input[i]->getContent().empty()){
							isFullInfo = false; 
							input[i]->requestFocus();
							input[indexInput]->draw();
							indexInput = i;
							input[indexInput]->draw();
							break;
						}
					}
					
					if(isFullInfo){
						
						maSV = input[0]->getContent();
						khoa = atoi(input[1]->getContent().c_str());
						HK = atoi(input[2]->getContent().c_str());
						
						for(int i=0; i<nInput; i++){
							delete input[i];
						}
						return;
						
					}else{
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					}
				}
				
				input[indexInput]->appendText(ch);
				input[indexInput]->draw();
			}
		}
		
		for(int i=0; i<nInput; i++) delete input[i];
		
	}

void DSLopTC::formHuy_LTC(int &khoa, int &HK, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "Huy lop TC");
		
		int nInput = 2;
		Input *input[nInput] = {NULL};
		
		int left = 650;
		int top = 220;
		
		input[0] = new Input("","Nien khoa ","0", 4, NUMBER, left, top, left + 300, top + INPUT_HEIGHT );
		input[1] = new Input("","Hoc ky ","1",1, NUMBER, left, top+INPUT_HEIGHT+20, left+300, top + INPUT_HEIGHT*2 +20);
		
		Button btnHuy("Huy","H",left, top+130, left+buttonWidth, top+INPUT_HEIGHT+130, clyellow, clblack, clblack);
		btnHuy.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+130, 850+buttonWidth, top+INPUT_HEIGHT+130, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		int x,y; char ch;
		string notification;
		
		for(int i=0; i<nInput; i++){
			if(input[i] != NULL)
				input[i]->draw();
		}
		
		int oldIndexInput=-1;
		int indexInput=0;
		
		input[indexInput]->requestFocus();
		input[indexInput]->draw();
		
		bool isEnter = false;
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN) || isEnter) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					for(int i=0; i<nInput; i++){
						if(input[i] != NULL) delete input[i];
					}
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnHuy.isClicked(x,y) && !input[0]->getContent().empty() && !input[1]->getContent().empty() || isEnter){
					isEnter = false;
					int isConfirmed = MessageBox(NULL,
												"HUY CAC LOP TIN CHI KHONG DU DIEU KIEN MO",
												"THONG BAO",
												MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												);
												    		
					switch(isConfirmed){
						case IDCANCEL:{
								break;
						}
										
						case IDOK: default:{	
								thaoTac = HUY_LTC;
								khoa = atoi(input[0]->getContent().c_str());
								HK = atoi(input[1]->getContent().c_str());
								
								for(int i=0; i<nInput; i++){
									if(input[i] != NULL) delete input[i];
								}
								
								return; 	
						}
					}
				}else if(btnHuy.isClicked(x,y) || isEnter) {
					
					isEnter = false;	
						
					 if(input[0]->getContent().empty() && input[1]->getContent().empty())
						notification = "KHONG DUOC BO TRONG DU LIEU !!!";
					else  if(input[0]->getContent().empty())
						notification = "VUI LONG NHAP O NIEN KHOA !!!";
					else if(input[1]->getContent().empty())
						notification = "VUI LONG NHAP O HOC KY !!!";
						
						MessageBox(
							        NULL,
							        notification.c_str(),
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					    		
					
				
				}
				
				for(int i=0; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == TAB){
					oldIndexInput = indexInput;
					if(++indexInput == nInput) indexInput = 0;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
				}else if(ch == ENTER ){
					isEnter = true;
					continue;
				}
				
				if(indexInput != -1){
					input[indexInput]->appendText(ch);
					input[indexInput]->draw();
				}
			}
		}
	}

void DSLopTC::formXuatDS_DK(int &viTriChon, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "xuat danh sach 1 lop tc");
		
		Input input("","Nhap ma lop tc:" ,"N", 5, NUMBER,  650, 210, 650 + 300, 210 + INPUT_HEIGHT);
		input.requestFocus();
		input.draw();
		
		Button btnXuat("Xem","X",650, 300, 650+buttonWidth, 300+40, claqua, cllightblue, clblack);
		btnXuat.draw();
		
		Button btnHuy("Huy", "H", 850, 300, 850+buttonWidth, 300+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y; char ch;
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnXuat.isClicked(x,y) && !input.getContent().empty()){
					viTriChon = atoi(input.getContent().c_str());
					thaoTac = XUAT;
					return;
				}else if(btnXuat.isClicked(x,y) && input.getContent().empty()){
					MessageBox(
						        NULL,
						        "VUI LONG NHAP DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				}
				
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == ENTER){
					if(!input.getContent().empty()){
						viTriChon = atoi(input.getContent().c_str());
						thaoTac = XUAT;
						return;
					}else{
						MessageBox(
						        NULL,
						        "VUI LONG NHAP DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
					} 
				}
				
				input.appendText(ch);
				input.draw();
			}
		}
		
	}

void DSLopTC::formNhap_LTC(LopTC *loptc, TREE DSMH, Action &thaoTac, Button *menuButton[]){
		string title;
		if(thaoTac == THEM) title = "them lop tc";
		else if(thaoTac == SUA) title = "sua lop tc";
		drawFrame(500, 150, 640 + 500, 580, title);
		int nInput = 7; 
		Input *input[nInput] = {NULL};
		MonHoc MH;
		int initPos = 1; // vi tri bat dau cua input neu chua co sinh vien dang ky
		
		if(thaoTac == SUA && loptc->getSoSVDK() != 0) initPos = 5; // vi tri bat dau cua input neu da co sinh vien dang ky
		
		
		int left = 650;
		int top = 200;
		
		input[0] = new Input("","Ma lop ","0", 5, NUMBER, left, top, left + 400, top + INPUT_HEIGHT);
		input[1] = new Input("","Ma mon hoc ","1", MAX_MAMH, NON_SPACE, left, top + INPUT_HEIGHT+ 20, left + 200, top + INPUT_HEIGHT * 2 + 20);
		input[2] = new Input("","Nien khoa ","2", 4, NUMBER, left, top+INPUT_HEIGHT*2 + 20*2, left + 90, top + INPUT_HEIGHT * 3 + 20*2);
		input[3] = new Input("","Hoc ky ","3", 1, NUMBER, left+100+60, top+INPUT_HEIGHT*2 + 20*2, left + 250, top + INPUT_HEIGHT * 3 + 20*2);
		input[4] = new Input("","Nhom ","4", 2, NUMBER, left+310, top+INPUT_HEIGHT*2 + 20*2, left + 400, top + INPUT_HEIGHT * 3 + 20*2);
		input[5] = new Input("", "SL Min ","5",3, NUMBER, left, top+INPUT_HEIGHT*3 + 20*3, left + 150, top +INPUT_HEIGHT * 4 + 20*3);
		input[6] = new Input("", "SL Max ","6",3, NUMBER, left + 250, top+INPUT_HEIGHT*3 + 20*3, left + 400, top +INPUT_HEIGHT * 4 + 20*3);
		
		string nameAction, idAction;
		
		if(thaoTac == THEM){
			nameAction = "Them"; idAction = "T";
		}else if(thaoTac == SUA){
			nameAction = "Sua"; idAction = "S";
		}
		
		int clbkcolor = initPos == 1 ? claqua : clgray;
		
		Button btnChonMH("Chon MH","C",left+250, top + INPUT_HEIGHT+ 20, left+250+80, top + INPUT_HEIGHT * 2 + 20, clbkcolor, cllightblue, clblack);
		btnChonMH.draw();
		
		Button btnSave(nameAction, idAction, left, top+INPUT_HEIGHT*6 +20*5, left+buttonWidth, top+INPUT_HEIGHT*6+20*5+40, claqua, cllightblue, clblack);
		btnSave.draw();
		
		Button btnHuy("Huy", "H", left+buttonWidth*2+100, top+INPUT_HEIGHT*6 +20*5, left+buttonWidth*3+100, top+INPUT_HEIGHT*6+20*5+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y; char ch;
		
		input[0]->setContent(convertIntToString(loptc->getMaLopTC()));
		input[1]->setContent(loptc->getMaMH());
		
		int tempInt;
		
		if(thaoTac == THEM){
			tempInt = loptc->getNienKhoa();
			if(tempInt != 0)
				input[2]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getHocKy();
			if(tempInt != 0)
				input[3]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getNhom();
			if(tempInt != 0)
				input[4]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getSVMin();
			if(tempInt != 0)
				input[5]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getSVMax();
			if(tempInt != 0)
				input[6]->setContent(convertIntToString(tempInt));
			
		}
		
		
		if(thaoTac == SUA){
			input[2]->setContent(convertIntToString(loptc->getNienKhoa()));
			input[3]->setContent(convertIntToString(loptc->getHocKy()));
			input[4]->setContent(convertIntToString(loptc->getNhom()));
			input[5]->setContent(convertIntToString(loptc->getSVMin()));
			input[6]->setContent(convertIntToString(loptc->getSVMax()));
		}
		
		int indexInput=initPos;
		int oldIndexInput=1;
		
		bool isFullInfo = true;
		int checkTrung = 0;
		input[indexInput]->requestFocus();
		for(int i=0; i<nInput; i++){
			if(input[i] != NULL){
				input[i]->draw();
			}
		}
		
		input[indexInput]->draw();
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnChonMH.isClicked(x,y) && initPos == 1){
					thaoTac = CHON;
					clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					MH = DSMH.chonMH_LTC(thaoTac, menuButton);
					
					if(!MH.getMaMH().empty())
						loptc->setMaMH(MH.getMaMH());
					else 
						loptc->setMaMH(input[1]->getContent());
					loptc->setNienKhoa(atoi(input[2]->getContent().c_str()));
					loptc->setHocKy(atoi(input[3]->getContent().c_str()));
					loptc->setNhom(atoi(input[4]->getContent().c_str()));
					loptc->setSVMin(atoi(input[5]->getContent().c_str()));
					loptc->setSVMax(atoi(input[6]->getContent().c_str()));
					
					for(int i=0; i<nInput; i++)	if(input[i] != NULL) delete input[i];
					return;
					
				}else if(btnSave.isClicked(x,y)){
					isFullInfo = true;
					for(int i=initPos; i<nInput; i++){
						if(input[i]->getContent().empty()){
							MessageBox(
						        NULL,
						        "VUI LONG NHAP DU THONG TIN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		isFullInfo = false;
				    		break;
						}
					}
					
					if(isFullInfo){
						
						// check xem so luong max co bi be hon so luong min hay ko
						// 5-min 6-max
						if(atoi(input[5]->getContent().c_str()) > atoi(input[6]->getContent().c_str())){
							isFullInfo = false;
							MessageBox(
						        NULL,
						        "SL MAX PHAI LON HON SL MIN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		continue;
						}
						
						// check ma mon hoc co ton tai trong danh sach hay ko
						MH.setMaMH(input[1]->getContent());
						DSMH.them_MH(DSMH.getRoot(), MH, checkTrung);
						if(checkTrung == -1){
							MessageBox(
						        NULL,
						        "MA MON HOC KHONG TON TAI !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
							
							isFullInfo = false;
							checkTrung = 0;
							
							input[1]->requestFocus();
							input[indexInput]->draw();
							indexInput = 1;
							input[indexInput]->draw();
						}
					}
					
					if(isFullInfo && checkTrung==1){
						loptc->setMaMH(input[1]->getContent());
						loptc->setNienKhoa(atoi(input[2]->getContent().c_str()));
						loptc->setHocKy(atoi(input[3]->getContent().c_str()));
						loptc->setNhom(atoi(input[4]->getContent().c_str()));
						loptc->setSVMin(atoi(input[5]->getContent().c_str()));
						loptc->setSVMax(atoi(input[6]->getContent().c_str()));
						
						for(int i=0; i<nInput; i++)
								if(input[i] != NULL) delete input[i];
						return;
					}
				}
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 640 + 500, 600);
					for(int i=0; i<nInput; i++)
						if(input[i] != NULL) delete input[i];
					return;
				}
				
				// clicked input
				for(int i=initPos; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
				
			}
			
			if(kbhit()){
				ch = getch();
				if(ch == TAB){
					oldIndexInput = indexInput;
					indexInput++;
					if(indexInput == nInput) indexInput = initPos;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
					
				}
				
				if(indexInput != -1){
					input[indexInput]->appendText(ch);
					input[indexInput]->draw();
				}
			}
		}
		
		for(int i=0; i<nInput; i++)
			if(input[i] != NULL) delete input[i];
		
	}
	
void DSLopTC::xuatDiem1SVTheoTrang_LTC(TREE DSMH, string maSV, Action &thaoTac, Button *menuButton[]){
		int tongSoDong = this->n;
		LopTC *loptc[this->n];
		tongSoDong = 0;
		
		// lay ds lop tc ma sv da dang ky
		for(int i=0; i<this->n; i++){
			if(this->checkSVDK_LTC(lopTC[i]->getMaLopTC(),maSV)){
				loptc[tongSoDong++] = this->lopTC[i];
			}
		}
		
		// sinh vien chua dang ky bat ki 1 lop tc nao
		if(tongSoDong == 0){
			MessageBox(
				NULL,
				"SINH VIEN CHUA DANG KY LOP TC NAO !!!",
				"THONG BAO",
				MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
			);
			return;
		}
		
		int soLuongMH = 0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0;
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);
		
		Button *editButton[tongSoDong] = {NULL};
		Button *deleteButton[tongSoDong] = {NULL};
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Table newTable = table_LTC();
		//newTable.getCols(newTable.getNumOfCols() - 1)->setName("Diem");
		newTable.getCols(7)->setName("STCLT");
		newTable.getCols(7)->setWidth(newTable.getCols(7)->getWidth() + newTable.getCols(8)->getWidth());
		
		newTable.getCols(8)->setName("STCTH");
		newTable.getCols(8)->setWidth(newTable.getCols(8)->getWidth() + newTable.getCols(9)->getWidth());
		
		newTable.getCols(9)->setName("Diem");
		newTable.getCols(9)->setWidth(newTable.getCols(newTable.getNumOfCols() - 1)->getWidth());
		
		newTable.setCols(10); // set num of cols
		
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		btnNext.requestFocus();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		int xBtn = tableLeft; int yBtn = tableTop+rowTableHeight;
		for(int i=0; i<newTable.getNumOfCols() -1 ; i++) xBtn += newTable.getCols(i)->getWidth();
		
		int lastX = newTable.getCols(newTable.getNumOfCols() - 1)->getWidth();
		
		for(int i=0; i<tongSoDong; i++){
			if(editButton[i] == NULL){
				editButton[i] = new Button (
										convertFloatToString(loptc[i]->getDSDK().timDiem_DK(maSV)),
										convertIntToString(i),
										xBtn,
										yBtn,
										xBtn + lastX,
										yBtn + rowTableHeight,
										cllightwhite,
										clblack,
										clblack
									);
				yBtn += rowTableHeight;
			}
		}
		
		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		int x,y;
		bool exitLoop = false;
		while(!exitLoop){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				indexMenu = isClickMenuButton(menuButton, x,y);
				if(indexMenu != -1){
					if(indexMenu == nMenuButton - 1){
            			exitProgram = isExit();
            			if(exitProgram)
            				exitLoop = true;
            			else indexMenu = -1;
            			continue;	
					}            			
					else {
						exitLoop = true; continue;
					}
					
				}
				
				if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}else if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
            		
            		ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
            		
            		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
					
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
					
					ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
					
					xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
			}
		}
		
		delete[] arrMH;
		freeArrButton(editButton, tongSoDong);
		freeArrButton(deleteButton, tongSoDong);
		newTable.freeTable();
		return;
	}
	
string DSLopTC::formXemDiemSV_LTC(DSLopSV DSLSV, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+270, "Xem diem cac lop tc cua 1 sv");
		
		int left = 650;
		int top = 220;
		
		Input *input = new Input("", "Ma sinh vien ", "0", MAX_MASV, STUDENT_ID, left, top, left+300, top+INPUT_HEIGHT);
		input->requestFocus();
		input->draw();
		
		Button btnTT("Xem Diem","TT",left, top+100, left+buttonWidth+20, top+INPUT_HEIGHT+110, claqua, cllightblue, clblack);
		btnTT.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+100, 850+buttonWidth+20, top+INPUT_HEIGHT+110, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		bool exitLoop = false;
		int x,y;
		char ch;
		string maSV = "";
		bool isFullInfo = true;
		int coSV = -1;
		
		while(!exitLoop){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnTT.isClicked(x,y)){
					isFullInfo = true;
					if(!input->getContent().empty()){
						coSV = DSLSV.timSV_LSV(input->getContent());
						if(coSV == -1) {
							MessageBox(
									NULL,
									"KHONG TIM THAY SINH VIEN !!!",
									"THONG BAO",
									MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
						
						}else {
							maSV = input->getContent();
							exitLoop = true;
							continue;
						}
					}else {
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
						continue;
					}
				} else if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT;
					maSV = ""; exitLoop = true;
					continue;
				}
			}
			
			if(kbhit()){
				ch = getch();
				if(ch == ENTER){
					isFullInfo = true;
					if(!input->getContent().empty()){
						coSV = DSLSV.timSV_LSV(input->getContent());
						if(coSV == -1) {
							MessageBox(
									NULL,
									"KHONG TIM THAY SINH VIEN !!!",
									"THONG BAO",
									MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
						
						}else {
							maSV = input->getContent();
							exitLoop = true;
							continue;
						}
					}else {
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
						continue;
					}
				}else {
					input->appendText(ch);
					input->draw();
				}
			}
		}
		
		delete input;
		
		return maSV;
	}

int DSLopTC::locCacLopDK_LTC(MonHoc *arrMH, int soLuongMH, string maSV){
		for(int i=0; i<soLuongMH; i++) arrMH[i].setTenMH("-1");
	
		for(int i=0; i<this->n; i++){
			if(this->checkSVDK_LTC(lopTC[i]->getMaLopTC(), maSV)){ // check sinh vien co dang ky vo lop tc nay ko
				for(int j=0; j<soLuongMH; j++){ // check xem sinh vien co hoc lai ko -> co, luu lai de lay diem nam hoc moi nhat
					if(arrMH[j].getMaMH() == lopTC[i]->getMaMH()){
						if(atoi(arrMH[j].getTenMH().c_str()) < lopTC[i]->getNienKhoa()){
							arrMH[j].setTenMH(convertIntToString(i)); // loi dung ten mh de luu lai vi tri ltc 
						}
					}
				}
			}
		}
	}
	
void DSLopTC::thongKeDiemTB_LSV(DSSV &dssv, TREE &DSMH, float *diemTB, int tongSoDong){
		
		float tongDiem = 0;
		int tongSoTC = 0; // tong so tin chi
		int tongTC = 0; // tong cua tc ly thuyet va tc thuc hanh 1 mon hoc -> tranh get nhieu lan trong Class
		
		int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0; 
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH); 
		
		int vtsv = -1;
		
		for(int i=0; i<soLuongMH; i++) arrMH[i].setTenMH("-1");
		
		// tinh diem trung binh tung sinh vien
		for(NodeSV *SV = dssv.getHead_DSSV(); SV != NULL; SV=SV->getNext_SV()){
			tongDiem = 0; tongSoTC = 0; vtsv++;
			
			this->locCacLopDK_LTC(arrMH, soLuongMH, SV->getData_SV().getMaSV());
			for(int i=0; i<soLuongMH; i++){
				if(arrMH[i].getTenMH() != "-1"){
					tongTC = arrMH[i].getSTCLT() + arrMH[i].getSTCTH();
					tongSoTC += tongTC;
					tongDiem += (lopTC[atoi(arrMH[i].getTenMH().c_str())]->getDSDK().timDiem_DK(SV->getData_SV().getMaSV()) * tongTC);
				}
			}
			
			if(tongSoTC != 0 && vtsv < tongSoDong) {
				diemTB[vtsv] = tongDiem / (1.0*tongSoTC);
				diemTB[vtsv] = round(diemTB[vtsv] * 10) / 10;     //  lam tron diem, lay 1 chu so sau day phay
			}
			
		}
		
		delete[] arrMH;
		
	}
	
void DSLopTC::xuatDiemTB1Trang_LSV(NodeSV *&head, float *diemTB, int batDau, int ketThuc, Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; // Xem can xuat bao nhieu dong
		if(soDong == 0) soDong = MAX_DONG_1_TRANG; // neu so du == 0 thi xuat ra MAX_DONG_1_TRANG dong
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack);
		
		NodeSV *p = head;
		for(int vt = 0;  p !=NULL && vt < batDau; vt++, p = p->getNext_SV()) ; // chay den STT can xuat
		
		for(int i = batDau; i < soDong; i++){ 
			setbkcolor(cllightwhite); setcolor(clblack); 
			yBtn += rowTableHeight;
			// in ra chuoi rong cac dong con thua
			if(i >= ketThuc){
				y +=  rowTableHeight;
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); 	x += newTable.getCols(0)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth()- 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(3)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(4)->getWidth();
				
				x =  tableLeft;
				continue;
			}
			
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(1)->getWidth()/2  - textwidth(p->getData_SV().getMaSV().c_str())/2, 
						y, 
						p->getData_SV().getMaSV().c_str()
					);
					
				x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + 10, 
						y, 
						p->getData_SV().getHo().c_str()
					);
					
				x += newTable.getCols(2)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(3)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + 10, 
						y, 
						p->getData_SV().getTen().c_str()
					);
					
				x += newTable.getCols(3)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(4)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2 - textwidth(convertFloatToString(diemTB[i]).c_str())/2, 
						y, 
						convertFloatToString(diemTB[i]).c_str()
				);
				
			x = tableLeft;
			if(p!=NULL ) p = p->getNext_SV();
		}
	}
	
void DSLopTC::xuatDiemTBTheoTrang_LSV(TREE &DSMH, DSSV &dssv, Action thaoTac, Button *menuButton[]){
		int tongSoDong = dssv.demSoLuongSV();
		if(tongSoDong <= 0){
			MessageBox(
					NULL,
					"LOP HOC KHONG CO SINH VIEN NAO !!!",
					"THONG BAO",
					MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				);
			return;
		}
		
		float *diemTB = new float[tongSoDong];
		for(int i=0; i<tongSoDong; i++) diemTB[i]=0.0;
		
		thongKeDiemTB_LSV(dssv, DSMH, diemTB, tongSoDong);
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Table newTable = table_DiemTB();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		xuatDiemTB1Trang_LSV(dssv.getHead_DSSV(), diemTB, batDau, ketThuc, newTable);
		inTrang(trangHienTai, tongSoTrang);
		
		int x,y;
		bool exitLoop = false;
		
		while(!exitLoop){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	indexMenu = isClickMenuButton(menuButton, x,y);
				if(indexMenu != -1){
					if(indexMenu == nMenuButton - 1){
            			exitProgram = isExit();
            			if(exitProgram)
            				exitLoop = true;
            			else indexMenu = -1;
            			continue;	
					}            			
					else {
						exitLoop = true; continue;
					}
					
				}
				
				if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}else if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
            		
            		ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
            		
            		xuatDiemTB1Trang_LSV(dssv.getHead_DSSV(), diemTB, batDau, ketThuc, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
					
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
					
					ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
					
					xuatDiemTB1Trang_LSV(dssv.getHead_DSSV(), diemTB, batDau, ketThuc, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				
			}
		}
		
		
		delete[] diemTB;
		newTable.freeTable();
	}

void DSLopTC::thongKeDiemTK_LSV(DSSV &dssv, MonHoc *arrMH, int soLuongMH, float **diemTK, int tongSoDong){
		int vtsv = -1;
		for(NodeSV *SV = dssv.getHead_DSSV(); SV!=NULL; SV=SV->getNext_SV()){
			vtsv++;
			
			// loc cac ltc ma sinh vien da dang ky
			this->locCacLopDK_LTC(arrMH, soLuongMH, SV->getData_SV().getMaSV());
			
			// lay diem cac mon hoc ma sinh vien da dang ky hoc
			for(int i=0; i<soLuongMH; i++){
				if(arrMH[i].getTenMH() != "-1"){
					diemTK[vtsv][i] = lopTC[atoi(arrMH[i].getTenMH().c_str())]->getDSDK().timDiem_DK(SV->getData_SV().getMaSV());
					//cout<<"\n"<<diemTK[vtsv][i]<<" "<<arrMH[i].getMaMH()<<" "<<SV->getData_SV().getMaSV()<<" "<<i;
				} 
			}
		}
	}
	
void DSLopTC::xuatMonHocTK1Trang_LSV(MonHoc *arrMH, int soLuongMH, float **diemTK, int batDau, int ketThuc, int batDauMH, int ketThucMH, Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; // Xem can xuat bao nhieu dong
		if(soDong == 0) soDong = MAX_DONG_1_TRANG; // neu so du == 0 thi xuat ra MAX_DONG_1_TRANG dong
		
		int soCot = ketThucMH % MAX_COT_1_TRANG;
		if(soCot == 0) soCot = MAX_COT_1_TRANG;
		
		int xTemp = tableLeft ;
		for(int i=0; i<3; i++) xTemp += newTable.getCols(i)->getWidth();
		
		int x = xTemp;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2 ;
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else // de in khoang trang xoa toan bo du lieu cu sau khi filter content tu input ko tim thay
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
			
		if(ketThucMH == 0 && batDauMH == 0) soCot = MAX_COT_1_TRANG;
		else
			soCot = ketThucMH % MAX_COT_1_TRANG == 0 ? ketThucMH : ketThucMH + MAX_COT_1_TRANG - ketThucMH % MAX_COT_1_TRANG;
		
		int jCot = batDauMH; //cout<<"\nfdfd "<<batDauMH<<" "<<ketThucMH<<" "<<soCot; 
		int realPos;
		
		setbkcolor(cllightwhite);
		// ===================== XUAT TEN MON HOC =========================
		
		for(int j=batDauMH; j<soCot; j++){
			realPos = j % MAX_COT_1_TRANG + 3;
			if(j >= ketThucMH){
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(realPos)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(realPos)->getWidth();
			
				continue;
			}
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(realPos)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(realPos)->getWidth()/2  - textwidth(arrMH[j].getMaMH().c_str())/2, 
						y, 
						arrMH[j].getMaMH().c_str()
					);
					
				x += newTable.getCols(realPos)->getWidth();
			
		}
		x = xTemp;
		
		// ===================== XUAT DIEM TK =========================
		for(int i = batDau; i < soDong; i++){ 
			
			// khong can xoa cac chuoi thua vi ben sinh vien da xoa roi
			if( i>= ketThuc) break;
			
			y += rowTableHeight;
			for(int j=batDauMH; j<soCot; j++){
				realPos = j % MAX_COT_1_TRANG + 3;
				
				if( j>= ketThucMH){
					outtextxy(
						x + textwidth(string("|").c_str()), 
						y, 
						string(	(newTable.getCols(realPos)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
					); x += newTable.getCols(realPos)->getWidth();
					continue;
				}
				
				// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(realPos)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
				// xuat du lieu moi
				if(diemTK[i][j] != -1)
					outtextxy(
							x + newTable.getCols(realPos)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][j]).c_str())/2, 
							y, 
							convertFloatToString(diemTK[i][j]).c_str()
						);
				x += newTable.getCols(realPos)->getWidth();
			}
			
			x = xTemp;
		
		}
	}
	
void DSLopTC::xuatSinhVienTK1Trang_LSV(NodeSV *&head, float **diemTK, int batDau, int ketThuc, int batDauMH, int ketThucMH, Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; // Xem can xuat bao nhieu dong
		if(soDong == 0) soDong = MAX_DONG_1_TRANG; // neu so du == 0 thi xuat ra MAX_DONG_1_TRANG dong
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2 ;
		
		string strSTT; int cotMH = batDauMH - 1; string diem = "";
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else // de in khoang trang xoa toan bo du lieu cu sau khi filter content tu input ko tim thay
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack);
		
		NodeSV *p = head;
		for(int vt = 0;  p !=NULL && vt < batDau; vt++, p = p->getNext_SV()) ; // chay den STT can xuat
		
		for(int i = batDau; i < soDong; i++){ 
			setbkcolor(cllightwhite); setcolor(clblack); 
			
			// in ra chuoi rong cac dong con thua
			if(i >= ketThuc){
				y +=  rowTableHeight; //setbkcolor(clyellow);
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); 	x += newTable.getCols(0)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth()- 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				for(int sttCot=3; sttCot<9; sttCot++){
					outtextxy(
						x + textwidth(string("|").c_str()), 
						y, 
						string((newTable.getCols(sttCot)->getWidth()- 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
					); x += newTable.getCols(sttCot)->getWidth();
				}
				
				
				x =  tableLeft;
				continue;
			}
			
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(1)->getWidth()/2  - textwidth(p->getData_SV().getMaSV().c_str())/2, 
						y, 
						p->getData_SV().getMaSV().c_str()
					);
					
				x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + 10, 
						y, 
						(p->getData_SV().getHo() + " " + p->getData_SV().getTen()).c_str()
					);
					
				x += newTable.getCols(2)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(3)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(3)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(3)->getWidth();
				
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(4)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(4)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(5)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(5)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(5)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(6)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(6)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(6)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(7)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(7)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(7)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(8)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			if((++cotMH) < ketThucMH)
				if(diemTK[i][cotMH] != -1)
				outtextxy(
						x + newTable.getCols(8)->getWidth()/2 - textwidth(convertFloatToString(diemTK[i][cotMH]).c_str())/2, 
						y, 
						convertFloatToString(diemTK[i][cotMH]).c_str()
					);
					
				x += newTable.getCols(8)->getWidth();
				
			x = tableLeft; cotMH = batDauMH - 1;
			if(p!=NULL ) p = p->getNext_SV();
		}
	}
	
	
void  DSLopTC::xuatDiemTKTheoTrang_LSV(TREE &DSMH, DSSV &dssv, Action thaoTac, Button *menuButton[]){
		int tongSoDong = dssv.demSoLuongSV();
		if(tongSoDong <= 0){
			MessageBox(
					NULL,
					"LOP HOC KHONG CO SINH VIEN NAO !!!",
					"THONG BAO",
					MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				);
			return;
		}
		
		int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0; 
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH); 
		
		float *diemTK[tongSoDong];
		
		for(int i=0; i<tongSoDong; i++){
			diemTK[i] = new float[soLuongMH];
			for(int j=0; j<soLuongMH; j++) diemTK[i][j] = -1;
		}
		
		thongKeDiemTK_LSV(dssv, arrMH, soLuongMH, diemTK, tongSoDong);
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		soDu = (soLuongMH % MAX_COT_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrangMH = soLuongMH / MAX_COT_1_TRANG + soDu;
		int trangHienTaiMH = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		int batDauMH = 0;
		int ketThucMH = (soLuongMH > MAX_COT_1_TRANG) ? MAX_COT_1_TRANG : soLuongMH;
		
		Table newTable = table_DiemTK();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// button thay doi mon hoc
		Button btnPrevMH("<","btnPrevMH", 940, 90, 940 + buttonWidth, 90 + 30);
		btnPrevMH.draw();
		
		//setbkcolor(cllightwhite);
		outtextxy(1050, 95, "Xem cac mon hoc khac");
		
		Button btnNextMH(">","btnNextMH",1240, 90, 1240 + buttonWidth, 90 + 30);
		btnNextMH.draw();
		
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		xuatSinhVienTK1Trang_LSV(dssv.getHead_DSSV(), diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
		xuatMonHocTK1Trang_LSV(arrMH, soLuongMH, diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
		inTrang(trangHienTai, tongSoTrang);
		
		int x,y;
		bool exitLoop = false;
		
		while(!exitLoop){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	indexMenu = isClickMenuButton(menuButton, x,y);
				if(indexMenu != -1){
					if(indexMenu == nMenuButton - 1){
            			exitProgram = isExit();
            			if(exitProgram)
            				exitLoop = true;
            			else indexMenu = -1;
            			continue;	
					}            			
					else {
						exitLoop = true; continue;
					}
					
				}
				
				if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}else if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
            		
            		ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
            		
            		xuatSinhVienTK1Trang_LSV(dssv.getHead_DSSV(), diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
					
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
					
					ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
					
					xuatSinhVienTK1Trang_LSV(dssv.getHead_DSSV(), diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}else if(btnPrevMH.isClicked(x,y) && (trangHienTaiMH > 1)){
					trangHienTaiMH = --trangHienTaiMH == 0 ? 1 : trangHienTaiMH;
            		batDauMH = (trangHienTaiMH - 1) * MAX_COT_1_TRANG;
            		ketThucMH = (soLuongMH > MAX_COT_1_TRANG) ? batDauMH + MAX_COT_1_TRANG : soLuongMH;
            		
            		ketThucMH = (ketThucMH > soLuongMH) ? batDauMH + soLuongMH % batDauMH : ketThucMH;
            		
            		xuatMonHocTK1Trang_LSV(arrMH, soLuongMH, diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
            		
				}else if(btnNextMH.isClicked(x,y) && (trangHienTai < tongSoTrangMH)){
					trangHienTaiMH = ++trangHienTaiMH > tongSoTrangMH ? tongSoTrangMH : trangHienTaiMH;
					batDauMH = (trangHienTaiMH - 1) * MAX_COT_1_TRANG;
					ketThucMH = (soLuongMH > MAX_COT_1_TRANG) ? batDauMH + MAX_COT_1_TRANG : soLuongMH;
					
					ketThucMH = (ketThucMH > soLuongMH) ? batDauMH + soLuongMH % batDauMH : ketThucMH;
					
					xuatMonHocTK1Trang_LSV(arrMH, soLuongMH, diemTK, batDau, ketThuc, batDauMH, ketThucMH, newTable);
					
				}
            	
            }
		}
		
		for(int i=0; i<tongSoDong; i++){
			delete [] diemTK[i];
		}
		delete[] arrMH;
		newTable.freeTable();
	}

void DSLopTC::menu_LTC(TREE &DSMH, DSLopSV DSLSV, Action thaoTac, Button *menuButton[]){
		MonHoc MH;	LopTC *loptc = NULL; bool chuaThem = true; // de cap phat vung nho moi cho ltc, vi ltc cu sau khi them van giu nguyen data
		int viTriChon = -1; bool daChon = false; // da chon lop sinh vien hay chua
		int khoa = 0, HK = 0;
		string subTitle;
		// DKI LTC
		string maSV = ""; int coSV = -1; int coLTC = -1;
		string strN;
		while(!isNull_LTC() && indexMenu == -1){ 
			strN = convertIntToString(n);
			
			subTitle = "DANH SACH LOP TIN CHI";
			if(thaoTac == DK_LTC)
				subTitle = "DANG KY LOP TIN CHI";
			else if(thaoTac == DIEM_SV && !maSV.empty())
				subTitle = "DANH SACH LOP TIN CHI DA DANG KY";
			else if(thaoTac == DIEM_TB && daChon && viTriChon != -1)
				subTitle = "DIEM TRUNG BINH KHOA HOC CUA DS SINH VIEN 1 LOP";
			else if(thaoTac == DIEM_TK && daChon && viTriChon != -1)
				subTitle = "DIEM TONG KET MON HOC CUA SINH VIEN 1 LOP";
			
			Label title(
					subTitle,
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
			if(thaoTac != DK_LTC){
				title.printLabel(
						"  Tong so lop  ",
						strN
					);
			}else if(thaoTac == DK_LTC && coSV != -1 && coLTC != -1){
				title.printLabel(
						"Ma sinh vien",
						maSV
					);
			}
			
			if(thaoTac == DIEM_SV && !maSV.empty()){
				title.printLabel(
						"Ma sinh vien",
						maSV
					);
			}else if((thaoTac == DIEM_TB || thaoTac == DIEM_TK) && daChon && viTriChon != -1){
				title.printLabel(
					"   Lop",
					DSLSV.getLopSV_LSV(viTriChon)->getMaLop() + "    ",
					"So sinh vien hien tai",
					convertIntToString(DSLSV.getLopSV_LSV(viTriChon)->getDS_SV().demSoLuongSV())
				);
			}		
			
			
			switch(thaoTac){
				case THEM:{
					
					if(n == MAX_LOPTC) {
						MessageBox(
						        NULL,
						        "DS LOP TC DA TOI DA, KHONG THE THEM !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		); thaoTac = XUAT; continue;
					}
					
					if(loptc == NULL || chuaThem){
						loptc = new LopTC;
						chuaThem = false;
						loptc->taoMaLop_LTC(this->getMaLopTCMax());
					}
					
					
					thaoTac = THEM;
					formNhap_LTC(loptc, DSMH,thaoTac, menuButton);
					if(thaoTac == HUY){
						delete loptc;
						thaoTac = XUAT;
						chuaThem = true;
					}else if(thaoTac == THEM){
						if(this->checkTrungDS_LTC(loptc, -1, loptc->getMaMH())){
							MessageBox(
						        NULL,
						        "THONG TIN NHAP BI TRUNG VOI THONG TIN DA CO !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
						}else{
							this->them_LTC(loptc);
							MessageBox(
						        NULL,
						        "THEM LOP TIN CHI THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		clearRegion(500, 150, 640 + 500, 600);
							thaoTac = XUAT;
							chuaThem = true;
							
							MH.setMaMH(lopTC[n-1]->getMaMH());
							
							MH.setTT(true);
							int checkTrung = 3;
							DSMH.them_MH(DSMH.getRoot(), MH, checkTrung);
							
							MH.setMaMH(""); MH.setSTCLT(0); MH.setSTCTH(0); MH.setTenMH("");
							this->writeDataDS_LTC();
							DSMH.writeDataDS_MH();
							
						}
					}else if(thaoTac == CHON){
						thaoTac = THEM;
						xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
					
					}
					break;
				}
				case SUA:{
					if(viTriChon < n){
							if(!lopTC[viTriChon]->getTrangThai()){
								if(loptc == NULL || chuaThem) {
								loptc = new LopTC; chuaThem = false;
								
								loptc->setMaLopTC(lopTC[viTriChon]->getMaLopTC());
								loptc->setMaMH(lopTC[viTriChon]->getMaMH());
								loptc->setNienKhoa(lopTC[viTriChon]->getNienKhoa());
								loptc->setHocKy(lopTC[viTriChon]->getHocKy());
								loptc->setNhom(lopTC[viTriChon]->getNhom());
								loptc->setSVMin(lopTC[viTriChon]->getSVMin());
								loptc->setSVMax(lopTC[viTriChon]->getSVMax());
								loptc->setSoSVDK(lopTC[viTriChon]->getSoSVDK());
								}
								
								formNhap_LTC(loptc, DSMH, thaoTac, menuButton);
								if(thaoTac == HUY){
									delete loptc;
									thaoTac = XUAT; loptc = NULL; chuaThem = true;
								}else if(thaoTac == SUA){
									if(this->checkTrungDS_LTC(loptc, viTriChon, loptc->getMaMH())){
										MessageBox(
									        NULL,
									        "THONG TIN NHAP BI TRUNG VOI THONG TIN DA CO !!!",
									        "THONG BAO",
									        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
									}else if(loptc->getSVMax() < lopTC[viTriChon]->getSoSVDK()){
//									
										string svdadk = "SO SV MAX KHONG DUOC NHO HON SO SV DA DK( " + convertIntToString(lopTC[viTriChon]->getSoSVDK()) + " )";
										MessageBox(
									        NULL,
									        svdadk.c_str(),
									        "THONG BAO",
									        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
									}else{
										
										// neu lop tc chua co sinh vien dang ky
										if(lopTC[viTriChon]->getDSDK().isNull_DK()){
											lopTC[viTriChon]->setMaMH(loptc->getMaMH());
											lopTC[viTriChon]->setNienKhoa(loptc->getNienKhoa());
											lopTC[viTriChon]->setHocKy(loptc->getHocKy());
											lopTC[viTriChon]->setNhom(loptc->getNhom());
										}
										
										lopTC[viTriChon]->setSVMin(loptc->getSVMin());
										lopTC[viTriChon]->setSVMax(loptc->getSVMax());
										
										MessageBox(
									        NULL,
									        "SUA LOP TIN CHI THANH CONG !!!",
									        "THONG BAO",
									        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
										clearRegion(500, 150, 640 + 500, 600);
										delete loptc;
										thaoTac = XUAT;
										chuaThem = true;
										viTriChon = 0;
										this->writeDataDS_LTC();
									}
									
								}else if(thaoTac == CHON){
									thaoTac = SUA;
									xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
								}
							}else { // lop tc da huy, ko duoc sua
								MessageBox(
									        NULL,
									        "LOP TIN CHI BI HUY KHONG THE SUA !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    	clearRegion(500, 150, 640 + 500, 600);
							    	thaoTac = XUAT;
							}
					}
					break;
				}
				case XOA:{
					if(viTriChon < n){ MH.setMaMH(lopTC[viTriChon]->getMaMH());
						this->xoa_LTC(lopTC[viTriChon]->getMaLopTC());
						if(n == 0)
							clearRegion(tableLeft, INPUT_Y - 30, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							
							// set lai trang thai daMoLop cua mon hoc theo lop tc vua xoa
							int checkTrung = 0;
							
							bool coLop = checkLopTC(MH.getMaMH());
							
							if(coLop==false){
								MH.setTT(false);
								checkTrung = 3;
								DSMH.them_MH(DSMH.getRoot(), MH, checkTrung);
							}
							
							this->writeDataDS_LTC();
							DSMH.writeDataDS_MH();
							MH.setMaMH(""); MH.setSTCLT(0); MH.setSTCTH(0); MH.setTenMH("");
					}
					break;
				}
				case XUAT:{
					xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
					break;
				}
				
				case DIEM:{
					xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
					if(thaoTac == DIEM) {
						if(viTriChon < n && indexMenu == -1){
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
							MonHoc MH; int temp = 0;
							MH.setMaMH(lopTC[viTriChon]->getMaMH());
							DSMH.them_MH(DSMH.getRoot(), MH, temp );
							lopTC[viTriChon]->getDSDK().menu_DK(
															DSLSV,
															lopTC[viTriChon]->getMaLopTC(),
															lopTC[viTriChon]->getNienKhoa(),
															lopTC[viTriChon]->getHocKy(),
															lopTC[viTriChon]->getNhom(),
															lopTC[viTriChon]->getTrangThai(),
															MH.getTenMH(),
															thaoTac,
															menuButton
														);
							if(thaoTac == THOAT) thaoTac = DIEM;
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
							lopTC[viTriChon]->setSoSVDK(lopTC[viTriChon]->getDSDK().demSoLuongSV());
							this->writeDataDS_DK();							
						}
					}
					
					break;
				}
				
				case DIEM_SV:{
					
					if(!maSV.empty()){
							xuatDiem1SVTheoTrang_LTC(DSMH, maSV, thaoTac, menuButton);
							thaoTac = DIEM; maSV = "";
						}
					else {
						maSV = formXemDiemSV_LTC(DSLSV, thaoTac);
					}
					
			    	if(thaoTac == THOAT){
			    		clearRegion(500, 150, 540 + 500, 200+270);
			    		thaoTac = DIEM; maSV = "";
					}else {
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12); continue;
					}
					
					break;
				}
				
				case DIEM_TB:{
					if(!daChon){ viTriChon = -1;
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						DSLSV.menu_LSV(viTriChon, thaoTac, menuButton);
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						if(viTriChon != -1){
							daChon = true;
							if(DSLSV.getLopSV_LSV(viTriChon)->getDS_SV().isNULL_SV()){
								daChon = false; // lop khong co sinh vien thi cho chon lai
							}
						}
						else {
							thaoTac = DIEM; daChon = false;
						}
						continue; // cap nhat title neu viTriChon != -1
					}
					
					if(thaoTac == DIEM_TB && daChon && viTriChon != -1){
						xuatDiemTBTheoTrang_LSV(DSMH, DSLSV.getLopSV_LSV(viTriChon)->getDS_SV(), thaoTac, menuButton);
						//clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					}
					
					viTriChon = -1; daChon = false; //thaoTac = DIEM;
					break;
				}
				
				case DIEM_TK: {
					if(!daChon){ viTriChon = -1;
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						DSLSV.menu_LSV(viTriChon, thaoTac, menuButton);
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						if(viTriChon != -1){
							daChon = true;
							if(DSLSV.getLopSV_LSV(viTriChon)->getDS_SV().isNULL_SV()){
								daChon = false; // lop khong co sinh vien thi cho chon lai
							}
						}
						else {
							thaoTac = DIEM; daChon = false;
						}
						continue; // cap nhat title neu viTriChon != -1
					}
					
					if(thaoTac == DIEM_TK && daChon && viTriChon != -1){
						xuatDiemTKTheoTrang_LSV(DSMH, DSLSV.getLopSV_LSV(viTriChon)->getDS_SV(), thaoTac, menuButton);
					}
					
					viTriChon = -1; daChon = false; //thaoTac = DIEM;
					break;
				}
				
				case XUAT_DS:{
					formXuatDS_DK(viTriChon, thaoTac);
					if(thaoTac == HUY){
						thaoTac = XUAT;
						
					}else {
						
						viTriChon = this->tim_LTC(viTriChon);
						if(viTriChon==-1){ // khong tim thay lop tin chi
							MessageBox(
						        NULL,
						        "KHONG TIM THAY LOP TIN CHI !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
				    		thaoTac = XUAT_DS;
						}else{ // Co lop tin chi
							MonHoc MH; int temp = 0;
							MH.setMaMH(lopTC[viTriChon]->getMaMH());
							DSMH.them_MH(DSMH.getRoot(), MH, temp );
							thaoTac = XUAT_DS;
							if(!lopTC[viTriChon]->getDSDK().isNull_DK()) 
								clearRegion(tableLeft, frameTop+12, frameRight - 12, frameBottom - 12);
								
							lopTC[viTriChon]->getDSDK().menu_DK(
															DSLSV,
															lopTC[viTriChon]->getMaLopTC(),
															lopTC[viTriChon]->getNienKhoa(),
															lopTC[viTriChon]->getHocKy(),
															lopTC[viTriChon]->getNhom(),
															lopTC[viTriChon]->getTrangThai(),
															MH.getTenMH(),
															thaoTac,
															menuButton
														);
							
							clearRegion(tableLeft, frameTop+12, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							lopTC[viTriChon]->setSoSVDK(lopTC[viTriChon]->getDSDK().demSoLuongSV());
							this->writeDataDS_DK();
						}
					}
					break;
				}
				
				case HUY_LTC:{
					
					formHuy_LTC(khoa, HK, thaoTac);
					if(thaoTac == THOAT){
						
					}else {
						this->huyLopTCTheoKhoaVaHK_LTC(khoa, HK);
						MessageBox(
							NULL,
							"HUY THANH CONG!!!",
							"THONG BAO",
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);	
						clearRegion(500, 150, 550 + 500, 200+300);	
					}
					khoa = 0; HK = 0;				
					thaoTac=XUAT;
					this->writeDataDS_LTC();
					break;
				}
				
				case DK_LTC:{
					
						if(thaoTac == DK_LTC && coSV == -1 && coLTC == -1){
							formDK_LTC(maSV, khoa, HK, thaoTac);
							if(thaoTac == THOAT){	
								thaoTac = XUAT;
							}else {
								coSV = DSLSV.timSV_LSV(maSV);
								if(coSV == -1){
									MessageBox(
									        NULL,
									        "KHONG TIM THAY SINH VIEN !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    	coLTC = -1; continue;
								}else {
									
									coLTC = this->checkLopTheoKhoaVaHK_LTC(khoa, HK);
									if(coLTC == -1){
										MessageBox(
									        NULL,
									        "KHONG TIM THAY LOP TIN CHI !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    		
							    		coSV = -1;  continue;
									}else{
										clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
										
									}
								}
							}
						}else{
							dangKyTheoLop_LTC(DSMH, maSV, khoa, HK, thaoTac);
							if(thaoTac == THOAT){
								clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
								
							}else{
								MessageBox(
									        NULL,
									        "DA LUU THANH CONG !!!",
									        "THONG BAO",
									        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    );
							}
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							coSV = -1; coLTC = -1; maSV = "";
							khoa = 0; HK = 0;
							this->writeDataDS_DK();
						}
					
					clearRegion(500, 150, 550 + 500, 200+300);
					
					break;
				}
				
				
				case THOAT_CT:{
					indexMenu =-1;
					return;
					break;
				}
				
			} // switch case
		
		} 
		if(isNull_LTC()){
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP TIN CHI NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}


