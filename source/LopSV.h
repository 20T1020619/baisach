#pragma once
#include "Const.h"

class LopSV{
private:
	string maLop;
	DSSV dssv;
public:
	
	LopSV();
	
	void setMaLop(string maLop);
	
	string getMaLop();
	
	DSSV &getDS_SV();

	void setDS_SV(DSSV ds);
	
};

class DSLopSV{
private:
	LopSV *lopSV[MAX_LOPSV]  = {NULL};
	int n;
public:
	
	DSLopSV();
	
	void freeDS_LSV();
	
	void setN(int n);
	
	int getN();
	
	LopSV *&getLopSV_LSV(int viTri);
	
	void loadData_LSV();
	
	void loadDataDS_SV();
	
	void writeData_LSV(LopSV *LSV,ofstream &fileOut);
	
	void writeDataDS_LSV();
	
	void writeDataDS_SV();
	
	bool isNull_LSV();
	
	bool isFull_LSV();
	
	int them_LSV(string &maLopSV);
	
	int tim_LSV(string maLop);
	
	int timSV_LSV(string maSV);
	
	NodeSV * layInfo_SV(string maSV);
	
	void xuatDS1Trang_LSV(LopSV *lopSV[], int batDau, int ketThuc, Button *printButton[], Table newTable, Action thaoTac);
	
	void locDS_LSV(string content, LopSV *lop[], int &nFilter, int &tongSoTrang);
	
	void xuatDSTheoTrang_LSV(int &viTriChon, Action &thaoTac, Button *menuButton[]);
	
	void formThem_LSV(string &maLopSV, Action &thaoTac);

	void menu_LSV(int &viTriChon, Action &thaoTac, Button *menuButton[]);
	
};


/*
** ================ Lop sinh vien ================
*/

LopSV::LopSV(){
	maLop = "";
	dssv.setHead_DSSV(NULL);
}

DSSV &LopSV::getDS_SV(){
		return this->dssv;	
}

void LopSV::setMaLop(string maLop){
	this->maLop = maLop;
}
	
string LopSV::getMaLop(){
	return this->maLop;
}

void LopSV::setDS_SV(DSSV ds){
		this->dssv.setHead_DSSV(ds.getHead_DSSV());
	}

/*
** ================ Danh sach lop sinh vien ================
*/

DSLopSV::DSLopSV(){
	n = 0;
	for(int i=0; i<MAX_LOPSV; i++) lopSV[i] = NULL;
}

void DSLopSV::freeDS_LSV(){
		for(int i=0; i<n; i++){
			if(lopSV[i] != NULL) {
				lopSV[i]->getDS_SV().freeDS_SV(lopSV[i]->getDS_SV().getHead_DSSV());
				delete lopSV[i];
			}
		}
	}

void DSLopSV::setN(int n){
	this->n = n;
}

int DSLopSV::getN(){
	return this->n;
}

bool DSLopSV::isNull_LSV(){
	return this->n == 0;
}

bool DSLopSV::isFull_LSV(){
	return this->n == MAX_LOPSV;
}

void DSLopSV::loadData_LSV(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp;
		fileIn.open(PATH_LSV.c_str(), ios::in);
		if(fileIn.is_open()){
			string str;
			while (!fileIn.eof()){
			
				getline(fileIn, str, '\n');
				if(str=="") break;
	
				them_LSV(str);
				if (fileIn.eof()) break;
			}
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS LOP SINH VIEN";
			LIST_DATA = "DS LOP SINH VIEN";
			loadFileIsSuccess = false;
		}
			
		fileIn.close();
	}

void DSLopSV::loadDataDS_SV(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp; string tempStr;
		fileIn.open(PATH_SV.c_str(),ios::in);
		if (fileIn.is_open())
		{
			//if(DSSV.pHead==NULL)
			while (!fileIn.eof())
			{
				SinhVien data;
				
				getline(fileIn, tempStr, ',');
				if(tempStr=="") break;
				data.setMaSV(tempStr);
				getline(fileIn, tempStr, ',');
				data.setHo(tempStr);
				getline(fileIn, tempStr, ',');
				data.setTen(tempStr);
				getline(fileIn, tempStr, ',');
				data.setPhai(tempStr);
				getline(fileIn, tempStr, ',');
				data.setSDT(tempStr);
				getline(fileIn, tempStr,'\n');
				data.setMaLop(tempStr);
	
				NodeSV* SV = new NodeSV(data);
				/*int viTriThem = timviTri_SV(DSSV, SV);
				them_SV(DSSV,SV, viTriThem);*/
		
				int viTriLop = tim_LSV(SV->getData_SV().getMaLop());
				if (viTriLop != -1)	{
					this->lopSV[viTriLop]->getDS_SV().them_SV(SV);
				}
				if (fileIn.eof()) break;
				
			}
		}else { cout<<"\nKHONG TIM THAY FILE DU LIEU DS SINH VIEN"; getch();
			LIST_DATA = "DS SINH VIEN";
			loadFileIsSuccess = false;
		}
		
		fileIn.close();
	}

void DSLopSV::writeDataDS_LSV(){
		ofstream fileOut;
		fileOut.open(PATH_LSV.c_str(), ios::out);
		if (fileOut.is_open()) {
			for (int i = 0; i < this->n; i++)	{
					writeData_LSV(this->lopSV[i], fileOut);
				}
			
		}
		fileOut.close();
	}

void DSLopSV::writeDataDS_SV(){
		
		ofstream fileOut(PATH_SV.c_str(),ios::out);
		if(fileOut.is_open()){
			
			for(int i=0; i<n; i++){
				if(this->lopSV[i]->getDS_SV().isNULL_SV()!=true)
						
				for(NodeSV *p = this->lopSV[i]->getDS_SV().getHead_DSSV(); p!=NULL; p=(p->getNext_SV())){
						p->writeData_SV(p->getData_SV(),fileOut);
					}
			}
			
			
		}
		fileOut.close();
		
	}

int DSLopSV::them_LSV(string &maLopSV){
	if(isFull_LSV()) return -1;
	
	int vt=0;
	for(; vt<n ; vt++) {
		if(lopSV[vt]->getMaLop() > maLopSV) break;
		if(lopSV[vt]->getMaLop() == maLopSV ) return 2; // lop sv da ton tai
	}
	
	LopSV *LSV = new LopSV;
	LSV->setMaLop(maLopSV);
	
	for(int i=n; i>vt; i--)
		lopSV[i] = lopSV[i-1];
	
	lopSV[vt] = LSV;
	n++;
	
	return 1;
}

int DSLopSV::tim_LSV(string maLop){
	if(isNull_LSV()) return -1;
	
	for(int i=0; i<n; i++)
		if(this->lopSV[i]->getMaLop() == maLop ) return i;
	
	return -1;
}

int DSLopSV::timSV_LSV(string maSV){
		for(int i=0; i<n; i++){
			if(this->lopSV[i]->getDS_SV().tim_SV(maSV)!=-1) return i;
		}
		
		return -1;
	}

void DSLopSV::writeData_LSV(LopSV *LSV,ofstream &fileOut){
	char temp = ',';
	fileOut << LSV->getMaLop();
	fileOut<<"\n";
}

LopSV *&DSLopSV::getLopSV_LSV(int viTri){
	return this->lopSV[viTri];	
}

NodeSV * DSLopSV::layInfo_SV(string maSV){
		for(int i=0; i<n; i++){
			if(!lopSV[i]->getDS_SV().isNULL_SV()){
				for(NodeSV *p = lopSV[i]->getDS_SV().getHead_DSSV(); p!=NULL; p=p->getNext_SV() )
					if(p->getData_SV().getMaSV() == maSV)
						return p;
			}
		}
		
		return NULL;
	}

void DSLopSV::xuatDS1Trang_LSV(LopSV *lopSV[], int batDau, int ketThuc, Button *printButton[], Table newTable, Action thaoTac){
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT, soLuongSV; 
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		
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
					string((newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				
				View view("",x,yBtn, x+newTable.getCols(3)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
				view.draw();
				
				x =  tableLeft;
				continue;
			}
			
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			// xoa du lieu cu
			//setbkcolor(clyellow);
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			//setbkcolor(cllightwhite);
			outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
			x += newTable.getCols(0)->getWidth();
			
			// xoa du lieu cu
			//setbkcolor(clyellow);
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			//setbkcolor(cllightwhite);
			outtextxy(
					x + newTable.getCols(1)->getWidth()/2  - textwidth(lopSV[i]->getMaLop().c_str())/2, 
					y, 
					lopSV[i]->getMaLop().c_str()
				);
				
			x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			soLuongSV = convertIntToString(lopSV[i]->getDS_SV().demSoLuongSV());
				
			// xuat du lieu moi
			outtextxy(
					x + newTable.getCols(2)->getWidth()/2  - textwidth(soLuongSV.c_str())/2, 
					y, 
					soLuongSV.c_str()
				);
			
			x += newTable.getCols(2)->getWidth();
			
			if(thaoTac != DIEM_TB && thaoTac != DIEM_TK){
				if(printButton[i] == NULL)
					printButton[i] = new Button(
												 "Xem DSSV",
												 strSTT, 
												 x+30, 
												 yBtn+3, 
												 x+30+checkBoxButtonWidth+30,
												 yBtn-3+checkBoxButtonHeight, 
												 claqua, 
												 cllightblue, 
												 clblack
												);
				printButton[i]->draw();
			}else if(thaoTac == DIEM_TB || thaoTac == DIEM_TK){
				if(printButton[i] == NULL)
					printButton[i] = new Button(
												 "Xem Diem TB",
												 strSTT, 
												 x+20, 
												 yBtn+3, 
												 x+40+checkBoxButtonWidth+30,
												 yBtn-3+checkBoxButtonHeight, 
												 claqua, 
												 cllightblue, 
												 clblack
												);
												
				if(thaoTac == DIEM_TK) printButton[i]->setText("Xem diem TK");
				printButton[i]->draw();
			}
		
			x = tableLeft ;
		
		
		}
	}

void DSLopSV::locDS_LSV(string content, LopSV *lop[], int &nFilter, int &tongSoTrang){
		nFilter = 0;
		// chuoi khac rong
		if(!content.empty()){
			for(int i=0; i<this->n; i++){
				if(lopSV[i]->getMaLop().find(content) != string::npos)
					lop[nFilter++] = lopSV[i];
			}
			
		}else{
			for(int i=0; i<this->n; i++)
				lop[nFilter++] = lopSV[i];
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;		
	}

void DSLopSV::xuatDSTheoTrang_LSV(int &viTriChon, Action &thaoTac, Button *menuButton[]){
		int tongSoDong = n;
		int nFilter = n;
		
		LopSV *lop[n];
		for(int i=0; i<n; i++)
			lop[i] = this->lopSV[i];
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *printButton[tongSoDong] = {NULL};
		
		Table newTable = table_LSV();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ten lop hoc:" ,"N", MAX_MALOPSV, NON_SPACE, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnAdd("THEM LOP HOC","btnAdd",400, 80, 430 + buttonWidth, 120);
		if(thaoTac != DIEM_TB && thaoTac != DIEM_TK)
			btnAdd.draw();
		
		int x,y;
		
		bool exitLoop = false;
		
		while(!exitLoop){
			delay(0.000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
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
            	
            	// checked if btn is clicked xem dssv
            	for(int i=batDau; i<ketThuc; i++){
            		if(printButton[i] != NULL){
            			if(printButton[i]->isClicked(x,y) && printButton[i]->getEnable()){
            				// tim vi tri thuc(real) cua lop sinh vien neu dc filter
            				string tempMaLop = lop[i]->getMaLop();
								for(int vt = 0; vt<this->n; vt++){
									if(lopSV[vt]->getMaLop() == tempMaLop){
										viTriChon = vt; break;
									}
								}
								
	            			if(lop[viTriChon]->getDS_SV().isNULL_SV()){
	            					MessageBox(
								        NULL,
								        "LOP KHONG CO SINH VIEN NAO !!!",
								        "THONG BAO",
								        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						    		);
						    		
						    		if(thaoTac != DIEM_TB && thaoTac != DIEM_TK){
						    			int isConfirmed = MessageBox(
											        NULL,
											        "BAN CO MUON NHAP SINH VIEN CHO LOP NAY",
											        "THONG BAO",
											        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									    		);
										switch(isConfirmed){
											case IDCANCEL:{
												break;
											}
											case IDOK: default:{
												thaoTac = NHAP_DS;
												newTable.freeTable();
												freeArrButton(printButton, nFilter);
												return;
											}
										}
									}else { exitLoop = true; continue; }
						    		
							}else{
								if(thaoTac != DIEM_TB && thaoTac != DIEM_TK ) thaoTac = XUAT_DS; // xuat ds sinh vien
	            				newTable.freeTable();
								freeArrButton(printButton, nFilter);
								return;
							}
	            			
						}
					}
				}
            	
            	
            	if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            		xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				if(btnAdd.isClicked(x,y) && thaoTac != DIEM_TB && thaoTac != DIEM_TK){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = THEM;
					newTable.freeTable();
					freeArrButton(printButton, nFilter);
					return;
				}
				
        	}
        	
        	// Filter by input
			if(kbhit()){
					freeArrButton(printButton, nFilter);
					char ch = getch();
					newInput.appendText(ch);
					newInput.draw();
					locDS_LSV(newInput.getContent(), lop, nFilter, tongSoTrang);
					
					batDau = 0; trangHienTai = 1;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
					xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
			}
		}
		
		newTable.freeTable();
		freeArrButton(printButton, nFilter);
		return;
	}
	
void DSLopSV::formThem_LSV(string &maLopSV, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300);
		
		Input input("","Nhap ma lop: " ,"N", MAX_MALOPSV, NON_SPACE,  650, 200, 650 + 300, 200 + INPUT_HEIGHT);
		input.requestFocus();
		input.setContent(maLopSV);
		input.draw();
		
		Button btnThem("Them","T",650, 300, 650+buttonWidth, 300+40, claqua, cllightblue, clblack);
		btnThem.draw();
		
		Button btnHuy("Huy", "H", 850, 300, 850+buttonWidth, 300+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y;
		
		while(true){
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnThem.isClicked(x,y) && !input.getContent().empty()){
					int isConfirmed = MessageBox(
											 NULL,
											"BAN CO CHAC CHAN MUON THEM LOP SINH VIEN NAY",
											"THONG BAO",
											MB_ICONINFORMATION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									    );
									    
					switch(isConfirmed){
						case IDCANCEL:{
							break;
						}
						
						case IDOK: default:{
							maLopSV = input.getContent();
							return;
						}
					}
					
				}
			}
			
			if(kbhit()){
				char ch = getch();
				input.appendText(ch);
				input.draw();
			}
		}
	}

void DSLopSV::menu_LSV(int &viTriChon, Action &thaoTac, Button *menuButton[]){
		//int viTriChon = 0; 
		string maLopSV = "";
		string strN;
		
		if(n==0){
			
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP SINH VIEN NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
		
			if(thaoTac != DIEM_TB && thaoTac != DIEM_TK){
				int isConfirmed = MessageBox(
										NULL,
										"BAN CO MUON THEM LOP SINH VIEN",
										"THONG BAO",
										MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									);
				switch(isConfirmed){
					case IDCANCEL:{
						break;
						}
					case IDOK: default:{
						thaoTac = THEM;
						break;
					}
				}
			}else { return;
			}
			
		}
		
		while((n>0 || thaoTac == THEM ) && indexMenu == -1){ 
			strN = convertIntToString(n);
			Label title(
					"DANH SACH LOP SINH VIEN",
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
				
			title.printLabel(
						"   Tong so lop",
						strN + "     ",
						"                             "
						
					);
			
			
			switch(thaoTac){
				
				case XUAT:{
					xuatDSTheoTrang_LSV(viTriChon, thaoTac, menuButton);
					break;
				}
				
				case XUAT_DS:{
					if(viTriChon < n){
						thaoTac = XUAT;
						clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
						this->lopSV[viTriChon]->getDS_SV().menu_SV(this->lopSV[viTriChon]->getMaLop(), thaoTac, menuButton);
						
						this->writeDataDS_SV();
					}
					break;
				}
					
				case THEM:{
					
					if(n == MAX_LOPSV) {
						MessageBox(
						        NULL,
						        "DS LOP SV DA TOI DA, KHONG THE THEM !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		); thaoTac = XUAT; continue;
					}
					
					formThem_LSV(maLopSV, thaoTac);
					if(thaoTac == HUY){
						thaoTac = XUAT;
						clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
					}else if(thaoTac == THEM){						
						
						int kq = them_LSV(maLopSV);
						switch(kq){
							case -1:{ // ds lop sv da full
								MessageBox(
										NULL,
										"DANH SACH LOP SINH VIEN DA DAY !!!",
										"THONG BAO",
										MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									);
								break;
							}
								
							case 1:{ // them thanh cong
								MessageBox(
										NULL,
										"THEM LOP SINH VIEN THANH CONG !!!",
										"THONG BAO",
										MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									);
								clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
								thaoTac = XUAT;
								this->writeDataDS_LSV();
								break;
							}
								
							case 2: default:{ // lop sv da ton tai
								MessageBox(
								        NULL,
								        "LOP SINH VIEN NAY DA TON TAI !!!",
								        "THONG BAO",
								        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							   		);
								break;
							}
						}	
						
					}
					break;
				}
					
				case NHAP_DS:{
					if(viTriChon < n){
						clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
						thaoTac = THEM;
						this->lopSV[viTriChon]->getDS_SV().menu_SV(this->lopSV[viTriChon]->getMaLop(), thaoTac, menuButton);
						thaoTac = XUAT_DS;
						this->writeDataDS_SV();
					}
					break;
				}
				
				case DIEM_TB: case DIEM_TK:{
					xuatDSTheoTrang_LSV(viTriChon, thaoTac, menuButton);
					if(thaoTac == THOAT_CT){
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						viTriChon = -1;
					}
					return;
					break;
				}
				
				case THOAT_CT:{
					indexMenu =-1;
					return;
					break;
				}
				
			} // switch case 
				
		} // while 
	}
