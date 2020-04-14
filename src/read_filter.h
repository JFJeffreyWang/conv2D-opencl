#include<fstream>
#include<iostream>
using namespace std;

int read_filter(char * filename, double *filter){
    std::ifstream infile(filename);
    //cout << filename << endl; 
    int v;
    infile >> v;
    for(int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            infile >> filter[i*v+j] ;
        }
    }
    infile.close();
    return v;
}

void print_filter(int v, double * filter){
    cout << v << endl;
    for(int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            cout << (int)filter[i*v+j] << '\t';
        }
        cout << endl;
    }
}

int read_filter_int(char * filename, int *filter){
    std::ifstream infile(filename);
    //cout << filename << endl; 
    int v;
    infile >> v;
    for(int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            infile >> filter[i*v+j] ;
        }
    }
    infile.close();
    return v;
}


// int main(int argc, char* argv[]){
//     if (argc < 1){
//         cout<<"no file"<<endl;
//     }
//     cout << argv[1] << endl;
//     double filter[100];
//     int v = read_filter(argv[1], filter);
//     cout << v << endl;
//     for(int i=0; i<v; i++){
//         for (int j=0; j<v; j++){
//             cout << (int)filter[i*v+j] << '\t';
//         }
//         cout << endl;
//     }
// }