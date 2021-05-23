class Data {
	public :
		string kolom;

		Data *lanjut, *kembali;

	protected :
		Data *kepala, *ekor, *baru, *arus;

		void buatKolom(string kolom){
			kepala = new Data();
			kepala->kolom = kolom;
			kepala->kembali = NULL;
			kepala->lanjut = NULL;
			ekor = kepala;

		}

		void tambahKolom(string kolom){
			if (kepala == NULL)
				this->buatKolom(kolom);
			else{
				baru = new Data();
				baru->kolom = kolom;
				baru->kembali = ekor;
				baru->lanjut = NULL;
				ekor->lanjut = baru;
				ekor = baru;
			}
		}
};

class Link : Data {
	public :
		Link(string n){
			this->namaFile = n;
			kepala = NULL;
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
					else
						this->tambahKolom(tampung);
				}
			}

		}

		void ambilKolom(){
			arus = kepala;
			while(arus != NULL){
				cout << arus->kolom;
				if (arus->lanjut != NULL)
					cout << ", ";

				arus = arus->lanjut;
			}
		}

	private :
		string namaFile;
		ifstream bacafile;
		string tampung;
};