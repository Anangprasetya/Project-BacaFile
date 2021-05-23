class Data {
	public :
		string kolom;

		Data *lanjut, *kembali;

	protected :
		Data *kepala, *ekor, *baru, *arus;
};

class Link : Data {
	public :
		Link(string n){
			this->namaFile = n;
		}

		void baca(){
			this->bacafile.open(this->namaFile);
			while(getline(bacafile, tampung)){
				cout << tampung << endl;
			}

		}

	private :
		string namaFile;
		ifstream bacafile;
		string tampung;
};