class DataBaris {
	public :
		string baris;
		DataBaris *kembali, *lanjut;
};

class DataKolom {
	public :
		string kolom;

		DataKolom *lanjut, *kembali;

	protected :
		DataKolom *kepala, *ekor, *baru, *arus;
		DataBaris *bKepala, *bEkor, *bBaru, *bArus;

		void buatKolom(string kolom){
			kepala = new DataKolom();
			kepala->kolom = kolom;
			kepala->kembali = NULL;
			kepala->lanjut = NULL;
			ekor = kepala;

		}

		void buatBaris(string baris){
			bKepala = new DataBaris();
			bKepala->baris = baris;
			bKepala->kembali = NULL;
			bKepala->lanjut = NULL;
			bEkor = bKepala;
		}

		void tambahBaris(string baris){
			if (bKepala == NULL)
				this->buatBaris(baris);
			else
			{
				bBaru = new DataBaris();
				bBaru->baris = baris;
				bBaru->kembali = bEkor;
				bBaru->lanjut = NULL;
				bEkor->lanjut = bBaru;
				bEkor = bBaru;
			}
		}

		void tambahKolom(string kolom){
			if (kepala == NULL)
				this->buatKolom(kolom);
			else{
				baru = new DataKolom();
				baru->kolom = kolom;
				baru->kembali = ekor;
				baru->lanjut = NULL;
				ekor->lanjut = baru;
				ekor = baru;
			}
		}
};

class Link : DataKolom {
	public :
		Link(string n){
			this->namaFile = n;
			kepala = NULL;
			bKepala = NULL;
			this->baca();
		}

		void baca(){
			int i = 1;
			this->bacafile.open(this->namaFile);
			while(getline(bacafile, tampung)){
				if (i == 1)
				{
					if (tampung == ";")
						i += 1;
					else{
						this->tambahKolom(tampung);
					}
				}
				else {
					this->tambahBaris(tampung);
				}
			}

		}

		void ambilKolom(){
			cout << "Kolom : ";
			arus = kepala;
			while(arus != NULL){
				cout << arus->kolom;
				if (arus->lanjut != NULL)
					cout << ", ";

				arus = arus->lanjut;
			}

			cout << endl;
		}

		void ambilBaris(){
			bArus = bKepala;
			while(bArus != NULL){
				if (bArus->baris == ";")
					cout << endl;
				else
					cout << bArus->baris;

				if (bArus->lanjut != NULL)
					cout << " ";

				bArus = bArus->lanjut;
			}
			cout << endl;
		}

	private :
		string namaFile;
		ifstream bacafile;
		string tampung;
};