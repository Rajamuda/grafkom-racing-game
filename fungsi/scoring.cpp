void submitScore(){
    if(!isSubmit){
        std::ofstream file;
        file.open("skor.txt", std::ios::app);

        file << duration << std::endl;

        file.close();

        isSubmit = true;
    }
}

void getScore(double arr[]){
    std::vector<double> vek;
    std::ifstream file;
//    std::vector<double> vek;

    file.open("skor.txt");
    double angka;
    while(!file.eof()){
        file >> angka;
        vek.push_back(angka);
    }

    vek.pop_back();
    std::sort(vek.begin(), vek.end());

    int i=0;
    std::vector<double>::iterator it;
    for(it = vek.begin(); it!=vek.begin()+5; ++it){
        std::cout << *it << std::endl;
        arr[i++] = *it;
    }
}
