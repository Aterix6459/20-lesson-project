#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class print_job{
private:
    string fileName;
    string plastic_type;
    string startPrint;    
    int temp_soplo;
    float time_print;
    bool end_print;
    bool is_printing;

public:
    print_job(string fileName, string plastic_type, float time_print){
       this->fileName = fileName;
       this->plastic_type = plastic_type;
       this->time_print = time_print;
       is_printing = false;

       cout << "файл \"" << fileName << ".gcode\" загружен в память принтера" << endl;
       
        set_temp();
        out_data();

        start_print();
    }
    ~print_job(){
        if(is_printing == true){
            cout << "печать завершается, пожалуйста подождите";
            for(int i = 0; i < 3; i++){
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "." << flush;
            }
            cout << endl;
        }
    }

    void set_temp(){
        if(plastic_type == "PLA" || "pla")
        temp_soplo = 220;
    else if(plastic_type == "PETG" || "petg")
        temp_soplo = 250;
    else if(plastic_type == "TPU" || "tpu")
        temp_soplo = 230;
    else if(plastic_type == "ABS" || "ABS")
        temp_soplo = 260;
    else
        cout << "этот пластик ещё не доступен для печати." << endl;
    }

    void out_data(){
        cout << "название файла: " << fileName << ".gcode" << endl;
        cout << "вид пластика: " << plastic_type << endl;
        cout << "температура сопла: " << temp_soplo << "°C" << endl;
    }

    void start_print(){
        cout << "вы действительно хотите начать печать?(Y/n) ";
        cin >> startPrint;
        cout << endl;

        if(startPrint == "y") {
            cout << "начало печати";
            for(int i = 0; i < 3; i++){
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "." << flush;
            }
            cout << endl << "печать началась, время печати " << time_print << " ч." << endl;
            is_printing = true;
            this_thread::sleep_for(chrono::milliseconds(5000));
        }

        else{
            abort_print();
        }
    }

    void abort_print() {
        cout << "печать завершается, подождите";
        for(int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "." << flush;
        }
        is_printing = false;
        cout << endl << "печать завершилась." << endl;    
    }   

};


int main(){

    print_job my_gcode("inf_cube", "PLA", 1.5);

    return 0;
}