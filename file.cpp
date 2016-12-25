#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

bool myfunction (double i,double j) { return (i<j);}

int main(){
    std::vector<double> vek;
    std::ifstream file;
    file.open("skor.txt");

    int itung = 0;
    double angka;
    while(!file.eof()){
        file >> angka;
        vek.push_back(angka);
//        std::cout << angka << std::endl;
    }

    vek.pop_back();
    std::sort(vek.begin(), vek.end());

    std::vector<double>::iterator it;

    double sesuatu[3];
    int i=0;
    for(it = vek.begin(); it!=vek.begin()+3; ++it){
        std::cout << *it << std::endl;
        sesuatu[i++] = *it;
    }
    std::cout << "---" << i << std::endl;
    while(i){
        std::cout << sesuatu[--i] << std::endl;
    }

//    file.close();
//
//    std::ofstream file2;
//    file2.open("skor.txt", std::ios_base::app | std::ios_base::out);
//    file2 << "1254.28" << std::endl;


    file.close();
}
